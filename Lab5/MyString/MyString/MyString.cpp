#include "stdafx.h"
#include "../MyString/MyString.h"
#include <iostream>
#include <stdlib.h>

CMyString::CMyString()
	: m_length(0)
	, m_pChars(new char[1])
{
	m_pChars[0] = '\0';
}

CMyString::CMyString(const char * pString)
	: m_length(strlen(pString))
	, m_pChars(new char[m_length + 1])
{
	memcpy(m_pChars, pString, m_length + 1);
}

CMyString::CMyString(const char * pString, size_t length)
	: m_length(length + 1)
	, m_pChars(new char[m_length])
{
	if (m_length != 1)
	{
		StrCpy(pString, length);
	}
}

CMyString::CMyString(CMyString const & other)
	: m_length(other.m_length + 1)
	, m_pChars(new char[m_length])
{
	if (m_length != 1)
	{
		StrCpy(other.m_pChars, other.m_length);
	}
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
	StrCpy(stlString.c_str(), stlString.size());
}

CMyString::~CMyString()
{
	delete m_pChars;
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

CMyString const CMyString::SubString(size_t start, size_t length)const
{
	if (m_length > 0 && start < m_length && length <= m_length && start < length)
	{
		return CMyString(&m_pChars[start], length);
	}
	return CMyString();
}

void CMyString::Clear()
{
	delete m_pChars;
	m_pChars = nullptr;
	m_length = 0;
}


void CMyString::StrCpy(const char* str, size_t length)
{
	strncpy_s(m_pChars, m_length, str, length);
	--m_length;
}

bool CMyString::StrCmp(CMyString const &str)const
{
	if (m_length != str.m_length)
	{
		return false;
	}

	size_t i = 0;
	for (; m_pChars[i] == str.m_pChars[i] && i < str.m_length; ++i);

	return (i == m_length);
}


const char* CMyString::GetSortedAlphabeticallyChars()
{
	auto str = CMyString(*this);
	
	qsort(str.m_pChars, str.m_length, sizeof(char), (int(*)(const void *, const  void *)) strcmp);

	return str.m_pChars;
}