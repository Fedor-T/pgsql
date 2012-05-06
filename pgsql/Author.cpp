#include "Author.h"

Author::Author(map<string, string> attributes)
{
	id = atoi(attributes["id"].c_str());
	firstName = attributes["firstname"];
	lastName =  attributes["lastname"];
	fatherName = attributes["fathername"];
}
Author::Author()
{
	id = 0;
}
Author::~Author(void)
{
}
void Author::print()
{
	if(!id) return;
	cout<<setw(5)<<id<<"|"<<setw(14)<<firstName<<"|"<<setw(14)<<lastName<<"|"<<setw(14)<<fatherName<<"|"<<endl;
}

void Author::printHeader()
{
	cout<<setw(6)<<"id: |"<<setw(15)<<"FirstName: |"<<setw(15)<<"LastName: |"<<setw(15)<<"FathrName: |"<<endl;
}