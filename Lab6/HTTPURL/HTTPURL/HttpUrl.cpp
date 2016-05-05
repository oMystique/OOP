#include "stdafx.h"
#include "HttpUrl.h"
#include <boost/utility/string_ref.hpp>

using namespace std;
using boost::string_ref;

CHttpUrl::CHttpUrl(string const & url)
{
	tie(m_protocol, m_domain, m_document) = ParseUrl(url);
}

CHttpUrl::CHttpUrl(string const & domain, string const & document
			, Protocol protocol, unsigned short /*port*/)
	: m_domain(ValidateDomainName(domain))
	, m_document(ValidateDocument(document))
	, m_protocol(protocol)
{
}

string CHttpUrl::GetURL()const
{
	return ToStringProtocol() + "://" + m_domain + m_document;
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

unsigned short CHttpUrl::GetPort() const
{
	return static_cast<unsigned short>(m_protocol);
}

Protocol CHttpUrl::ToProtocolType(string const & scheme)const
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

CHttpUrl::UrlContains CHttpUrl::ParseUrl(string const & url)const
{
	string_ref urlRef(url);

	auto scheme = ParseProtocol(urlRef);
	urlRef = urlRef.substr(scheme.size() + 3, urlRef.size() - 1);

	auto domain = ValidateDomainName(ParseDomain(urlRef));
	urlRef = urlRef.substr(domain.size(), urlRef.size() - 1);

	auto document = urlRef.to_string();
	
	return make_tuple(ToProtocolType(scheme), ValidateDomainName(domain), ValidateDocument(document));
}

string CHttpUrl::ValidateDomainName(string const & domain)const
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

string CHttpUrl::ValidateDocument(string const & document) const
{
	if (find_if(document.begin(), document.end(), [&](char ch)
		{return (isspace(ch)); }) 
		!= document.end())
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

string CHttpUrl::ParseDomain(boost::string_ref & str)const
{
	auto domainEnd = str.find('/');

	return str.substr(0, domainEnd).to_string();
}

string CHttpUrl::ParseProtocol(boost::string_ref & str)const
{
	const string schemeDelimiter = "://";
	auto schemeEnd = str.find(schemeDelimiter);

	if (schemeEnd == string_ref::npos)
	{
		throw CUrlParsingError("Protocol parsing error.");
	}

	return str.substr(0, schemeEnd).to_string();
}
