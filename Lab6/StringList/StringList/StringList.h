#pragma once
#include <iterator>
#include <string>
#include <memory>

template <typename ValueType>
class CStringList
{
	struct Node
	{
		Node(const ValueType & data, Node * prev, std::unique_ptr<Node> && next)
			: data(data), prev(prev), next(std::move(next)), isEnd(false)
		{
		}
		Node(const ValueType & data, Node * prev, std::unique_ptr<Node> && next, bool isEnd)
			: data(data), prev(prev), next(std::move(next)), isEnd(isEnd)
		{
		}
		ValueType data;
		Node *prev;
		std::unique_ptr<Node> next;
		const bool isEnd;
	};
public:
	CStringList();
	size_t GetSize()const;
	void Append(const ValueType &data);
	void AddToFront(const ValueType &data);
	bool IsEmpty()const;
	void Clear();
	
	class CIterator : public std::iterator<std::bidirectional_iterator_tag, Node, ptrdiff_t>
	{
		friend CStringList<ValueType>;
		CIterator(Node *node, bool isReverse = false);
	public:
		friend bool const operator==(typename CStringList<ValueType>::CIterator const &it1, typename CStringList<ValueType>::CIterator const &it2)
		{
			return it1.m_node == it2.m_node;
		}
		friend bool const operator!=(typename CStringList<ValueType>::CIterator const &it1, typename CStringList<ValueType>::CIterator const &it2)
		{
			return it1.m_node != it2.m_node;
		}
		CIterator() = default;
		ValueType &operator*()const;
		CIterator &operator++();
		CIterator &operator--();
	private:
		Node *m_node = nullptr;
		bool m_isReverse = false;
	};

	CIterator begin();
	CIterator end();
	const CIterator begin()const;
	const CIterator end()const;

	CIterator Insert(CIterator &iter, ValueType const &data);
	CIterator Erase(CIterator &iter); 
	ValueType & GetBackElement();
	ValueType & GetFrontElement();
	ValueType const& GetBackElement()const;
	ValueType const& GetFrontElement()const;

	~CStringList();
private:
	size_t m_size = 0;
	std::unique_ptr<Node> m_firstNode;
	Node *m_lastNode = nullptr;
	CIterator m_end;
};

template <typename ValueType>
CStringList<ValueType>::CStringList()
	: m_end(CIterator((new Node(ValueType(), nullptr, nullptr, true))))
{
}

template <typename ValueType>
CStringList<ValueType>::~CStringList()
{
	delete m_end.m_node;
}


template <typename ValueType>
size_t CStringList<ValueType>::GetSize() const
{
	return m_size;
}

template <typename ValueType>
void CStringList<ValueType>::Append(const ValueType & data)
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
	m_end.m_node->prev = m_lastNode;
	++m_size;
}

template <typename ValueType>
void CStringList<ValueType>::AddToFront(const ValueType & data)
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
	m_end.m_node->prev = m_lastNode;
	++m_size;
}

template <typename ValueType>
bool CStringList<ValueType>::IsEmpty()const
{
	return m_size == 0;
}

template <typename ValueType>
void CStringList<ValueType>::Clear()
{
	while (m_firstNode)
	{
		auto tmp = move(m_firstNode->next);
		m_firstNode.reset();
		m_firstNode = move(tmp);
	}
	m_size = 0;
	m_lastNode = nullptr;
	m_end.m_node->prev = nullptr;
}

template <typename ValueType>
ValueType & CStringList<ValueType>::GetBackElement()
{
	if (!m_lastNode)
	{
		throw runtime_error("List is empty.");
	}

	return  m_lastNode->data;
}

template <typename ValueType>
ValueType & CStringList<ValueType>::GetFrontElement()
{
	if (!m_firstNode)
	{
		throw runtime_error("List is empty.");
	}

	return m_firstNode->data;
}

