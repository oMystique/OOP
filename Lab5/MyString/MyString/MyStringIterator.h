#pragma once
#include <iterator>

class CMyString;

template<typename ValueType>
class MyStrIterator : public std::iterator<std::input_iterator_tag, ValueType>
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
	ValueType* value;
};

template<typename ValueType>
MyStrIterator<ValueType>::MyStrIterator(ValueType *value) :
	value(value)
{
}

template<typename ValueType>
MyStrIterator<ValueType>::MyStrIterator(const MyStrIterator& it) :
	value(it.value)
{
}

template<typename ValueType>
bool MyStrIterator<ValueType>::operator!=(MyStrIterator const& other) const
{
	return value != other.value;
}

template<typename ValueType>
bool MyStrIterator<ValueType>::operator==(MyStrIterator const& other) const
{
	return value == other.value;
}

template<typename ValueType>
typename MyStrIterator<ValueType>::reference MyStrIterator<ValueType>::operator*() const
{
	return *value;
}

template<typename ValueType>
MyStrIterator<ValueType> &MyStrIterator<ValueType>::operator++()
{
	++value;
	return *this;
}

template<typename ValueType>
MyStrIterator<ValueType> &MyStrIterator<ValueType>::operator--()
{
	--value;
	return *this;
}

template<typename ValueType>
size_t const operator -(MyStrIterator<ValueType> const &iter1, MyStrIterator<ValueType> const &iter2)
{
	return iter1.value - iter2.value;
}

template<typename ValueType>
size_t const operator +(MyStrIterator<ValueType> const &iter, int value)
{
	if (iter.value == m_length || iter.value + value > m_length)
	{
		throw std::out_of_range("Out of range.");
	}

	return iter.value + value;
}

template<typename ValueType>
size_t const operator +(int value, MyStrIterator<ValueType> const &iter)
{
	if (iter.value == m_length || iter.value + value > m_length)
	{
		throw std::out_of_range("Out of range.");
	}

	return iter.value + value;
}