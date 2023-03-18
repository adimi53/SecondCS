#pragma once
#include <string>
using std::string;
#define MAX_NAME_LEN 10


class Manager
{
private:
	int id;
	string firstName;
	string lastName;
	int birthYear;

public:
	// c'tor
	Manager();
	Manager(const int& id, const string& name, const string& name2, const int& year);

	// getters
	int getId() const;
	string getFirstName() const;
	string getLastName() const;
	int getBirthYear() const;

	// setters
	void setId(const int& id_num);
	void setFirstName(const string& name);
	void setLastName(const string& name);
	void setBirthYear(const int& year);

	// print
	void print();
};