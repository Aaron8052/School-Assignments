/*
	Name: Assignment: 16.10: SortableVector Class Template
	Copyright: 2024
	Author: Yu Jiang
	Date: 31/05/24 22:40
	Description: A SortableVector class implemetation 
		inherited from SimpleVector class, and the test driver
*/

#include "FeetInches.h"
#include "SimpleVector.h"
#include <iostream>
using namespace std;

// Generic type T
// SortableVector class inherited from SimpleVector class
template <class T>
class SortableVector : public SimpleVector<T>
{
	public: 
		void sort();
		SortableVector() : SimpleVector<T>(){}
		SortableVector(int size) : SimpleVector<T>(size){}
		SortableVector(const SortableVector &obj) : SimpleVector<T>(&obj){}
};

// Print the vec
template <class T>
void printVec(SortableVector<T> &vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}

// Test driver
int main(int argc, char** argv) {
	SortableVector<FeetInches> vec(5);
	FeetInches test1(1, 2);
	vec[0] = test1;
	FeetInches test2(2, 4);
	vec[1] = test2;
	FeetInches test3(1, 3);
	vec[2] = test3;
	FeetInches test4(10, 11);
	vec[3] = test4;
	FeetInches test5(8, 10);
	vec[4] = test5;
	cout << "B4 sort:\n";
	printVec(vec);
	vec.sort();
	cout << "\nAft sort:\n";
	printVec(vec);
	return 0;
}

// Implementation of the sort func
template <class T>
void SortableVector<T>::sort()
{
	// Bubble sort
	int maxElement = this->size() - 1;
	for(int i = 0; i < this->size() - 1; i++)
	{
		for(int j = 0; j < maxElement; j++)
		{
			if((*this)[j] > (*this)[j + 1])
			{
				T temp = (*this)[j];
				(*this)[j] = (*this)[j + 1];
				(*this)[j + 1] = temp;
			}
		}
		maxElement --;
	}
}