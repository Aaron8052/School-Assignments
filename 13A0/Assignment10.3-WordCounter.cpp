/*
	Name: Assignment: 10.3: Word Counter
	Copyright: 2024
	Author: Yu Jiang
	Date: 29/03/24 12:14
	Description: 
		A program that counts num of words in a string
*/

#include <iostream>
#include <cstring>
using namespace std;

// Prototypes
char* toCstr(string str);
int getWordCount(string);
int getWordCount(char*);

// Main Driver
int main(int argc, char** argv)
{
	// Test Scripts
	// string test = "   a      ";
	// string test = " Hello World 123 456 !!!  ";
	// string test = "     ";
	// string test = " ";
	// cout << getWordCount(toCstr(test)) << endl;
	const int MAX_SIZE = 80;
	char* strptr = new char[MAX_SIZE];
	cout << "The enter a string within 80 characters:" << endl;
	cin.getline(strptr, MAX_SIZE);
	cout << "String:\t\t\"" << strptr << "\"\n"
		 << "Words:\t\t" << getWordCount(strptr) << "\n\n";
	system("pause");
	delete [] strptr;
	return 0;
}

// Converts a C++ str to C-Str
char* toCstr(string str)
{
	int len = str.length();
	char* cstr = new char[len + 1];
	for(int i = 0; i < len; i++)
	{
		*(cstr + i) = str[i];
	}
	*(cstr + len) = '\0';
	return cstr;
}

// Check if the str is null or empty
bool isNullStr(char* str)
{
	return str == nullptr || *str == '\0';
}

// get the index of the first non white space char
int getFirstCharPos(char* str)
{
	int firstCharPos = 0;
	while(isspace(*(str + firstCharPos)) && !isNullStr(str + firstCharPos))
	{
		firstCharPos++;
	}
	return firstCharPos;
}

// get the index of the last non white space char
int getEndCharPos(char* str)
{
	int endCharPos = strlen(str) - 1;
	if(endCharPos <= 0)
		return 0;
	while(isspace(*(str + endCharPos)) && endCharPos > 0)
	{
		endCharPos--;
	}
	return endCharPos;
}

// Get word count of a str
// within a given beginning and ending index
int getWordCountInRange(char* str, int begin, int end)
{
	int wordCount = 0;
	
	// Iterate thru the str from begin to end
	// and count for words
	bool isCurrentWhiteSpace = true;
	for(int i = begin; i < end; i++)
	{
		char* currentPtr = (str + i);
		
		// the current char is white space
		if(*currentPtr == ' ')
		{
			isCurrentWhiteSpace = true;
			continue;
		}
		
		// beginning of a new word
		if(isCurrentWhiteSpace)
			wordCount ++;
		isCurrentWhiteSpace = false;
	}
	return wordCount;
}

// an overloaded version of 
// getWordCount(char*) that accepts C++ string instead
int getWordCount(string str)
{
	return getWordCount(toCstr(str));
}

// Counts number of words in a C-String
int getWordCount(char* str)
{
	if(isNullStr(str))
		return 0;	
		
	// Trim the str
	int strLen = strlen(str), 
		firstCharPos = getFirstCharPos(str), 
		endCharPos = getEndCharPos(str);
		
	// true when the entire str are white spaces
	if(endCharPos <= 0 || firstCharPos == strLen)
		return  0;
	int wordCount = getWordCountInRange(str, firstCharPos, endCharPos + 1);
	return wordCount;
}