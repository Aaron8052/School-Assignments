/*
	Name: LinkedList Test
	Copyright: 2024
	Author: Yu Jiang
	Date: 22/05/24 11:54
	Description: Test the NumberList class.
*/

#include <iostream>
#include "NumberList.h"
using namespace std;

// Test driver NumberList
int main(int argc, char** argv) {
	NumberList list;
	list.insertNode(30);
	list.insertNode(25);
	list.insertNode(40);
	list.insertNode(18);
	list.insertNode(59);
	cout << "Starting list: \n";
	list.displayList();
	list.appendNode(0);
	cout << "Append Node: \n";
	list.displayList();
	list.deleteNode(59);
	cout << "Delete Node: \n";
	list.displayList();
	return 0;
}