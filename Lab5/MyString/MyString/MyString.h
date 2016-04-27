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
	CMyString SubString(size_t start, size_t length = SIZE_MAX)const;
	void Clear();

	int StrCmp(CMyString const &str)const;

//operators
	CMyString& operator =(const CMyString& str);
	CMyString& operator +=(const CMyString& str);
	const char &operator[](size_t index) const;
	char &operator[](size_t index);
private:
	void StrCpy(const char* str);

private:
	size_t m_length;
	char *m_pChars;
};


CMyString SortByAlphabet(CMyString const &str);

//operators
CMyString operator +(CMyString const &str1, CMyString const &str2);
CMyString operator +(std::string const &str1, CMyString const &str2);
CMyString operator +(const char* str1, CMyString const &str2);

bool operator ==(const CMyString &str1, const CMyString &str2);
bool operator !=(const CMyString &str1, const CMyString &str2);
bool operator <(const CMyString &str1, const CMyString &str2);
bool operator >(const CMyString &str1, const CMyString &str2);
bool operator <=(const CMyString &str1, const CMyString &str2);
bool operator >=(const CMyString &str1, const CMyString &str2);

std::ostream & operator <<(std::ostream & strm, CMyString const & string);
std::istream & operator >>(std::istream & strm, CMyString & string);