// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


struct timeStamp
{
	string username;
	string filename;
	long time;
};

void getInput(long& startTime, long& endTime)
{

	cout << "Enter the start time: ";
	cin >> startTime;
	cout << "Enter the end time: ";
	cin >> endTime;
	cout << endl;

	return;
}

void readFile(timeStamp &fileOutput[])
{
	string recordFile;
	cout << "Enter the access record file: ";
	cin >> recordFile;
	cout << endl;

	ifstream fin;
	fin.open(recordFile);


	for (int i = 0; i < 100; i++)
	{
		fin >> fileOutput[i].filename >> fileOutput[i].username
			>> fileOutput[i].time;

	}

	fin.close();




	return;
}

void display()
{
	cout << "The following records match your criteria: " << endl;
	cout << endl;
	cout << setw(15) << "Timestamp" << setw(20) << "File";
	cout << setw(20) << "User" << endl;
	cout << "--------------- ------------------- -------------------" << endl;



	cout << "End of records" << endl;

	return;
}

/**********************************************************************
* Add text here to describe what the function "main" does. Also don't forget
* to fill this out with meaningful text or YOU WILL LOSE POINTS.
***********************************************************************/
int main()
{

	timeStamp fileOutput[150];
	long startTime;
	long endTime;

	readFile(fileOutput);
	getInput(startTime, endTime);
	display();

	return 0;
}

