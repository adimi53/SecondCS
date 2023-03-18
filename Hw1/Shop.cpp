#include "Shop.h"
#include <iostream>
using std::cout;

// -------------------------------------------------------c'tor
Shop::Shop() : manager(), name("~"), closedDay(Sunday), isOnline(0) {};
Shop::Shop(const Manager& manager, const string& name, const Day& day, const bool& online) : manager(manager), name(name), closedDay(day), isOnline(online) {
	if (size(name) > MAX_NAME_LEN)
	{
		cout << "Shop name legnth is too long\n";
		this->name = "~";
	}
}

// -------------------------------------------------------getters
Manager Shop::getManager() const
{
	return manager;
}

string Shop::getName() const
{
	return name;
}

Day Shop::getClosedDay() const
{
	return closedDay;
}

bool Shop::getIsOnline() const
{
	return isOnline;
}

// -------------------------------------------------------setters
void Shop::setManager(const Manager& manager)
{
	this->manager = manager;
}

void Shop::setName(const string& name)
{
	if (size(name) > MAX_NAME_LEN)
	{
		cout << "Shop name legnth is too long\n";
		this->name = "~";
	}
	else this->name = name;
}

void Shop::setClosedDay(const Day& day)
{
	closedDay = day;
}

void Shop::setIsOnline(const bool& state)
{
	isOnline = state;
}

// --------------------------------------------------------print
void Shop::print()
{
	cout << "Printing shop:\n";
	manager.print();
	cout << "Name : " << name << "\n";
	switch (closedDay) // we want to print the actual day and not the value
	{
	case Sunday:
		cout << "Closed day : Sunday\n"; break;
	case Monday:
		cout << "Closed day : Monday\n"; break;
	case Tuesday:
		cout << "Closed day : Tuesday\n"; break;
	case Wednesday:
		cout << "Closed day : Wednesday\n"; break;
	case Thursday:
		cout << "Closed day : Thursday\n"; break;
	case Friday:
		cout << "Closed day : Friday\n"; break;
	case Saturday:
		cout << "Closed day : Saturday\n"; break;
	}
	cout << "Is Online : " << (isOnline ? "True" : "False") << "\n";
}