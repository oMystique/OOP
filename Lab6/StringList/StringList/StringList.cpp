#include "stdafx.h"
#include "StringList.h"
#include <cassert>
#include <iostream>

using namespace std;

size_t CStringList::GetSize() const
{
	return m_size;
}

void CStringList::Append(const string & data)
{
	auto newNode = make_unique<Node>(data, m_lastNode, nullptr);
	Node *newLastNode = newNode.get();
	if (m_lastNode)
	{
		m_lastNode->next = move(newNode);
	}
	else 
	{
		m_firstNode = move(newNode);
	}
	m_lastNode = newLastNode;
	++m_size;
}

void CStringList::AddToFront(const string & data)
{
	auto newNode = make_unique<Node>(data, nullptr, nullptr);
	if (m_firstNode)
	{
		m_firstNode->prev = newNode.get();
		newNode->next = move(m_firstNode);
	}
	else
	{
		m_lastNode = newNode.get();
	}
	m_firstNode = move(newNode);
	++m_size;
}

bool CStringList::IsEmpty() const
{
	return m_size == 0;
}

void CStringList::Clear()
{
	while (m_firstNode) 
	{
		auto tmp = move(m_firstNode->next);
		m_firstNode.reset(); 
		m_firstNode = move(tmp); 
	}
	m_size = 0;
	m_lastNode = nullptr;
}

CStringList::CIterator CStringList::begin()
{
	return CIterator(m_firstNode.get());
}

CStringList::CIterator CStringList::end()
{
	return CIterator(m_lastNode->next.get());
}

void CStringList::Insert(CIterator &iter, string const &data)
{
	if (!iter.m_node)
	{
		throw invalid_argument("Iterator is not valid.");
	}
	auto iterNode = iter.m_node;
	if (iterNode == m_firstNode.get())
	{
		AddToFront(data);
	}
	else if (iterNode == m_lastNode)
	{
		Append(data);
	}
	else
	{
		auto newNode = make_unique<Node>(data, nullptr, nullptr);
		auto prevIterNode = iterNode->prev;
		iterNode->prev = newNode.get();
		prevIterNode->next = move(newNode);
		prevIterNode->next->prev = prevIterNode;
		prevIterNode->next->next.reset(iterNode);
	}
	++m_size;
}

string & CStringList::GetBackElement()
{
	if (!m_lastNode)
	{
		throw runtime_error("List is empty.");
	}

	return  m_lastNode->data;
}

string & CStringList::GetFrontElement()
{
	if (!m_firstNode)
	{
		throw runtime_error("List is empty.");
	}

	return m_firstNode->data;
}

string const & CStringList::GetBackElement()const
{
	if (!m_lastNode)
	{
		throw runtime_error("List is empty.");
	}

	return  m_lastNode->data;
}

string const & CStringList::GetFrontElement()const
{
	if (!m_firstNode)
	{
		throw runtime_error("List is empty.");
	}

	return m_firstNode->data;
}

CStringList::CIterator::CIterator(Node * node, bool isReverse)
	: m_node(node)
	, m_isReverse(isReverse)
{
}

std::string & CStringList::CIterator::operator*()const
{
	return m_node->data;
}
