#include "stdafx.h"
#include "../MyString/MyString.h"
#include <iostream>

CMyString::CMyString()
	: m_string(nullptr)
{
}

CMyString::CMyString(const char * pString)
	: m_length(strlen(pString) + 1)
	, m_string(new char[m_length])
{
	strcpy_s(m_string, m_length, pString);
	if (m_string[m_length - 2] != '\0')
	{
		m_string[m_length - 1] = '\0';
	}
}

CMyString::CMyString(const char * pString, size_t length)
	: m_length(length + 1)
	, m_string(new char[m_length])
{
	strncpy_s(m_string, m_length, pString, length);
}

CMyString::CMyString(CMyString const & other)
{
}

CMyString::CMyString(CMyString && other)
{
}

CMyString::CMyString(std::string const & stlString)
{
}

CMyString::~CMyString()
{
	delete m_string;
}

size_t CMyString::GetLength() const
{
	return m_length;
}

const char * CMyString::GetStringData() const
{
	return m_string;
}

CMyString const CMyString::SubString(size_t start, size_t length)const
{
	if (m_length > 0 && start < m_length && length <= m_length && start < length)
	{
		return CMyString(&m_string[start], length);
	}
	return CMyString();
}

void CMyString::Clear()
{
	delete m_string;
	m_string = nullptr;
	m_length = 0;
}
