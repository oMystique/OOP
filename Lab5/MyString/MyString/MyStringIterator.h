#pragma once
#include <iterator>

class CMyString;

template<typename ValueType>
class MyStrIterator : public std::iterator<std::random_access_iterator_tag, ValueType, ptrdiff_t>
{
	friend class CMyString;
private:
	MyStrIterator(ValueType* value);
public:
	MyStrIterator(const MyStrIterator &it);

	bool operator!=(MyStrIterator const& other) const;
	bool operator==(MyStrIterator const& other) const;
	typename MyStrIterator::reference operator*() const;
	MyStrIterator& operator++();
	MyStrIterator& operator--();
	MyStrIterator& operator+=(size_t value);
	ValueType const operator[](size_t index)const;
	ValueType &operator[](size_t index);
private:
	ValueType* m_pValue;
};

template<typename ValueType>
MyStrIterator<ValueType>::MyStrIterator(ValueType *value)
	: m_pValue(value)
{
}

template<typename ValueType>
MyStrIterator<ValueType>::MyStrIterator(const MyStrIterator<ValueType>& it) :
	m_pValue(it.m_pValue)
{
}

template<typename ValueType>
ValueType const MyStrIterator<ValueType>::operator[](size_t index)const
{
	return m_pValue[index];
}

template<typename ValueType>
ValueType &MyStrIterator<ValueType>::operator[](size_t index)
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
	++m_pValue;
	return *this;
}

template<typename ValueType>
MyStrIterator<ValueType> &MyStrIterator<ValueType>::operator--()
{
	--m_pValue;
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
	m_pValue += value;
	return *this;
}

template<typename ValueType>
MyStrIterator<ValueType> const operator +(MyStrIterator<ValueType> &&iter, size_t value)
{
	iter += value;
	return (iter);
}

template<typename ValueType>
MyStrIterator<ValueType> const operator +(size_t value, MyStrIterator<ValueType> &&iter)
{
	iter += value;
	return (iter);
}

template<typename ValueType>
MyStrIterator<ValueType> const operator++(MyStrIterator<ValueType> & iter, int)
{
	++iter;
	return iter;
}

template<typename ValueType>
MyStrIterator<ValueType> const operator--(MyStrIterator<ValueType> & iter, int)
{
	--iter;
	return iter;
}