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
* getUserDNA asks the user for their DNA strand and will reprompt if more 
* or less than 10 letters. 
***********************************************************************/
void getUserDNA(string& userDNA)
{
	cout << "Enter your DNA sequence: ";
	getline(cin, userDNA);
	while (userDNA.length != 10)
	{
		cout << "Enter your 10 letter DNA sequence: ";
		getline(cin, userDNA);
	} // end while - will reprompt if more or less than 10 letters. 
	return;
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
		cin >> relatives[a].m_dna;
		while (relatives[a].m_dna.length != 10)
		{
			cout << "Please enter the 10 letter DNA sequence for " << relatives[a].m_name << ": ";
			cin >> relatives[a].m_dna;
		} // end while - asks the user for new input if does not ten letters.
		

		
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
		}
		cout << "Percent Match for " << relatives[i].m_name << ": ";
		cout << b * 10 << "%" << endl;
	}

	int pause;
	cin >> pause;
	return;
}

/**********************************************************************
* initiates string userDNA. As well as vector RelativesDNA. Runs the 
* other functions in the program. 
***********************************************************************/
int main()
{

	string userDNA;

	vector<RelativesDNA> relatives;
	getUserDNA(userDNA);
	int potentialRel = getRelativesDNA(relatives);

	percent(potentialRel, userDNA, relatives);

	return 0;
}