template <typename ValueType>
ValueType const & CStringList<ValueType>::GetBackElement()const
{
	if (!m_lastNode)
	{
		throw runtime_error("List is empty.");
	}

	return  m_lastNode->data;
}

template <typename ValueType>
ValueType const & CStringList<ValueType>::GetFrontElement()const
{
	if (!m_firstNode)
	{
		throw runtime_error("List is empty.");
	}

	return m_firstNode->data;
}

template <typename ValueType>
CStringList<ValueType>::CIterator::CIterator(Node * node, bool isReverse)
	: m_node(node)
	, m_isReverse(isReverse)
{
}

template <typename ValueType>
ValueType & CStringList<ValueType>::CIterator::operator*()const
{
	if (!m_node || (m_node->isEnd))
	{
		throw std::runtime_error("Iterator as invalid.");
	}

	return m_node->data;
}

template <typename ValueType>
typename CStringList<ValueType>::CIterator & CStringList<ValueType>::CIterator::operator++()
{
	if (!m_node->next || !m_node)
	{
		throw (std::runtime_error("Iterator has not icrementable."));
	}
	m_node = m_node->next.get();

	return *this;
}

template <typename ValueType>
typename CStringList<ValueType>::CIterator & CStringList<ValueType>::CIterator::operator--()
{
	m_node = m_node->prev;

	return *this;
}

template <typename ValueType>
typename CStringList<ValueType>::CIterator CStringList<ValueType>::begin()
{
	return CIterator(m_firstNode.get());
}

template <typename ValueType>
typename CStringList<ValueType>::CIterator CStringList<ValueType>::end()
{
	return m_end;
}

template <typename ValueType>
typename const CStringList<ValueType>::CIterator CStringList<ValueType>::begin()const
{
	return CIterator(m_firstNode.get());
}

template <typename ValueType>
typename const CStringList<ValueType>::CIterator CStringList<ValueType>::end()const
{
	return m_end;
}

template <typename ValueType>
typename CStringList<ValueType>::CIterator CStringList<ValueType>::Insert(CIterator &iter, ValueType const &data)
{
	auto iterNode = iter.m_node;
	if (iterNode == m_firstNode.get() && iter.m_node != m_end.m_node)
	{
		AddToFront(data);
	}
	else if ((iterNode == m_lastNode) || (iterNode == m_end.m_node))
	{
		Append(data);
	}
	else
	{
		if (!iterNode)
		{
			throw invalid_argument("Iterator is not valid.");
		}
		auto newNode = make_unique<Node>(data, move(iterNode->prev)
			, move(make_unique<Node>(iterNode->data, nullptr, move(iterNode->next))));
		newNode->next->prev = newNode.get();
		iter.m_node = newNode->next.get();
		newNode->prev->next = move(newNode);
		++m_size;
	}
	return iter;
}

template <typename ValueType>
typename CStringList<ValueType>::CIterator CStringList<ValueType>::Erase(CIterator & iter)
{
	if (!iter.m_node || iter.m_node->isEnd)
	{
		throw runtime_error("Dont erase it, because iter is null.");
	}
	if (iter.m_node == m_firstNode.get())
	{
		if (m_firstNode->next)
		{
			m_firstNode = move(m_firstNode->next);
			m_firstNode->prev = nullptr;
			iter = m_firstNode.get();
		}
		else
		{
			m_firstNode = nullptr;
			m_lastNode = nullptr;
			m_end.m_node->prev = nullptr;
		}
	}
	else if (iter.m_node == m_lastNode)
	{
		m_lastNode = m_lastNode->prev;
		m_lastNode->next = nullptr;
		m_end.m_node->prev = m_lastNode;
		iter = m_lastNode->next.get();
	}
	else
	{
		auto next = move(iter.m_node->next);
		auto prev = iter.m_node->prev;
		next->prev = prev;
		prev->next = move(next);
		iter = prev->next.get();
	}
	--m_size;

	return iter;
}