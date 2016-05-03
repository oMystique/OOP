#include "stdafx.h"
#include "UrlParsingError.h"

CUrlParsingError::CUrlParsingError(std::string const & msg) 
	: std::invalid_argument(msg)
{
};
