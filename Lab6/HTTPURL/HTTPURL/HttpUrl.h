#pragma once
#include "UrlParsingError.h"
#include <tuple>
#include <boost/utility/string_ref.hpp>

class CHttpUrl
{
	using UrlContains = std::tuple<Protocol, std::string, std::string>;
public:
	CHttpUrl(std::string const &url);
	CHttpUrl(
		std::string const&domain,
		std::string const&document,
		Protocol protocol = Protocol::HTTP,
		unsigned short port = 80);

	std::string GetURL()const;
	std::string GetDomain()const;
	std::string GetDocument()const;
	Protocol GetProtocol()const;
	unsigned short GetPort()const;

	std::string ToStringProtocol()const;
	Protocol ToProtocolType(std::string const &scheme)const;
private:
	std::string ValidateDomainName(std::string const &domain)const;
	std::string ValidateDocument(std::string const &document)const;
	std::string ParseDomain(boost::string_ref &str)const;
	std::string ParseProtocol(boost::string_ref &str)const;
	UrlContains ParseUrl(std::string const &url)const;
private:
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
};
