#include "stdafx.h"
#include "../MyString/MyString.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

CMyString::Iterator CMyString::begin()
{
	return Iterator(m_pChars);
}

CMyString::Iterator CMyString::end()
{
	return Iterator(m_pChars + m_length);
}

CMyString::ConstIterator CMyString::begin() const
{
	return ConstIterator(m_pChars);
}

CMyString::ConstIterator CMyString::end()const
{
	return ConstIterator(m_pChars + m_length);
}

CMyString::Iterator CMyString::rbegin()
{
	return Iterator(m_pChars + m_length);
}

CMyString::Iterator CMyString::rend()
{
	return Iterator(m_pChars - 1);
}

CMyString::ConstIterator CMyString::rbegin()const
{
	return ConstIterator(end());
}

CMyString::ConstIterator CMyString::rend()const
{
	return ConstIterator(m_pChars - 1);
}

CMyString::CMyString()
	: m_length(0)
	, m_pChars(new char[1])
{
	m_pChars[0] = '\0';
}

CMyString::CMyString(const char * pString)
	: m_length(strlen(pString) + 1)
	, m_pChars(new char[m_length])
{
	StrCpy(pString);
	--m_length;
}

CMyString::CMyString(const char * pString, size_t length)
	: m_length(length + 1)
	, m_pChars(new char[m_length])
{
	StrCpy(pString);
	--m_length;
}

CMyString::CMyString(CMyString const & other)
	: m_length(other.m_length + 1)
	, m_pChars(new char[m_length])
{
	StrCpy(other.m_pChars);
	--m_length;
}

CMyString::CMyString(CMyString && other)
	: m_length(other.m_length)
	, m_pChars(other.m_pChars)
{
	other.m_pChars = nullptr;
	other.m_length = 0;
}

CMyString::CMyString(std::string const & stlString)
	: m_length(stlString.size() + 1)
	, m_pChars(new char[m_length])
{
	StrCpy(stlString.c_str());
	--m_length;
}

CMyString::~CMyString()
{
	delete[] m_pChars;
	m_pChars = nullptr;
}

size_t CMyString::GetLength() const
{
	return m_length;
}

const char * CMyString::GetStringData() const
{
	return m_pChars;
}

CMyString CMyString::SubString(size_t start, size_t length)const
{
	if (start >= m_length || start >= length)
	{
		throw out_of_range("Out of range");
	}
	else if (length > m_length)
	{
		length = m_length;
	}
	return CMyString(&m_pChars[start], length);
}

void CMyString::Clear()
{
	delete[] m_pChars;
	m_pChars = new char[1];
	m_pChars[0] = '\0';
	m_length = 0;
}


void CMyString::StrCpy(const char* str)
{
	memcpy(m_pChars, str, m_length);
	m_pChars[m_length - 1] = '\0';
}

int CMyString::StrCmp(CMyString const &str)const
{
	return (memcmp(m_pChars
		, str.GetStringData()
		, static_cast<size_t>(fmaxl(static_cast<long double>(m_length)
			, static_cast<long double>(str.GetLength())))));
}


CMyString& CMyString::operator =(CMyString &&str)
{
	swap(m_pChars, str.m_pChars);
	swap(m_length, str.m_length);

	delete[] str.m_pChars;
	str.m_pChars = nullptr;

	return *this;
}

CMyString& CMyString::operator =(const CMyString& str)
{
	if (this != &str)
	{
		CMyString tmp(str);

		swap(m_pChars, tmp.m_pChars);
		swap(m_length, tmp.m_length);
	}

	return *this;
}

CMyString & CMyString::operator +=(const CMyString & str)
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

	delete[] m_pChars;
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
	if (str1.GetLength() != str2.GetLength())
	{
		return false;
	}
	return (str1.StrCmp(str2) == 0);
}

bool operator !=(const CMyString &str1, const CMyString &str2)
{
	if (str1.GetLength() != str2.GetLength())
	{
		return true;
	}
	return (str1.StrCmp(str2) != 0);
}

bool operator <(const CMyString &str1, const CMyString &str2)
{
	return (str1.StrCmp(str2) == -1);
}

bool operator >(const CMyString &str1, const CMyString &str2)
{
	return (str1.StrCmp(str2) == 1);
}

bool operator <=(const CMyString &str1, const CMyString &str2)
{
	return ((str1 == str2) || (str1 < str2));
}

bool operator >=(const CMyString &str1, const CMyString &str2)
{
	return ((str1 == str2) || (str1 > str2));
}

const char & CMyString::operator [](size_t index)const
{
	if (index >= m_length)
	{
		throw std::out_of_range("Index out of range.");
	}
	return m_pChars[index];
}

char & CMyString::operator [](size_t index)
{
	if (index >= m_length)
	{
		throw std::out_of_range("Index out of range.");
	}
	return m_pChars[index];
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