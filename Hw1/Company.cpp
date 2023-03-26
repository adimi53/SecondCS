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
void Company::sortShops(Shop* shops, const int size, const bool byName) // sort the shops array by given parameter
{
    Shop temp;
    int i, j;

    for (i = 0; i < size - 1; i++) // sort the array using bubble sort
    {
        for (j = i + 1; j < size; j++)
        {
            if (byName)
            {
                if (shops[i].getName() > shops[j].getName())
                {
                    temp = shops[i]; // swap 
                    shops[i] = shops[j];
                    shops[j] = temp;
                }
            }
            else
            {
                if (shops[i].getClosedDay() > shops[j].getClosedDay())
                {
                    temp = shops[i]; // swap 
                    shops[i] = shops[j];
                    shops[j] = temp;
                }
            }
        }
    }
}

void Company::printShopsByDay() // print shops by closed day order
{
    if (!shopsNumber) 
    {
        cout << "There are no shops in this company.\n"; // no shops
        return;
    }
    
    cout << "There are " << shopsNumber << " shops in this company. The shops details sorted by day are:\n";
    sortShops(shops, shopsNumber, false); // sort the shops array by day
    for (int i = 0; i < shopsNumber; i++) 
    {
        cout << "Shop #" << i + 1 << " :\n";
        shops[i].print();
        cout << "\n";
    }
}

void Company::printShopsByName() // print shops by lexicographic order of names
{
    if (!shopsNumber) 
    {
        cout << "There are no shops in this company.\n"; // no shops
        return;
    }
    
    cout << "There are " << shopsNumber << " shops in this company. The shops details sorted by name are:\n";
    sortShops(shops, shopsNumber, true); // sort the shops array by name
    for (int i = 0; i < shopsNumber; i++) 
    {
        cout << "Shop #" << i + 1 << " :\n";
        shops[i].print();
        cout << "\n";
    }
}
