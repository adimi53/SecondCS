#include "Company.h"
#include <iostream>
using std::cout;

// -------------------------------------------------------c'tor 
Company::Company() : name("~"), shops(), shopsNumber(0) {};

Company::Company(const string& name) : name(name), shops(), shopsNumber(0) {
	if (size(name) > MAX_NAME_LEN)
	{
		cout << "Company name legnth is too long\n";
		this->name = "~";
	}
}

// -------------------------------------------------------getters
string Company::getName() const
{
	return name;
}

int Company::getShopsNumeber() const
{
	return shopsNumber;
}

// -------------------------------------------------------setters
void Company::setName(const string& name)
{
	if (size(name) > MAX_NAME_LEN)
	{
		cout << "Company name legnth is too long\n";
		this->name = "~";
	}
	else this->name = name;
}

// --------------------------------------------------------add shop
void Company::addShop(const Shop& shop)
{
	if (shopsNumber >= MAX_SHOPS_NUMBER)
	{
		cout << "There is no place for new shops!\n";
	}
	else
	{
		shops[shopsNumber++] = shop;
	}
}

// ---------------------------------------------------------help funcs
void Company::sortByName(Shop* shops, const int size)
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

void Company::sortByDay(Shop* shops, const int size)
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
void Company::printShopsByDay()
{
	if (!shopsNumber) cout << "There are no shops in this company.\n"; // no shops
	else if (shopsNumber > 1)
	{
		cout << "There are " << shopsNumber << " shops in this company. The shops details are :\n";
		sortByDay(shops, shopsNumber); // help fucn
	}
	else // only 1 shop
	{
		cout << "There is 1 shop in this company. The shops details are : \n";
		cout << "Shop #1 : \n";
		shops[0].print();
	}
}

void Company::printShopsByName()
{
	if (!shopsNumber) cout << "There are no shops in this company.\n"; // no shops
	else if (shopsNumber > 1)
	{
		cout << "There are " << shopsNumber << " shops in this company. The shops details are :\n";
		sortByName(shops, shopsNumber); // help func
	}
	else // only 1 shop 
	{
		cout << "There is 1 shop in this company. The shops details are : \n";
		cout << "Shop #1 : \n";
		shops[0].print();
	}
}