#include "pch.h"
#include <vector>
#include "MergingIterator.h"
#include "MergingRange.h"
#include <initializer_list>
#include <iostream>
using namespace std;
class TestCaseFixing : public ::testing::Test {
protected:
	virtual void SetUp(void) {
		// настройка перед запуском очередного теста
	}
	virtual void TearDown(void) {
		// очистка после прогона очередного теста
	}
	/*vector<int> range1 { 1,2,3,4,5,6 };
	vector<int> range2{ 3,4,5,6,7,8,9 };
	vector<int> range3{ 6,7,8,9,10,11,12 };

	MergingRange<vector<int>> NullMerRange({ {range1.begin(),range1.begin()} });*/
	vector<int> a{ 1,2,3 };
	vector<int> b{ 1,2,3 };
	vector<int> c{ 1,2,3 };

	MergingRange < vector<int>::iterator> merRange({ { a.begin(),a.end() }, { b.begin(),b.end() }, { c.begin(),c.end() } });
	
};

TEST_F(TestCaseFixing, NoParams)
{

	//noParamsMerRange.begin() == noParamsMerRange.end();
	
}