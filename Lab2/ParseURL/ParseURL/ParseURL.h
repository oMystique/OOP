#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <boost/regex.hpp>

enum class Protocol
{
	HTTP = 80,
	HTTPS = 443,
	FTP = 21
};

bool ParseURL(std::string const &url, Protocol &protocol, int &port, std::string &host, std::string &document);