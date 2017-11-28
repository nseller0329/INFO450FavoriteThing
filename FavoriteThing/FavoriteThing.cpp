// FavoriteThing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myfavorite.h"
#include <iostream>
#include <fstream>

using namespace std;
string getFile();
const int LISTSIZE = 50;

int main()
{
	myfavorite **mylist;
	int count = 0;

	int i;
	string response = "Y";

	mylist = new myfavorite*[LISTSIZE];

	string path = getFile();
	ifstream infile(path);

	if (infile.good())
	{
		while (!infile.eof())
		{
			string ID,name,console,genre,owned;
			getline(infile, ID, '|');
		
			if (ID.length())
			{ 
				getline(infile, name,'|');
				getline(infile, console,'|');
				getline(infile, genre,'|');
				getline(infile, owned,'\n');
				mylist[count] = new myfavorite (stoi(ID), name, console, genre, owned);
				count++;
			}
		} 
	}

	cout << "You have " << count << " records. Would you like to add any?" << endl;
	cin >> response;

	while (response == "Y" || response == "y")
	{
		mylist[count] = new myfavorite();
		if (mylist[count]->getFavorite() == 0) count++;
		
		cout << "Would you like to add another one?" << endl;
		cin >> response;
	}

	for (i = 0; i < count; i++)
	{
		mylist[i]->displayFavorites();
	}






	ofstream outfile(path);

	if (!outfile.good())

	{
		cout << "ERROR - can not open file for output." << endl;
		return -1;
	}
	for (i = 0; i < count; i++)

	{

		outfile << mylist[i];
		cout << "Successful Save." << endl;
	}

	for (i = 0; i < count; i++)
	{
		delete mylist[i];
	}
	delete mylist[i];

    return 0;
}

string getFile()
{
	string path;
	cout << "Please enter the file path: ";
	getline(cin, path);
	return path;

}

