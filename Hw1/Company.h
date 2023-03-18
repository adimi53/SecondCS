#pragma once
#include "Shop.h"
#define MAX_SHOPS_NUMBER 10

class Company
{
private:
	string name;
	Shop* shops;
	int shopsNumber;

	//help functions
	void sortByName(Shop* shops, const int size);
	void sortByDay(Shop* shops, const int size);

public:
	// c'tor 
	Company(); 
	Company(const string& name);
	~Company();

	// getters
	string getName() const;
	Shop* getShops() const;
	int getShopsNumeber() const;

	// setters
	void setName(const string& name);

	void addShop(const Shop& shop);
	void printShopsByName();
	void printShopsByDay();
};
