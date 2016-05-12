#pragma once
#include <iterator>

class CMyString;

template<typename ValueType>
class MyStrIterator : public std::iterator<std::random_access_iterator_tag, ValueType, ptrdiff_t>
{
	friend class CMyString;
private:
	MyStrIterator(ValueType* value, bool isReverse = false);
public:
	MyStrIterator(const MyStrIterator &it);

	bool operator!=(MyStrIterator const& other) const;
	bool operator==(MyStrIterator const& other) const;
	typename MyStrIterator::reference operator*() const;
	MyStrIterator& operator++();
	MyStrIterator& operator--();
	MyStrIterator& operator+=(size_t value);
	MyStrIterator& operator-=(size_t value);
	ValueType operator[](size_t index)const;
private:
	ValueType* m_pValue;
	bool m_isReverse = false;
};

template<typename ValueType>
MyStrIterator<ValueType>::MyStrIterator(ValueType *value, bool isReverse = false)
	: m_pValue(value)
	, m_isReverse(isReverse)
{
}

template<typename ValueType>
MyStrIterator<ValueType>::MyStrIterator(const MyStrIterator<ValueType>& it) :
	m_pValue(it.m_pValue)
{
}

template<typename ValueType>
ValueType MyStrIterator<ValueType>::operator[](size_t index)const
{
	return m_pValue[index];
}

template<typename ValueType>
bool MyStrIterator<ValueType>::operator!=(MyStrIterator const& other)const	
{
	return m_pValue != other.m_pValue;
}

template<typename ValueType>
bool MyStrIterator<ValueType>::operator==(MyStrIterator const& other)const
{
	return m_pValue == other.m_pValue;
}

template<typename ValueType>
typename MyStrIterator<ValueType>::reference MyStrIterator<ValueType>::operator*()const
{
	return *m_pValue;
}

template<typename ValueType>
MyStrIterator<ValueType> &MyStrIterator<ValueType>::operator++()
{
	m_isReverse ? --m_pValue : ++m_pValue;

	return *this;
}

template<typename ValueType>
MyStrIterator<ValueType> &MyStrIterator<ValueType>::operator--()
{
	m_isReverse ? ++m_pValue : --m_pValue;

	return *this;
}

template<typename ValueType>
ptrdiff_t const operator -(MyStrIterator<ValueType> const &iter1, MyStrIterator<ValueType> const &iter2)
{
	return (&*iter1 - &*iter2);
}

template<typename ValueType>
MyStrIterator<ValueType>& MyStrIterator<ValueType>::operator+=(size_t value)
{
	m_isReverse ? m_pValue -= value : m_pValue += value;

	return *this;
}

template<typename ValueType>
MyStrIterator<ValueType>& MyStrIterator<ValueType>::operator-=(size_t value)
{
	m_isReverse ? m_pValue += value : m_pValue -= value;

	return *this;
}

template<typename ValueType>
MyStrIterator<ValueType> operator +(MyStrIterator<ValueType> iter, size_t value)
{
	return iter += value;
}

template<typename ValueType>
MyStrIterator<ValueType> operator +(size_t value, MyStrIterator<ValueType> iter)
{
	return iter += value;
}

template<typename ValueType>
MyStrIterator<ValueType> const operator++(MyStrIterator<ValueType> & iter, int)
{
	return ++iter;
}

template<typename ValueType>
MyStrIterator<ValueType> const operator--(MyStrIterator<ValueType> & iter, int)
{
	return --iter;
}