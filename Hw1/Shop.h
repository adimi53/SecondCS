#pragma once
#include "Manager.h"

enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

class Shop
{
private:
	Manager manager;
	string name;
	Day closedDay;
	bool isOnline;

public:
	// c'tor
	Shop();
	Shop(const Manager& manager, const string& name, const Day& day, const bool& online);

	//getters 
	Manager getManager() const;
	string getName() const;
	Day getClosedDay() const;
	bool getIsOnline() const;

	//setters 
	void setManager(const Manager& manager);
	void setName(const string& name);
	void setClosedDay(const Day& day);
	void setIsOnline(const bool& state);

	//print 
	void print();
};