#include "stdafx.h"
#include "HttpUrl.h"
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <math.h>
#include <boost/math/special_functions/fpclassify.hpp>

using namespace std;
using boost::string_ref;
using boost::lexical_cast;

CHttpUrl::CHttpUrl(string const & url)
{
	tie(m_protocol, m_domain, m_port, m_document) = ParseUrl(url);
}

CHttpUrl::CHttpUrl(string const & domain, string const & document
			, Protocol protocol, unsigned short port)
	: m_domain(ValidateDomainName(domain))
	, m_port(port)
	, m_document(ValidateDocument(document))
	, m_protocol(protocol)
{
	if (port == 80 && m_protocol == Protocol::HTTPS)
	{
		m_port = 443;
	}
}

string CHttpUrl::GetURL()const
{
	return ToStringProtocol() + "://" + m_domain 
		+ (((m_port == 80) || (m_port == 443)) ? "" : ":" + to_string(m_port)) 
		+ m_document;
}

string CHttpUrl::GetDomain()const
{
	return m_domain;
}

string CHttpUrl::GetDocument()const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol()const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort()const
{
	return m_port;
}

Protocol CHttpUrl::ToProtocolType(string const & scheme)
{
	if (scheme == "http")
	{
		return Protocol::HTTP;
	}
	else if (scheme == "https")
	{
		return Protocol::HTTPS;
	}

	throw invalid_argument("Invalid protocol.");
}

CHttpUrl::UrlComponents CHttpUrl::ParseUrl(string const & url)
{
	string_ref urlRef(url);

	auto scheme = ParseProtocol(urlRef);
	urlRef = urlRef.substr(scheme.size() + 3, urlRef.size() - 1);
	auto protocol = ToProtocolType(scheme);

	auto domain = ValidateDomainName(ParseDomain(urlRef));
	urlRef = urlRef.substr(domain.size(), urlRef.size() - 1);

	unsigned short port = static_cast<unsigned short>(protocol);
	if (urlRef[0] == ':')
	{
		auto portStr = ParsePort(urlRef);
		urlRef = urlRef.substr(portStr.size() + 1, urlRef.size() - 1);
		port = lexical_cast<unsigned short>(portStr);
	}

	auto document = urlRef.to_string();

	return make_tuple(protocol, ValidateDomainName(domain), port, ValidateDocument(document));
}

const string & CHttpUrl::ValidateDomainName(string const & domain)
{
	if (domain.empty())
	{
		throw invalid_argument("Domain name is empty.");
	}
	else if (find_if(domain.begin(), domain.end(), [&](char ch)
		{return (isspace(ch) || (ch == '/') || (ch == '\'')); })
		!= domain.end())
	{
		throw invalid_argument("Domain name must not contains any spaces, tabulations or slashes.");
	}

	return domain;
}

string CHttpUrl::ValidateDocument(string const & document)
{
	if (find_if(document.begin(), document.end(), [&](char ch) {
			return (isspace(ch)); 
		}) != document.end())
	{
		throw invalid_argument("Document must not contain any spaces or tabulation.");
	}

	if (document[0] != '/')
	{
		return '/' + document;
	}

	return document;
}

string CHttpUrl::ToStringProtocol()const
{
	switch(m_protocol)
	{
	case Protocol::HTTP:
		return "http";

	case Protocol::HTTPS:
		return "https";
	}

	return string();
}

string CHttpUrl::ParseDomain(string_ref &str)
{
	auto domainEnd = str.find(':');
	if (domainEnd == string_ref::npos)
	{
		domainEnd = str.find("/");
	}

	return str.substr(0, domainEnd).to_string();
}

string CHttpUrl::ParseProtocol(string_ref &str)
{
	const string schemeDelimiter = "://";
	auto schemeEnd = str.find(schemeDelimiter);

	if (schemeEnd == string_ref::npos)
	{
		throw CUrlParsingError("Protocol parsing error.");
	}

	return str.substr(0, schemeEnd).to_string();
}

string CHttpUrl::ParsePort(string_ref & str)
{
	auto portEnd = str.find('/');
	auto portStr = str.substr(1, portEnd - 1).to_string();

	return portStr.empty() ? throw CUrlParsingError("Port parsing error.") : portStr;
}
