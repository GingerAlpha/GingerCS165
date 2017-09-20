// DNA Assignment.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <sstream>

using namespace std;

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

int relativesDNA()
{
	string relNames[50];
	string relDNA[50];
	int pots;
	cout << "Enter the number of potential relatives: ";
	cin >> pots;
	cout << endl;

	for (int i = 0; i < pots; i++)
	{
		cout << "Please enter the name of relative #" << i + 1 << ": ";
		cin >> relNames[i];

	}

	cout << endl;

	for (int a = 0; a < pots; a++)
	{
		cout << "Please enter the DNA sequence for " << relNames[a] << ": ";
		cin >> relDNA[a];

	}
	cout << endl;

	return 0;
}

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
	userDNA = getUserDNA();
	// or
	getUserDNA(userDNA);
	relativesDNA();
	percent(userDNA, relNames, relDNA, pots);

	return 0;
}
