#pragma once
#include <map>
//#include <boost/algorithm/string/case_conv.hpp>

static const double VAL_NOT_EXISTING = -INFINITY;

struct FunctionParamethers
{
	std::string value1 = "";
	std::string operand = "";
	std::string value2 = "";
};

struct StrLess : public std::binary_function<std::string, std::string, bool>
{
	bool const operator () (const std::string &str1, const std::string &str2) { return _stricoll(str1.c_str(), str2.c_str()) < 0; }
};

typedef std::map<std::string, double, StrLess> VarsArray;
typedef std::map<std::string, FunctionParamethers, StrLess> FunctionsArray;