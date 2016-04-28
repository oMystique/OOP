#pragma once
#include <iterator>

class CMyString;

template<typename ValueType>
class MyStrIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
	friend class CMyString;
private:
	MyStrIterator(ValueType* p);
public:
	MyStrIterator(const MyStrIterator &it);

	bool operator!=(MyStrIterator const& other) const;
	bool operator==(MyStrIterator const& other) const; //need for BOOST_FOREACH
	typename MyStrIterator::reference operator*() const;
	MyStrIterator& operator++();
private:
	ValueType* p;
};
