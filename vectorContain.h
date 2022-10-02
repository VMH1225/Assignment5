#pragma once
#ifndef VECTORCONTAIN_H
#define VECTORCONTAIN_H

#include "Studnt.h"
#include <iostream>
#include <vector>
#include "input.h"
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class vectorContain
{
private:
	vector<student> studentRecord;
	vector<student>::iterator iter;
public:
	// precondition:
	// postcondition: main process for vector container program
	void vectorMain();
	// precondition:
	// postcondition: checks if the list is empty
	bool emptyVector();
	// precondition:
	// postcondition: returns the amount to reserve
	int amountReserve();
	// precondition:
	// postcondition:
	// returns the amount to resize
	int amountResize();
	// precondition: requires a file named "input.dat" with student records
	// postcondition: reads a file and stores the data into the vector with push_back()
	void readAndStoreData(vector<student>& studentRecord);
	// precondition: requires v1 to have data
	// postcondition: prints out the student info at position n in the vector
	void vectorIndex();
	// precondition: requires v1 to have data
	// postcondition: utilizing begin() and end() and prints out the vector
	void beginAndEndIterator();
	// precondition: requires v1 to have data
	// postcondition: utilizing rbegin() and rend() and prints out the vector
	void rBeginAndrEndIterator();
	// precondition: requires v1 to have data and an element after begin()
	// postcondition: utilizing erase() and erases an element after begin() if it exists
	void eraseIt();
	// precondition: requires v1 to have data
	// postcondition: utilizing erase() and erases from begin() to end()
	void eraseBeginAndEnd();
	// precondition:
	// postcondition: utilizing insert() and inserts another set of element after begin()
	void insertElement();
	// precondition: requires v1 to have data
	// postcondition: utilizing swap() and swaps data with another vector
	void swapVector(vector<student>& v2);
};

#endif // !VECTORCONTAIN_H
