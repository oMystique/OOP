#pragma once
#include <string>
#include <sstream>

class CMyString
{
public:
	CMyString();
	CMyString(const char *pString);
	CMyString(const char *pString, size_t length);
	CMyString(CMyString const &other);
	CMyString(CMyString &&other);
	CMyString(std::string const &stlString);
	~CMyString();

	size_t GetLength()const;
	const char* GetStringData()const;

	CMyString const SubString(size_t start, size_t length = SIZE_MAX)const;

	void Clear();
private:
	char *m_string = nullptr;
	size_t m_length = 0;
};


std::ostream & operator <<(std::ostream & strm, CMyString const & string);