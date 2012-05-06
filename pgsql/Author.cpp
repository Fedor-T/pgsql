#include "Author.h"

Author::Author(data attributes): Model("Author", attributes.size(), atoi(attributes["id"].c_str()), attributes)
{
	firstName = attributes["firstname"];
	lastName =  attributes["lastname"];
	fatherName = attributes["fathername"];
}
Author::Author():Model(0,0){}

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

string Author::insertColumns()
{
	return string("(firstname, lastname, fathername)");
}

string Author::values(){
	strstream result;

	result << "VALUES(";
	result << "\'"<<firstName<<"\',";
	result << "\'"<<lastName<<"\',";
	result << "\'"<<fatherName<<"\'";
	result << ")"<<ends;

	return result.str();
}