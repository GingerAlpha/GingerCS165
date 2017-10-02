// DNA Assignment.cpp : Defines the entry point for the application.


#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/**********************************************************************
* Creates a class which holds two strings. 
***********************************************************************/
class RelativesDNA {
public:
	string m_name;
	string m_dna;
};

/**********************************************************************
* getDNA asks the user for their DNA strand and will reprompt if more 
* or less than 10 letters. Also will reprompt if not using A,C,G,T. 
***********************************************************************/
string getDNA()
{
	string inputDNA;
	cin >> inputDNA;
	while (inputDNA.length() != 10 || inputDNA.find_first_not_of("ACGT") != string::npos)
	{
		if (inputDNA.length() != 10)
		{
			cout << "Enter your 10 letter DNA sequence: ";
			cin >> inputDNA;
		}
		else
		{
			cout << "Enter you DNA sequence only using A,C,G,T: ";
			cin >> inputDNA;
		} // end else - if they dont use ACGT
	} // end while - will reprompt if more or less than 10 letters. 
	return inputDNA;
}

/**********************************************************************
* Asks the user for the number of potential relatives. Returns that
* number to main. Also asks for the names of the relatives and thier 
* DNA sequences. 
***********************************************************************/
int getRelativesDNA(vector<RelativesDNA>& relatives)
{

	int potentialRel; // number of relatives
	cout << "Enter the number of potential relatives: ";
	cin >> potentialRel;
	while (potentialRel > 50 || potentialRel < 1)
	{
		cout << "Enter an ammount between 1 and 50: ";
		cin >> potentialRel;
	} // end while - will ask again if outside of limits 
	cout << endl;
	RelativesDNA relative; 

	for (int i = 0; i < potentialRel; i++)
	{
		cout << "Please enter the name of relative #" << i + 1 << ": ";
		cin >> relative.m_name;
		relatives.push_back(relative);
	} // end for - get all the names of the relatives

	cout << endl;

	for (int a = 0; a < potentialRel; a++)
	{
		cout << "Please enter the DNA sequence for " << relatives[a].m_name << ": ";
		relatives[a].m_dna = getDNA();

	} // end for - get all the dna sequences for the relatives
	cout << endl;

	return potentialRel;
} // end of function - relativesDNA

  /**********************************************************************
  * Takes the userDNA and the RelativesDNA and checks them against each other
  * then adds into a percentage. Displays percent as well. 
  ***********************************************************************/
void percent(int potentialRel, string userDNA, vector<RelativesDNA>& relatives)
{
	for (int i = 0; i < potentialRel; i++)
	{
		int b = 0;
		for (int a = 0; a < 10; a++)
		{
			if (userDNA[a] == relatives[i].m_dna[a])
				b++;
		} // end for - checks each letter for same output
		cout << "Percent Match for " << relatives[i].m_name << ": ";
		cout << b * 10 << "%" << endl;
	} // end for - 
	return;
}

/**********************************************************************
* initiates string userDNA. As well as vector RelativesDNA. Runs the 
* other functions in the program. 
***********************************************************************/
int main()
{
	cout << "Enter your DNA sequence: ";
	string userDNA = getDNA();

	vector<RelativesDNA> relatives;
	int potentialRel = getRelativesDNA(relatives);

	percent(potentialRel, userDNA, relatives);

	return 0;
}