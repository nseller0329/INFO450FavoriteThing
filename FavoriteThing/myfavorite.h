#pragma once
#include <string>
using namespace std;

class myfavorite
{
private:
	int ID;
	int i;
	string name;
	string console;
	string genre;
	string owned;

public:
	int getFavorite();
	void displayFavorites();
	myfavorite();
	myfavorite(int i, string nm, string csl, string gr, string owd);
	~myfavorite();

	friend ofstream& operator<<(ofstream &fs, myfavorite *item);
	friend bool operator==(const myfavorite &a, const myfavorite &b);
};

