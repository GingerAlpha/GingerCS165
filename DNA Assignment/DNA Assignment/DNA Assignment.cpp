// DNA Assignment.cpp : Defines the entry point for the application.


#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class RelativesDNA {
public:
	string m_name;
	string m_dna;
};

/**********************************************************************
* Add text here to describe what the function "main" does. Also don't forget
* to fill this out with meaningful text or YOU WILL LOSE POINTS.
***********************************************************************/

int getUserDNA(string& userDNA)
{
	cout << "Enter your DNA sequence: ";
	getline(cin, userDNA);
	return 0;

}
/**********************************************************************
* Add text here to describe what the function "main" does. Also don't forget
* to fill this out with meaningful text or YOU WILL LOSE POINTS.
***********************************************************************/
//<<<<<<< Updated upstream
// This function asks the user for the number of relatives and gets their names and dna sequence
//int relativesDNA(vector<RelativesDNA>& relatives)
//=======

int getRelativesDNA(vector<RelativesDNA>& relatives)
//>>>>>>> Stashed changes
{

	int potentialRel; // number of relatives
	cout << "Enter the number of potential relatives: ";
	cin >> potentialRel;
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

	} // end for - get all the dna sequences for the relatives
	cout << endl;

	return potentialRel;
} // end of function - relativesDNA


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

	return;
}

int main()
{

	string userDNA;

	vector<RelativesDNA> relatives;
	getUserDNA(userDNA);
	int potentialRel = getRelativesDNA(relatives);

	percent(potentialRel, userDNA, relatives);

	return 0;
}
