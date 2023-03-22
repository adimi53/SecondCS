#include "Company.h"
#include <iostream>
using std::cout;

// -------------------------------------------------------c'tor 
Company::Company() : name("~"), shops(), shopsNumber(0) {}; // default values 

// input values if valid
Company::Company(const string& name) : name(name), shops(), shopsNumber(0) {
	if (size(name) > MAX_NAME_LEN) // check name length
	{
		cout << "Company name legnth is too long\n";
		this->name = "~"; // too long- default value
	}
}

// -------------------------------------------------------getters
string Company::getName() const // get name 
{
	return name;
}

const Shop* Company::getShops() const // get pointer to shops array 
{
	return shops;
}

int Company::getShopsNumeber() const // get shops number
{
	return shopsNumber;
}

// -------------------------------------------------------setters
void Company::setName(const string& name) // set name if not too long 
{
	if (size(name) > MAX_NAME_LEN) // check name length 
	{
		cout << "Company name legnth is too long\n";
		this->name = "~"; // too long- default value 
	}
	else this->name = name; // length is ok
}

// --------------------------------------------------------add shop
void Company::addShop(const Shop& shop) // add shop
{
	if (shopsNumber >= MAX_SHOPS_NUMBER) // check if theres space for more shops
	{
		cout << "There is no place for new shops!\n"; // if company is full cant add a shop
	}
	else // there is space 
	{
		shops[shopsNumber++] = shop;
	}
}

// ---------------------------------------------------------help funcs
void Company::sortByName(Shop* shops, const int size) // sort the shops array by lexicographic order of shops names 
{
	Shop temp;
	int i, j;

	for (i = 0; i < size - 1; i++) // sort the array in a lexicographic order using bubble sort
	{
		for (j = i + 1; j < size; j++)
		{
			if (shops[i].getName() > shops[j].getName())
			{
				temp = shops[i]; // swap 
				shops[i] = shops[j];
				shops[j] = temp;
			}
		}
	}
	for (i = 0; i < size; i++) // print the shops
	{
		cout << "Shop #" << i + 1 << " :\n";
		shops[i].print();
		cout << "\n";
	}
}

void Company::sortByDay(Shop* shops, const int size) // sort the shops array by shops closed day 
{
	Shop temp;
	int i, j;

	for (i = 0; i < size - 1; i++) // sort the array by closed day using bubble sort
	{
		for (j = i + 1; j < size; j++)
		{
			if (shops[i].getClosedDay() > shops[j].getClosedDay())
			{
				temp = shops[i]; // swap
				shops[i] = shops[j];
				shops[j] = temp;
			}
		}
	}

	for (i = 0; i < size; i++) // print the shops
	{
		cout << "Shop #" << i + 1 << " :\n";
		shops[i].print();
		cout << "\n";
	}
}

// ---------------------------------------------------------print
void Company::printShopsByDay() // print shops by closed day order
{
	if (!shopsNumber) cout << "There are no shops in this company.\n"; // no shops
	else if (shopsNumber > 1) // several shops
	{
		cout << "There are " << shopsNumber << " shops in this company. The shops details are :\n";
		sortByDay(shops, shopsNumber); // help fucn that sorts and prints the shops
	}
	else // only 1 shop, prints it
	{
		cout << "There is 1 shop in this company. The shops details are : \n";
		cout << "Shop #1 : \n";
		shops[0].print();
	}
}

void Company::printShopsByName() // print shops by lexicographic order of names 
{
	if (!shopsNumber) cout << "There are no shops in this company.\n"; // no shops
	else if (shopsNumber > 1) // several shops 
	{
		cout << "There are " << shopsNumber << " shops in this company. The shops details are :\n";
		sortByName(shops, shopsNumber); // help func that sorts and prints the shops
	}
	else // only 1 shop, print it
	{
		cout << "There is 1 shop in this company. The shops details are : \n";
		cout << "Shop #1 : \n";
		shops[0].print();
	}
}