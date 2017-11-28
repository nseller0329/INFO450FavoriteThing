#include "stdafx.h"
#include "myfavorite.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

myfavorite::myfavorite()
{
	ID = 0;
	name = "";
	console = "";
	genre = "";
	owned = ' ';
}
myfavorite::myfavorite(int i, string nm, string csl, string gr, string owd)
{
	ID = i;
	name = nm;
	console = csl;
	genre = gr;
	owned = owd;

}
myfavorite::~myfavorite()
{
}

int myfavorite::getFavorite()

{
	cout << "What is the ID number? " << endl;
	cin >> ID;
	cin.ignore();
	cin.clear();
	cout << "What is the name of your favorite video game?" << endl;
	getline(cin, name);
	cout << "What console is it on?" << endl;
	getline(cin, console);
	cout << "What genre is it?" << endl;
	getline(cin, genre);
	cout << "Do you own it (Y/N)?" << endl;
	getline(cin, owned);

	while ((owned != "y") && (owned != "Y") && (owned != "N") && (owned != "n"))
	{
		cout << "Invalid Please enter a valid option." << endl;
		getline(cin, owned);
	}

	return 0;
}

void myfavorite::displayFavorites()
{
	cout << "*****Your Favorite Game: " << ID << "*****" << endl;
	cout << "Name: " << name << endl;
	cout << "Console: " << console << endl;
	cout << "Genre: " << genre << endl;
	cout << "Owned: " << owned << endl;
}

ofstream& operator<<(ofstream &fs, myfavorite *item)
{
	fs << item->ID << "|" << item->name << "|" << item->console << "|" << item->genre << "|" << item->owned << endl;
	return fs;
}

bool operator==(const myfavorite &a, const myfavorite &b)
{
	if ((a.name == b.name) && (a.ID == b.ID))
		return -1;

	else return 0;

}