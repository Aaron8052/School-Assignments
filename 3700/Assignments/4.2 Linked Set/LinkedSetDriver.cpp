/*
    Name: LinkedSet Driver
    Copyright: 2025
    Author: Yu Jiang
    Date: 03/28/2025
    Description: Main test driver for the LinkedSet class.
*/

#include <iostream>
#include "LinkedSet.h"

using namespace std;

string getBoolStr(const bool b)
{
	return b == true ? "true" : "false";
}

void printSet(const LinkedSet<int>& set)
{
	cout << "Current Size: " << set.getCurrentSize()
		<< endl << "Items: " << endl;
	if (set.isEmpty())
	{
		cout << "The set is empty!" << endl << endl;
		return;
	}
	vector<int> vec = set.toVector();
	int vecSize = (int)vec.size();
	for (int i = 0; i < vecSize; i++)
		cout << vec[i] << " ";
	cout << endl << endl;
}

void testContains(LinkedSet<int>& set)
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

void testAdd(LinkedSet<int>& set)
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

void testAddDup(LinkedSet<int>& set)
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

void testRemove(LinkedSet<int>& set)
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

void testClear(LinkedSet<int>& set)
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

void testRemoveFirst(LinkedSet<int>& set)
{
	cout << "-- Test Removes first added item --" << endl;
	set.clear();
	set.add(2);
	set.add(-100);
	set.add(10);
	printSet(set);
	set.remove(2);
	printSet(set);
}

void testRemoveLast(LinkedSet<int>& set)
{
	cout << "-- Test Removes last added item --" << endl;
	set.clear();
	set.add(2);
	set.add(-100);
	set.add(10);
	printSet(set);
	set.remove(10);
	printSet(set);
}

void testRemoveOnlyOne(LinkedSet<int>& set)
{
	cout << "-- Test Remove the only item --" << endl;
	set.clear();
	set.add(2);
	printSet(set);
	set.remove(2);
	printSet(set);
}

int main()
{
	LinkedSet<int> testSet;
	testAdd(testSet);
	testAddDup(testSet);
	testContains(testSet);
	testClear(testSet);
	testRemove(testSet);
	testRemoveFirst(testSet);
	testRemoveLast(testSet);
	testRemoveOnlyOne(testSet);
	return 0;
}
