#pragma once
#include <iterator>
#include <initializer_list>
#include <vector>
// Начиная с С++17 std::iterator - deprecated
template <typename T>
class MergingIterator
{
	
public:
	explicit MergingIterator(std::initializer_list<std::pair<T,T>> list)
	{
		T minObj;

		
		bool isMinObjDefined = false;
		size_t minObjIndex  = 0;
		size_t index = 0;
		for (auto& i : list)
		{
			if (!isMinObjDefined)
			{
				minObj = i.first;
				isMinObjDefined = true;
			}
			else
			{
				if (*minObj > *(i.first)  )
				{
					minObj = i.first;
					minObjIndex = index;
				}
			}
			_iterators.push_back(i);
			index++;
		}
		_currentIterator = minObj;
		_currentIteratorIndex = minObjIndex;
	}

	typename std::iterator_traits<T>::value_type operator* ()
	{
		return *_currentIterator;
	}


	typename std::iterator_traits<T>::value_type operator++ ()
	{
		
		_iterators.at(_currentIteratorIndex).first++;
		T first = _iterators.at(_currentIteratorIndex).first;
		T second = _iterators.at(_currentIteratorIndex).second;
		if (first == second)
		{
			_iterators.erase(_iterators.begin() + _currentIteratorIndex);
		}
		T minObj;
		bool isMinObjDefined = false;
		size_t minObjIndex = 0;
		size_t index = 0;
		if (_iterators.size() != 0)
		{
			for (auto& i : _iterators)
			{
				if (!isMinObjDefined)
				{
					minObj = i.first;
					isMinObjDefined = true;
				}
				else
				{
					if (*minObj > *(i.first))
					{
						minObj = i.first;
						minObjIndex = index;
					}
				}

				index++;
			}
			_currentIterator = minObj;
			_currentIteratorIndex = minObjIndex;
		}
			return *_currentIterator;
		
	}
	

private:
		std::vector<std::pair<T,T>> _iterators;
		T _currentIterator;
		size_t _currentIteratorIndex;
};
namespace std {
	template <typename T>
	struct iterator_traits<MergingIterator<T>> {
		using iterator_category =
			std::forward_iterator_tag;
		using value_type = T;
		//using pointer = ...;
		//using reference = ...;
		//using difference_type = ...;
	};
}