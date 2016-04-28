#include "stdafx.h"
#include "MyString.h"

template<typename ValueType>
MyStrIterator<ValueType>::MyStrIterator(ValueType *p) :
	p(p)
{

}

template<typename ValueType>
MyStrIterator<ValueType>::MyStrIterator(const MyStrIterator& it) :
	p(it.p)
{
}

template<typename ValueType>
bool MyStrIterator<ValueType>::operator!=(MyStrIterator const& other) const
{
	return p != other.p;
}

template<typename ValueType>
bool MyStrIterator<ValueType>::operator==(MyStrIterator const& other) const
{
	return p == other.p;
}

template<typename ValueType>
typename MyStrIterator<ValueType>::reference MyStrIterator<ValueType>::operator*() const
{
	return *p;
}

template<typename ValueType>
MyStrIterator<ValueType> &MyStrIterator<ValueType>::operator++()
{
	++p;
	return *this;
}