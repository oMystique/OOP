#include "stdafx.h"
#include "StringList.h"
#include <cassert>
#include <iostream>

using namespace std;

//template <typename ValueType>
//CStringList<ValueType>::CStringList()
//	//: m_end(CIterator((new Node(ValueType(), nullptr, nullptr, true))))
//{
//}

//template <typename ValueType>
//CStringList<ValueType>::~CStringList()
//{
//	delete m_end.m_node;
//}
//
//template <typename ValueType>
//size_t CStringList<ValueType>::GetSize() const
//{
//	return m_size;
//}
//
//template <typename ValueType>
//void CStringList<ValueType>::Append(const ValueType & data)
//{
//	auto newNode = make_unique<Node>(data, m_lastNode, nullptr);
//	Node *newLastNode = newNode.get();
//	if (m_lastNode)
//	{
//		m_lastNode->next = move(newNode);
//	}
//	else 
//	{
//		m_firstNode = move(newNode);
//	}
//	m_lastNode = newLastNode;
//	m_end.m_node->prev = m_lastNode;
//	++m_size;
//}
//
//template <typename ValueType>
//void CStringList<ValueType>::AddToFront(const ValueType & data)
//{
//	auto newNode = make_unique<Node>(data, nullptr, nullptr);
//	if (m_firstNode)
//	{
//		m_firstNode->prev = newNode.get();
//		newNode->next = move(m_firstNode);
//	}
//	else
//	{
//		m_lastNode = newNode.get();
//	}
//	m_firstNode = move(newNode);
//	m_end.m_node->prev = m_lastNode;
//	++m_size;
//}
//
//template <typename ValueType>
//bool CStringList<ValueType>::IsEmpty()const
//{
//	return m_size == 0;
//}
//
//template <typename ValueType>
//void CStringList<ValueType>::Clear()
//{
//	while (m_firstNode) 
//	{
//		auto tmp = move(m_firstNode->next);
//		m_firstNode.reset(); 
//		m_firstNode = move(tmp);
//	}
//	m_size = 0;
//	m_lastNode = nullptr;
//	m_end.m_node->prev = nullptr;
//}

//template <typename ValueType>
//CStringList<ValueType>::CIterator CStringList<ValueType>::begin()
//{
//	return CIterator(m_firstNode.get());
//}
//
//template <typename ValueType>
//CStringList<ValueType>::CIterator CStringList<ValueType>::end()
//{
//	return m_end;
//}
//
//template <typename ValueType>
//CStringList<ValueType>::CIterator CStringList<ValueType>::Insert(CIterator &iter, ValueType const &data)
//{
//	auto iterNode = iter.m_node;
//	if (iterNode == m_firstNode.get() && iter.m_node != m_end.m_node)
//	{
//		AddToFront(data);
//	}
//	else if ((iterNode == m_lastNode) || (iterNode == m_end.m_node))
//	{
//		Append(data);
//	}
//	else
//	{
//		if (!iterNode)
//		{
//			throw invalid_argument("Iterator is not valid.");
//		}
//		auto newNode = make_unique<Node>(data, move(iterNode->prev)
//			, move(make_unique<Node>(iterNode->data, nullptr, move(iterNode->next))));
//		newNode->next->prev = newNode.get();
//		iter.m_node = newNode->next.get();
//		newNode->prev->next = move(newNode);
//		++m_size;
//	}
//	return iter;
//}
//
//template <typename ValueType>
//CStringList<ValueType>::CIterator CStringList<ValueType>::Erase(CIterator & iter)
//{
//	if (!iter.m_node || iter.m_node->isEnd)
//	{
//		throw runtime_error("Dont erase it, because iter is null.");
//	}
//	if (iter.m_node == m_firstNode.get())
//	{
//		m_firstNode = move(m_firstNode->next);
//		m_firstNode->prev = nullptr;
//		iter = m_firstNode.get();
//	}
//	else if (iter.m_node == m_lastNode)
//	{
//		m_lastNode = m_lastNode->prev;
//		m_lastNode->next = nullptr;
//		m_end.m_node->prev = m_lastNode;
//		iter = m_lastNode->next.get();
//	}
//	else
//	{
//
//	}
//
//	--m_size;
//	return iter;
//}
//
//template <typename ValueType>
//ValueType & CStringList<ValueType>::GetBackElement()
//{
//	if (!m_lastNode)
//	{
//		throw runtime_error("List is empty.");
//	}
//
//	return  m_lastNode->data;
//}
//
//template <typename ValueType>
//ValueType & CStringList<ValueType>::GetFrontElement()
//{
//	if (!m_firstNode)
//	{
//		throw runtime_error("List is empty.");
//	}
//
//	return m_firstNode->data;
//}
//
//template <typename ValueType>
//ValueType const & CStringList<ValueType>::GetBackElement()const
//{
//	if (!m_lastNode)
//	{
//		throw runtime_error("List is empty.");
//	}
//
//	return  m_lastNode->data;
//}
//
//template <typename ValueType>
//ValueType const & CStringList<ValueType>::GetFrontElement()const
//{
//	if (!m_firstNode)
//	{
//		throw runtime_error("List is empty.");
//	}
//
//	return m_firstNode->data;
//}

//template <typename ValueType>
//CStringList<ValueType>::CIterator::CIterator(Node * node, bool isReverse)
//	: m_node(node)
//	, m_isReverse(isReverse)
//{
//}
//
//template <typename ValueType>
//ValueType & CStringList<ValueType>::CIterator::operator*()const
//{
//	if (!m_node || (m_node->isEnd))
//	{
//		throw std::runtime_error("Iterator as invalid.");
//	}
//
//	return m_node->data;
//}
