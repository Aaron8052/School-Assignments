/*
	Name: ArraySet
	Copyright: 2025
	Author: Yu Jiang
	Date: 19/03/25 23:06
	Description: ArraySet Test Driver
*/

#include <iostream>
#include "ArraySet.hpp"

using namespace std;

string getBoolStr(bool b)
{
	return b == true ? "true" : "false";
}
void printSet(ArraySet<int>& set)
{
	cout << "Max Size: " << set.getMaxSize()
		<< endl
		<< "Current Size: " << set.getCurrentSize()
		<< endl << "Items: " << endl;
	if(set.isEmpty())
	{
		cout << "The set is empty!" << endl << endl;
		return;
	}
	vector<int> vec = set.toVector();
	int vecSize = (int)vec.size();
	for(int i = 0; i < vecSize; i++)
		cout << vec[i] << " ";
	cout << endl << endl;
}

void testContains(ArraySet<int>& set)
{
	cout << "-- Test Contains --" << endl;
	set.clear();
	set.add(-10);
	set.add(4);
	set.add(7);
	set.add(9);
	printSet(set);
	cout << "Is Contains 4 ? " 
		<< getBoolStr(set.contains(4)) << endl
		<< "Is Contains 99 ? " 
		<< getBoolStr(set.contains(99)) 
		<< endl << endl;
}
	

void testAdd(ArraySet<int>& set)
{
	cout << "-- Test Add 2, -100, -10, 4 --" << endl;
	set.clear();
	set.add(2);
	set.add(-100);
	printSet(set);
	set.add(-10);
	set.add(4);
	printSet(set);
}

void testAddDup(ArraySet<int>& set)
{
	cout << "-- Test Add Duplicates 1, 5, 7, 9 --" << endl;
	set.clear();
	set.add(1);
	set.add(5);
	printSet(set);
	set.add(1);
	set.add(5);
	set.add(7);
	set.add(9);
	printSet(set);
}

void testExpand(ArraySet<int>& set)
{
	cout << "-- Test Size Expansion --" << endl;
	int attemps = set.getMaxSize() * 2;
	for(int i = attemps; i > 0; i --)
		set.add(i);
	printSet(set);
}

void testRemove(ArraySet<int>& set)
{
	cout << "-- Remove 10, 14 --" << endl;
	set.clear();
	set.add(2);
	set.add(-100);
	set.add(10);
	set.add(114514);
	printSet(set);
	set.remove(10);
	set.remove(14);
	printSet(set);
}

void testClearAndEmpty(ArraySet<int>& set)
{
	cout << "-- Clear All Items --" << endl;
	set.clear();
	set.add(2);
	set.add(-100);
	set.add(10);
	printSet(set);
	set.clear();
	printSet(set);
}

void testRemoveFirst(ArraySet<int>& set)
{
	cout << "-- Test Removes first item --" << endl;
	set.clear();
	set.add(2);
	set.add(-100);
	set.add(10);
	printSet(set);
	set.remove(2);
	printSet(set);
}

void testRemoveLast(ArraySet<int>& set)
{
	cout << "-- Test Removes last item --" << endl;
	set.clear();
	set.add(2);
	set.add(-100);
	set.add(10);
	printSet(set);
	set.remove(10);
	printSet(set);
}

void testRemoveOnlyOne(ArraySet<int>& set)
{
	cout << "-- Test Remove the only item --" << endl;
	set.clear();
	set.add(2);
	printSet(set);
	set.remove(2);
	printSet(set);
}

void testZeroSizeSet()
{
	cout << "-- Test 0 initSize --" << endl;
	ArraySet<int> testSet(0);
	printSet(testSet);
	testSet.add(1);
	testSet.add(2);
	testSet.add(3);
	printSet(testSet);
}

int main(){

	ArraySet<int> testSet(2);
	testAdd(testSet);
	testAddDup(testSet);
	testExpand(testSet);
	testContains(testSet);
	testClearAndEmpty(testSet);
	testRemove(testSet);
	testRemoveFirst(testSet);
	testRemoveLast(testSet);
	testRemoveOnlyOne(testSet);
	testZeroSizeSet();
	return 0;
}

