#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <boost/regex.hpp>

enum class Protocol
{
	HTTP,
	HTTPS,
	FTP
};

bool ParseURL(std::string const &url, Protocol &protocol, int &port, std::string &host, std::string &document);