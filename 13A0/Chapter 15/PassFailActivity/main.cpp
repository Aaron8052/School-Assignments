/*
	Name: Test GradedActivity
	Copyright: 2024
	Author: Yu Jiang
	Date: 13/05/24 12:08
	Description: 
*/

#include <iostream>
#include "GradedActivity.h"
#include "PassFailActivity.h"
#include "PassFailExam.h"
using namespace std;

// Print a grading report
void printReport(const GradedActivity &test){
	cout << "Test score is " << test.getScore()
		 << " for a letter grade of " << test.getLetterGrade() << endl;
}

// Main test driver
int main(int argc, char** argv) {
	// Test GradedActivity
	GradedActivity test1(80);
	test1.setScore(85);
	printReport(test1);
	
	// Test PassFailActivity
	PassFailActivity test2(70);
	test2.setScore(80);
	printReport(test2);
	
	// Test PassFailExam
	PassFailExam test3(20, 10, 70);
	printReport(test3);
	return 0;
}