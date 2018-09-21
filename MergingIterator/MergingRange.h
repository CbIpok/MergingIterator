#pragma once
#include <iterator>
#include <initializer_list>
#include <vector>
#include "MergingIterator.h"
// Начиная с С++17 std::iterator - deprecated
template <typename T>
class MergingRange
{

public:
	
	explicit MergingRange(std::initializer_list<std::pair<T, T>> list)
	{
		_begin = MergingIterator<T>(list);
	}

	MergingIterator<T> begin()
	{
		return _begin;
	}

	MergingIterator<T> end()
	{
		return MergingIterator<T>();
	}
private:
	MergingIterator<T> _begin;
};

