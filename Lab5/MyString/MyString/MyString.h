#pragma once
#include <string>
#include <sstream>
#include <cassert>
#include "MyStringIterator.h"

class CMyString
{
public:
	using Iterator = MyStrIterator<char>;
	using ConstIterator = MyStrIterator<const char>;

	Iterator begin();
	Iterator end();
	ConstIterator begin()const;
	ConstIterator end()const;

	Iterator rbegin();
	Iterator rend();
	ConstIterator rbegin()const;
	ConstIterator rend()const;

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
	CMyString& operator =(CMyString &&str);
	CMyString& operator +=(const CMyString& str);
	const char &operator [](size_t index) const;
	char &operator [](size_t index);
private:
	CMyString(size_t length);
	void StrCpy(const char* str);

private:
	const static char *m_nullTerminated;
	size_t m_length;
	char *m_pChars;
};

//operators
CMyString operator +(CMyString str1, CMyString const &str2);

bool operator ==(const CMyString &str1, const CMyString &str2);
bool operator !=(const CMyString &str1, const CMyString &str2);
bool operator <(const CMyString &str1, const CMyString &str2);
bool operator >(const CMyString &str1, const CMyString &str2);
bool operator <=(const CMyString &str1, const CMyString &str2);
bool operator >=(const CMyString &str1, const CMyString &str2);

std::ostream &operator <<(std::ostream & strm, CMyString const &string);
std::istream &operator >>(std::istream & strm, CMyString &string);