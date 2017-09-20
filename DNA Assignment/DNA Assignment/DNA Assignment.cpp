// DNA Assignment.cpp : Defines the entry point for the application.
//

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
string getUserDNA()
{
	string myDNA;
	cout << "Enter your DNA sequence: ";
	getline(cin, myDNA);

	return myDNA;
}

int getUserDNA(string& myDNA)
{
	cout << "Enter your DNA sequence: ";
	getline(cin, myDNA);
	return 0;

}
/**********************************************************************
* Add text here to describe what the function "main" does. Also don't forget
* to fill this out with meaningful text or YOU WILL LOSE POINTS.
***********************************************************************/
// This function asks the user for the number of relatives and gets their names and dna sequence
int relativesDNA(vector<RelativesDNA>& relatives)
{
//	string relNames[50];
//	string relDNA[50];
	int pots; // number of relatives
	cout << "Enter the number of potential relatives: ";
	cin >> pots;
	cout << endl;
	RelativesDNA relative; 

	for (int i = 0; i < pots; i++)
	{
		cout << "Please enter the name of relative #" << i + 1 << ": ";
		cin >> relative.m_name;
		relatives.push_back(relative);
	} // end for - get all the names of the relatives

	cout << endl;

	for (int a = 0; a < pots; a++)
	{
		cout << "Please enter the DNA sequence for " << relatives[a].m_name << ": ";
		cin >> relatives[a].m_dna;

	} // end for - get all the dna sequences for the relatives
	cout << endl;

	return 0;
} // end of function - relativesDNA


void percent(string myDNA, string relNames[], string relDNA[], int pots)
{
	for (int i = 0; i < pots; i++)
	{
		int b = 0;
		for (int a = 0; a < 10; a++)
		{
			if (myDNA[a] == relDNA[i][a])
				b++;
		}
		cout << "Percent Match for " << relNames[i] << ": ";
		cout << b * 10 << "%" << endl;
	}

	return;
}


int main()
{
	string userDNA;
	vector<RelativesDNA> relatives;
	userDNA = getUserDNA();
	// or
	getUserDNA(userDNA);
	relativesDNA(relatives);
#if 0
	percent(userDNA, relNames, relDNA, pots);
#endif
	return 0;
}
