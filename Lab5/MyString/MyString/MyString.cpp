#include "stdafx.h"
#include "../MyString/MyString.h"
#include <iostream>
#include <stdlib.h>

CMyString::Iterator CMyString::begin()
{
	return Iterator(&m_pChars[0]);
}

CMyString::Iterator CMyString::end()
{
	return Iterator(&m_pChars[m_length]);
}

CMyString::ConstIterator CMyString::begin() const
{
	return ConstIterator(&m_pChars[0]);
}

CMyString::ConstIterator CMyString::end()const
{
	return ConstIterator(&m_pChars[m_length]);
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
	if (m_length > 0 && start < m_length && length <= m_length && start < length)
	{
		return CMyString(&m_pChars[start], length);
	}
	return CMyString();
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
		, static_cast<size_t>(fmaxl(m_length, str.GetLength()))));
}