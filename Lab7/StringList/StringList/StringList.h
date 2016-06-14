#pragma once
#include <iterator>
#include <string>
#include <memory>
#include <functional>

template <typename ValueType>
class CMyList
{
	friend class CIterator;
	struct Node
	{
		Node(const ValueType & data, Node * prev, std::unique_ptr<Node> && next)
			: data(data), prev(prev), next(std::move(next))
		{
		}
		ValueType data;
		Node *prev;
		std::unique_ptr<Node> next;
	};

	template <typename T = ValueType>
	class CIterator : public std::iterator<std::bidirectional_iterator_tag, Node, ptrdiff_t>
	{
		friend CMyList;
		CIterator(Node *node, CMyList * list, bool isReverse = false)
			: m_node(node)
			, m_list(list)
			, m_isReverse(isReverse)

		{
		};
	public:
		friend bool const operator==(typename CMyList<ValueType>::CIterator<T> const &it1
			, typename CMyList<ValueType>::CIterator<T> const &it2)
		{
			return it1.m_node == it2.m_node;
		}
		friend bool const operator!=(typename CMyList<ValueType>::CIterator<T> const &it1
			, typename CMyList<ValueType>::CIterator<T> const &it2)
		{
			return !(it1 == it2);
		}
		CIterator() = default;
		T &operator*()const;
		T *operator->()const;
		CIterator &operator++();
		CIterator &operator--();
	private:
		Node *m_node = nullptr;
		bool m_isReverse = false;
		CMyList * m_list = nullptr;

	};
public:
	CMyList();
	size_t GetSize()const;
	void Append(const ValueType &data);
	void AddToFront(const ValueType &data);
	bool IsEmpty()const;
	void Clear();
	
	using iterator = CIterator<ValueType>;
	using const_iterator = CIterator<const ValueType>;

	CMyList & operator=(CMyList const &other);
	CMyList & operator=(CMyList && other);

	iterator begin();
	iterator end();
	const_iterator cbegin()const;
	const_iterator cend()const;

	iterator rbegin();
	iterator rend();
	const_iterator crbegin()const;
	const_iterator crend()const;

	template <typename T>
	CIterator<T> Insert(CIterator<T> iter, ValueType const &data);
	template <typename T>
	CIterator<T> Erase(CIterator<T> iter);

	ValueType & GetBackElement();
	ValueType & GetFrontElement();
	ValueType const& GetBackElement()const;
	ValueType const& GetFrontElement()const;

	~CMyList();
private:
	size_t m_size = 0;
	std::unique_ptr<Node> m_firstNode;
	Node *m_lastNode;
};

template <typename ValueType>
CMyList<ValueType>::CMyList()
{
}

template <typename ValueType>
CMyList<ValueType>::~CMyList()
{
	while (m_firstNode)
	{
		auto tmp = move(m_firstNode->next);
		m_firstNode.reset();
		m_firstNode = move(tmp);
	}
}

template <typename ValueType>
size_t CMyList<ValueType>::GetSize()const
{
	return m_size;
}

