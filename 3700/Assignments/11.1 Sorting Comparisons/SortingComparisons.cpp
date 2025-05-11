/*
    Name: SortingComparisons
    Copyright: 2025
    Author: Yu Jiang
    Date: 05/10/2025
    Description: The C++ implementation file for the SortingComparisons class.
*/

#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include "InsertionSort.hpp"
#include "MergeSort.hpp"

bool randInited;
int getRandInt()
{
	if (!randInited)
	{
		srand(time(nullptr));
		randInited = true;
	}
	return rand();
}

void getRandArrayOfSize(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = getRandInt();
}


void testSize(const int size)
{
	int srcArr[size], dupArr1[size], dupArr2[size];
	getRandArrayOfSize(srcArr, size);
	std::copy(srcArr, srcArr + size, dupArr1);
	std::copy(srcArr, srcArr + size, dupArr2);
	unsigned int actualInsertion = insertionSort<int>(dupArr1, size);
	unsigned int algInsertion = size * size;
	unsigned int actualMerge = mergeSort<int>(dupArr2, 0, size - 1);
	unsigned int algMerge = size * log(size);
	std::cout << "Size: " << size << std::endl
		<< "Comparisons of Insertion Sort: " << actualInsertion << std::endl
		<< "Theoretical Comparisons of Insertion Sort: " << algInsertion << std::endl
		<< "Difference: " << abs(actualInsertion - algInsertion) << std::endl
		<< "Comparisons of Merge Sort: " << actualMerge << std::endl
		<< "Theoretical Comparisons of Merge Sort: " << algMerge << std::endl
		<< "Difference: " << abs(actualMerge - algMerge)
		<< std::endl << std::endl;
}

int main()
{
	testSize(10);
	testSize(100);
	testSize(1000);
	testSize(10000);
	// testSize(100000);
	return 0;
}
