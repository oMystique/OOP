#include "stdafx.h"
#include "../MyString/MyString.h"


CMyString::CMyString()
{
}

CMyString::CMyString(const char * pString)
	: m_length(strlen(pString) + 1)
	, m_string(new char[m_length])
{
	strcpy_s(m_string, m_length, pString);
}

CMyString::CMyString(const char * pString, size_t length)
{
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

CMyString const CMyString::SubString(size_t start, size_t length) const
{
	return nullptr;
}

void CMyString::Clear()
{
	delete m_string;
}