template <typename ValueType>
void CMyList<ValueType>::Append(const ValueType & data)
{
	auto newNode = make_unique<Node>(data, m_lastNode, nullptr);
	Node *newLastNode = newNode.get();
	if (m_size != 0)
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

template <typename ValueType>
void CMyList<ValueType>::AddToFront(const ValueType & data)
{
	std::unique_ptr<Node> newNode = make_unique<Node>(data, nullptr, nullptr);
	if (m_size != 0)
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

template <typename ValueType>
bool CMyList<ValueType>::IsEmpty()const
{
	return m_size == 0;
}

template <typename ValueType>
void CMyList<ValueType>::Clear()
{
	while (m_firstNode)
	{
		auto tmp = move(m_firstNode->next);
		m_firstNode.reset();
		m_firstNode = move(tmp);
	}
	m_size = 0;
}

template <typename ValueType>
ValueType & CMyList<ValueType>::GetBackElement()
{
	if (IsEmpty())
	{
		throw runtime_error("List is empty.");
	}

	return  m_lastNode->data;
}

template <typename ValueType>
ValueType & CMyList<ValueType>::GetFrontElement()
{
	if (IsEmpty())
	{
		throw runtime_error("List is empty.");
	}

	return m_firstNode->data;
}

template <typename ValueType>
ValueType const & CMyList<ValueType>::GetBackElement()const
{
	if (IsEmpty())
	{
		throw runtime_error("List is empty.");
	}

	return  m_lastNode->data;
}

template <typename ValueType>
ValueType const & CMyList<ValueType>::GetFrontElement()const
{
	if (IsEmpty())
	{
		throw runtime_error("List is empty.");
	}

	return m_firstNode->data;
}

template<typename ValueType>
CMyList<ValueType> & CMyList<ValueType>::operator=(CMyList && other)
{
	std::swap(m_firstNode, other.m_firstNode);
	std::swap(m_lastNode, other.m_lastNode);
	m_size = other.m_size;
	other.Clear();

	return *this;
}

template<typename ValueType>
CMyList<ValueType> & CMyList<ValueType>::operator=(CMyList const & other)
{
	CMyList<ValueType> lst;
	auto tmp = other.m_firstNode.get();
	while (tmp)
	{
		lst.Append(tmp->data);
		tmp = tmp->next.get();
	}

	Clear();
	std::swap(m_firstNode, lst.m_firstNode);
	std::swap(m_lastNode, lst.m_lastNode);
	m_size = other.m_size;

	return *this;
}

template <typename ValueType>
template <typename T>
T & CMyList<ValueType>::CIterator<T>::operator*()const
{
	if (!m_node)
	{
		throw std::runtime_error("Iterator as invalid.");
	}

	return m_node->data;
}

template <typename ValueType>
template <typename T>
T * CMyList<ValueType>::CIterator<T>::operator->()const
{
	if (!m_node)
	{
		throw std::runtime_error("Iterator as invalid.");
	}

	return m_node;
}

template <typename ValueType>
template <typename T>
typename CMyList<ValueType>::CIterator<T> & CMyList<ValueType>::CIterator<T>::operator++()
{
	if (!m_node)
	{
		throw (std::runtime_error("Iterator has not icrementable."));
	}

	m_isReverse ? m_node = m_node->prev : m_node = m_node->next.get();

	return *this;
}

template <typename ValueType>
template <typename T>
typename CMyList<ValueType>::CIterator<T> & CMyList<ValueType>::CIterator<T>::operator--()
{
	if (m_node && ((m_isReverse && !m_node->next) || (!m_isReverse && !m_node->prev)))
	{
		throw (std::runtime_error("Iterator has not decrementable."));
	}

	if (!m_node)
	{
		m_isReverse ? m_node = m_list->m_firstNode.get() : m_node = m_list->m_lastNode;
	}
	else
	{
		m_isReverse ? m_node = m_node->next.get() : m_node = m_node->prev;
	}

	return *this;
}

template <typename ValueType>
typename CMyList<ValueType>::iterator CMyList<ValueType>::begin()
{
	return iterator(m_firstNode.get(), this);
}

template <typename ValueType>
typename CMyList<ValueType>::iterator CMyList<ValueType>::end()
{
	return iterator(nullptr, this);
}

template <typename ValueType>
typename CMyList<ValueType>::const_iterator CMyList<ValueType>::cbegin()const
{
	return const_iterator(m_firstNode.get(), this);
}

template <typename ValueType>
typename CMyList<ValueType>::const_iterator CMyList<ValueType>::cend()const
{
	return const_iterator(nullptr, this);
}

template <typename ValueType>
typename CMyList<ValueType>::iterator CMyList<ValueType>::rbegin()
{
	return iterator(m_lastNode, this, true);
}

template <typename ValueType>
typename CMyList<ValueType>::iterator CMyList<ValueType>::rend()
{
	return iterator(nullptr, this, true);
}

template <typename ValueType>
typename CMyList<ValueType>::CIterator<const ValueType> CMyList<ValueType>::crbegin()const
{
	return const_iterator(m_lastNode, this, true);
}

template <typename ValueType>
typename CMyList<ValueType>::CIterator<const ValueType> CMyList<ValueType>::crend()const
{
	return const_iterator(nullptr, this, true);
}

template <typename ValueType>
template <typename T>
typename CMyList<ValueType>::CIterator<T> CMyList<ValueType>::Insert(CIterator<T> iter, ValueType const &data)
{
	if (iter.m_list != this)
	{
		throw invalid_argument("Iterator is not valid.");
	}
	auto iterNode = iter.m_node;
	if (iterNode == m_firstNode.get() || (!iterNode && iter.m_isReverse))
	{
		AddToFront(data);
	}
	else if (iterNode == m_lastNode || (!iterNode && !iter.m_isReverse))
	{
		Append(data);
	}
	else
	{
		auto newNode  = make_unique<Node>(data, iterNode->prev , move(iterNode->next));
		newNode->next->prev = newNode.get();
		iter.m_node = newNode->next.get();
		newNode->prev->next = move(newNode);
		++m_size;
	}

	return iter;
}

template <typename ValueType>
template <typename T>
typename CMyList<ValueType>::CIterator<T> CMyList<ValueType>::Erase(CIterator<T> iter)
{
	if (!iter.m_node || iter.m_list != this)
	{
		throw invalid_argument("Iterator is not valid.");
	}
	if (m_size == 1)
	{
		Clear();
		iter = end();
		return iter;
	}
	else if (iter.m_node == m_firstNode.get())
	{
		m_firstNode = move(m_firstNode->next);
		m_firstNode->prev = nullptr;
		iter = begin();
	}
	else if (iter.m_node == m_lastNode)
	{
		m_lastNode = m_lastNode->prev;
		m_lastNode->next = nullptr;
		iter = end();
	}
	else
	{
		auto next = move(iter.m_node->next);
		auto prev = iter.m_node->prev;
		next->prev = prev;
		prev->next = move(next);
		iter = CIterator<T>(prev->next.get(), this, iter.m_isReverse);
	}
	--m_size;

	return iter;
}