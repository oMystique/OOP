#include "stdafx.h"
#include "../MyString/MyString.h"

using namespace std;

CMyString& CMyString::operator =(const CMyString& str)
{
	if (this != &str)
	{
		//CMyString tStr(str);
		//swap(*this, tStr);

		delete[] m_pChars;
		m_length = str.m_length + 1;
		m_pChars = new char[m_length];
		StrCpy(str.m_pChars, str.m_length);
	}

	return *this;
}

CMyString & CMyString::operator+=(const CMyString & str)
{
	char *tempStr;
	tempStr = new char[m_length + str.m_length + 1];

	for (size_t i = 0; i < m_length; i++)
	{
		tempStr[i] = m_pChars[i];
	}

	for (size_t i = m_length, j = 0;
		i <= m_length + str.m_length; i++, j++)
	{
		tempStr[i] = str.m_pChars[j];
	}

	m_length = m_length + str.m_length;

	delete m_pChars;
	m_pChars = tempStr;

	return *this;
}

CMyString operator +(CMyString const &str1, CMyString const &str2)
{
	return (CMyString(str1) += str2);
}

CMyString operator +(string const &str1, CMyString const &str2)
{
	return (CMyString(str1) += str2);
}

CMyString operator +(const char* str1, CMyString const &str2)
{
	return (CMyString(str1) += str2);
}

bool operator ==(const CMyString &str1, const CMyString &str2)
{
	return (str1.StrCmp(str2));
}

bool operator !=(const CMyString &str1, const CMyString &str2)
{
	return (!str1.StrCmp(str2));
}

bool operator <(const CMyString &str1, const CMyString &str2)
{
	return (strcmp(CMyString(str1).GetSortedAlphabeticallyChars(),
		CMyString(str2).GetSortedAlphabeticallyChars()) == -1);
}

bool operator >(const CMyString &str1, const CMyString &str2)
{
	return (strcmp(CMyString(str1).GetSortedAlphabeticallyChars(),
		CMyString(str2).GetSortedAlphabeticallyChars()) == 1);
}

bool operator <=(const CMyString &str1, const CMyString &str2)
{
	return ((str1 == str2) || (str1 < str2));
}

bool operator >=(const CMyString &str1, const CMyString &str2)
{
	return ((str1 == str2) || (str1 > str2));
}
	
const char & CMyString::operator[](size_t index)const
{
	char empty = '\0';
	return (index >= 0 && index < m_length) ? m_pChars[index] : empty;
}

char & CMyString::operator[](size_t index)
{
	char empty = '\0';
	return (index >= 0 && index < m_length) ? m_pChars[index] : empty;
}

ostream & operator <<(ostream & strm, CMyString const & string)
{
	strm << string.GetStringData();

	return strm;
}

istream & operator >>(istream & strm, CMyString & string)
{
	char tmp[2048];
	strm.getline(tmp, sizeof(tmp));
	string = CMyString(tmp);

	return strm;
}