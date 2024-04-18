/*
	Name: Assignment: 12.6: String Search
	Copyright: 2024
	Author: Yu Jiang
	Date: 12/04/24 12:14
	Description:
		Book Chapter 12 Programming Challenges #6 String Search
		Write a program that asks the user for a file name
		and a string for which to search. The program should 
		search the file for every occurrence of a specified 
		string. When the string is found, the line that contains 
		it should be displayed. After all the occurrences have 
		been located, the program should report the number of times
		the string appeared in the file.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// Prototypes
void openFile(ifstream&);
void searchLines(ifstream&, string);
bool strContains(string, string);

// Main Driver
int main(int argc, const char * argv[]) {
	ifstream indata;
	openFile(indata);
	cout << "Please enter a string to search for occurences: ";
	string strToSearch = "";
	getline(cin, strToSearch);
	searchLines(indata, strToSearch);
	return 0;
}

// Ask user for filename input, and opens the file
void openFile(ifstream& infile) {
	string fileName = "";
	cout << "Please enter file name to read: ";
	cin >> fileName;
	infile.open(fileName);
	while(!infile) {
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		cout << "Please enter file name to read: ";
		cin >> fileName;
		infile.open(fileName);
	}
	cin.ignore();
}

// Reads the file line by line and look for string occurences
void searchLines(ifstream& infile, string strToSearch) {
	string currentLine;
	unsigned int lineCount = 1;
	unsigned int occurences = 0;
	cout << "\nString to search:\t\"" << strToSearch << "\"" << endl;
	cout << "\nOccured in lines:\t";
	while(getline(infile, currentLine)) {
		if(strContains(currentLine, strToSearch)) {
			cout << "\n#"<<lineCount << ":\t" << currentLine;
			occurences ++;
		}
		lineCount ++;
	}
	cout << "\n\nTotal occurences:\t" << occurences;
}

// Check if "strToSearch" is contained in "line"
bool strContains(string line, string strToSearch) {
	return line.find(strToSearch) != line.npos;
}