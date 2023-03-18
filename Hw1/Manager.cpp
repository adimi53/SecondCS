#include "Manager.h"
#include <iostream>
using std::cout;

// -------------------------------------------------------c'tor
Manager::Manager() : id(0), firstName("~"), lastName("~"), birthYear(0) {};
Manager::Manager(const int& id, const string& name, const string& name2, const int& year) : id(id), firstName(name), lastName(name2), birthYear(year) {
	if (size(name) > MAX_NAME_LEN)
	{
		cout << "Manager first name legnth is too long\n";
		firstName = "~";
	}
	if (size(name2) > MAX_NAME_LEN)
	{
		cout << "Manager last name legnth is too long\n";
		lastName = "~";
	}
}

// -------------------------------------------------------getters
int Manager::getId() const
{
	return id;
}

string Manager::getFirstName() const
{
	return firstName;
}

string Manager::getLastName() const
{
	return lastName;
}

int Manager::getBirthYear() const
{
	return birthYear;
}

// -------------------------------------------------------setters
void Manager::setId(const int& id_num)
{
	id = id_num;
}

void Manager::setFirstName(const string& name)
{
	if (size(name) > MAX_NAME_LEN)
	{
		cout << "Manager first name legnth is too long\n";
		firstName = "~";
	}
	else firstName = name;
}

void Manager::setLastName(const string& name)
{
	if (size(name) > MAX_NAME_LEN)
	{
		cout << "Manager last name legnth is too long\n";
		lastName = "~";
	}
	else lastName = name;
}

void Manager::setBirthYear(const int& year)
{
	birthYear = year;
}

// -----------------------------------------------------print
void Manager::print()
{
	cout << "Printing manager:\n";
	cout << "Id : " << id << "\n";
	cout << "First name : " << firstName << "\n";
	cout << "Last name : " << lastName << "\n";
	cout << "Birth year : " << birthYear << "\n";
}
