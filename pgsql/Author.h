#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

class Author
{
public:
	Author(map<string, string> attributes);
	Author();
	void print();
	static void printHeader();
	~Author(void);
private:
	int id;
	string firstName;
	string lastName;
	string fatherName;
};
