#include <vector>
#include "MergingIterator.h"
#include "MergingRange.h"
#include <initializer_list>
#include <iostream>
using namespace std;
int main()
{
	vector<int> a{ 1,2,3 };
	vector<int> b{ 1,2,3 };
	vector<int> c{ 1,2,3 };
	
	MergingRange < vector<int>::iterator> merRange({ { a.begin(),a.end() }, { b.begin(),b.end() }, { c.begin(),c.end() } });
	
	for (auto i : merRange)
	{
		cout << i<<endl;
	}


}