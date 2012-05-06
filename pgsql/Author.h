#pragma once
#include <iostream>
#include <string>
using namespace std;

class Author
{
public:
	Author(void);
	void print();
	~Author(void);
private:
	int id;
	string firstName;
	string lastName;
	string fatherName;
};
