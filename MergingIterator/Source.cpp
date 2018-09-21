#include <vector>
#include "MergingIterator.h"
#include <initializer_list>
#include <iostream>
using namespace std;
int main()
{
	vector<int> a{ 1,2,3 };
	vector<int> b{ 1,2,3 };
	vector<int> c{ 1,2,3 };
	
	//initializer_list<std::pair< vector<int>::iterator, vector<int>::iterator> = 
	MergingIterator < vector<int>::iterator> merIterator({ { a.begin(),a.end() }, { b.begin(),b.end() }, { c.begin(),c.end() } });
	for (size_t i = 0; i < 9; i++)
	{
		cout << *merIterator<<endl;
		++merIterator;
	}

}