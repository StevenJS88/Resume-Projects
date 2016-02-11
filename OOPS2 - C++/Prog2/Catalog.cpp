//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: 
//
// Purpose: Prog2
//
//---------------------------------------------------------------------
#include "Catalog.h"
#include <iomanip>

#ifdef CATALOG_TEST
#include <fstream>
using namespace std;

#endif

Catalog::Catalog(const Catalog& orig) { }

Catalog::~Catalog() { List->~LList(); delete List; }

void Catalog::Run()
{
	char input;
	int number;
	cin >> number;
	cout << "There are " <<  number  <<" types of fruits initially in the list." << endl;
    cout << "They will be read in and inserted in the list in order." << endl;
	while (number > 0)
	{
		Fruit *new1 = new Fruit();
		cin >> *new1;
		if ( List->Insert(new1) )
		{
		   cout << "Added to list: " << setw(5) << *new1 << endl;
		}
		number--;
	}
	cout << endl;
	cin >> input;
	while ( input != 'S')
	{
		switch ( input )
		{
		case 'I': Insert();
			break;
		case 'D': Delete();
			break;
		case 'P': Print();
			break;
		case 'S':
	        break;
		default: 
			cout << "Invalid command!" << endl; 
			cout << endl;
			break;
		}
		cin >> input;
	}
	if (input == 'S')
		cout << "Normal Termination of program 2!" << endl;
}

bool Catalog::Insert() 
{
	bool inserted = false;
	Fruit *new2 = new Fruit();
	cin >> *new2;
	inserted = List->Insert( new2 );
	if ( inserted )
	{
	   cout << "Added to list: " << setw(5) << *new2 << endl;
	   cout << endl;
	}
	else
	{
	   cout << "Already in list:   " << *new2 << endl;
	   cout << endl;
	   delete new2;
	   new2 = NULL;
	}
	return inserted;
}

bool Catalog::Delete() 
{
	bool deleted = false;
	Fruit *new3 = new Fruit();
	cin >> *new3;
	deleted = List->Delete( *new3 );
	if ( deleted )
	{
	   cout << "Deleted from list: ";
	   cout << *new3 << endl;
	   cout << endl;
	}
	else
	{
		cout << "Wasn't in list: " << setw(4) << *new3  << endl;
		cout << endl;
	}
    delete new3;
	new3 = NULL;
	return deleted;
}

/*
int main()
{
	Catalog start = Catalog();
	start.Run();
	return 0;
}
*/