#include "stdafx.h"
#include "../MyString/MyString.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>

const char* CMyString::m_nullTerminated = "\0";

using namespace std;

CMyString::CMyString(size_t length)
	: m_length(length)
	, m_pChars(new char[m_length + 1])
{
}

CMyString::CMyString()
	: m_length(0)
	, m_pChars(nullptr)
{
}

CMyString::CMyString(const char * pString)
	: m_length(strlen(pString))
	, m_pChars(new char[m_length + 1])
{
	StrCpy(pString);
}

CMyString::CMyString(const char * pString, size_t length)
	: m_length(length)
	, m_pChars(new char[m_length + 1])
{
	StrCpy(pString);
}

CMyString::CMyString(CMyString const & other)
	: m_length(other.m_length)
	, m_pChars(new char[m_length + 1])
{
	StrCpy(other.m_pChars);
}

CMyString::CMyString(CMyString && other)
	: m_length(other.m_length)
	, m_pChars(other.m_pChars)
{
	other.m_pChars = nullptr;
	other.m_length = 0;
}

CMyString::CMyString(string const & stlString)
	: m_length(stlString.size())
	, m_pChars(new char[m_length + 1])
{
	StrCpy(stlString.c_str());
}

CMyString::~CMyString()
{
	delete[] m_pChars;
}

size_t CMyString::GetLength() const
{
	return m_length;
}

const char * CMyString::GetStringData() const
{
	if (!m_pChars)
	{
		return m_nullTerminated;
	}
	return m_pChars;
}

CMyString CMyString::SubString(size_t start, size_t length)const
{
	if (start >= m_length || start > length)
	{
		throw out_of_range("Out of range");
	}
	else if ((!m_pChars) || (start == length))
	{
		return m_nullTerminated;
	}
	else if (length > m_length)
	{
		length = m_length;
	}
	return CMyString(&m_pChars[start], length);
}

void CMyString::Clear()
{
	m_length = 0;
	if (m_pChars)
	{
		delete[] m_pChars;
		m_pChars = nullptr;
	}
}


void CMyString::StrCpy(const char* str)
{
	memcpy(m_pChars, str, m_length);
	m_pChars[m_length] = '\0';
}

int CMyString::StrCmp(CMyString const &str)const
{
	auto cmp = (memcmp(m_pChars, str.GetStringData(), min(m_length, str.m_length)));
	return cmp != 0 ? cmp : static_cast<int>(m_length - str.m_length);
}


CMyString& CMyString::operator =(CMyString &&str)
{
	if (this != &str)
	{
		swap(m_pChars, str.m_pChars);
		swap(m_length, str.m_length);

		delete[] str.m_pChars;
		str.m_pChars = nullptr;
	}

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
	if (str.m_pChars)
	{
		char *tempStr = new char[m_length + str.m_length + 1];

		memcpy(tempStr, m_pChars, m_length);
		memcpy(&tempStr[m_length], str.m_pChars, str.m_length);

		m_length = m_length + str.m_length;

		delete[] m_pChars;
		m_pChars = tempStr;
	}

	return *this;
}

CMyString operator +(CMyString str1, CMyString const &str2) 
{
	return str1 += str2;
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
	return !(str1 == str2);
}

bool operator <(const CMyString &str1, const CMyString &str2)
{
	return (str1.StrCmp(str2) < 0);
}

bool operator >(const CMyString &str1, const CMyString &str2)
{
	return (str1.StrCmp(str2) > 0);
}

bool operator <=(const CMyString &str1, const CMyString &str2) 
{
	return (str1.StrCmp(str2) <= 0);
}

bool operator >=(const CMyString &str1, const CMyString &str2)
{
	return (str1.StrCmp(str2) >= 0);
}

const char & CMyString::operator [](size_t index)const
{
	if (index > m_length)
	{
		throw out_of_range("Index out of range.");
	}

	return GetStringData()[index];
}

char & CMyString::operator [](size_t index)
{
	if (index >= m_length && index != 0)
	{
		throw out_of_range("Index out of range.");
	}
	else if (!m_pChars)
	{
		m_pChars = new char[2];
		m_pChars[1] = '\0';
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
	std::string tStr;
	strm >> tStr;
	string = CMyString(tStr);

	return strm;
}

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
	return Iterator(m_pChars + m_length - 1, true);
}

CMyString::Iterator CMyString::rend()
{
	return Iterator(m_pChars - 1, true);
}

CMyString::ConstIterator CMyString::rbegin()const
{
	return ConstIterator(m_pChars + m_length - 1, true);
}

CMyString::ConstIterator CMyString::rend()const
{
	return ConstIterator(m_pChars - 1, true);
}
