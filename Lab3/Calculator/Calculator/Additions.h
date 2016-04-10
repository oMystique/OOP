#pragma once
#include <map>
#include <boost\signals2.hpp>
#include <memory>
#include <boost/optional.hpp>

struct StrComparison : public std::binary_function<std::string, std::string, bool>
{
	inline bool const operator () (const std::string &str1, const std::string &str2) 
	{ 
		return _stricoll(str1.c_str(), str2.c_str()) < 0;
	}
};

class CFunction;
class CVar;

typedef std::map<std::string, std::shared_ptr<CVar>, StrComparison> Vars;
typedef std::map<std::string, std::shared_ptr<CFunction>, StrComparison> Functions;