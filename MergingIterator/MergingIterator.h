#pragma once
#include <iterator>
#include <initializer_list>
#include <vector>
// Начиная с С++17 std::iterator - deprecated
template <typename T>
class MergingIterator
{
	
public:
	MergingIterator()
	{
		_eof == true;
	}
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
		_eof = false;
	}

	typename std::iterator_traits<T>::value_type operator* ()
	{
		return *_currentIterator;
	}


	typename std::iterator_traits<T>::value_type operator++ ()
	{
		if (_iterators.size()==0)
		{
			_eof = true;
			return *_currentIterator;
		}
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
	
	typename std::iterator_traits<T>::value_type operator++ (int unused)
	{
		T toReturn = _currentIterator;
		this->operator++();
		return *toReturn;
	}
	
	inline bool eof() const
	{
		return _eof; 
	}
	
	inline bool operator ==(const MergingIterator<T> second) const
	{
		return _eof && second.eof();
	}

	inline bool operator !=(const MergingIterator<T> second) const
	{
		return !(this->_eof && second.eof());
	}

	
	MergingIterator<T>& operator&() = delete;
private:
		std::vector<std::pair<T,T>> _iterators;
		T _currentIterator;
		size_t _currentIteratorIndex;
		bool _eof;
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