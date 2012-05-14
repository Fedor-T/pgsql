#include "Book.h"

Book::Book(data attributes): Model("Book")
{
	data::iterator iterator;
	for (iterator = attributes.begin(); iterator != attributes.end(); iterator++)
	{
		modelData[iterator->first] = iterator->second;
	}
}

string Book::authorsCondition()
{
	stringstream condition;
	condition<<" id in (SELECT author_id FROM authors_books WHERE book_id = ";
	condition<<modelData["id"];
	condition<<")"<<ends;
	return condition.str();
}

string Book::areasCondition()
{
	stringstream condition;
	condition<<" id in (SELECT area_id FROM areas_books WHERE book_id = ";
	condition<<modelData["id"];
	condition<<")"<<ends;
	return condition.str();
}

void Book::print()
{
	if(modelData["id"] == "0") return;
	cout<<setw(5)<<modelData["id"]<<"|"
		<<setw(14)<<modelData["isbn"]<<"|"
		<<setw(14)<<modelData["title"]<<"|"
		<<setw(14)<<modelData["publisher"]<<"|"
		<<setw(14)<<modelData["publisher_location"]<<"|"
		<<setw(6)<<modelData["year"]<<"|"
		<<setw(7)<<modelData["pages"]<<"|"
		<<setw(9)<<modelData["count"]<<"|"
		<<setw(9)<<modelData["cost"]<<"|"
	<<endl;
}

void Book::printHeader()
{
	cout<<setw(6)<<"id: |"
		<<setw(16)<<"ISBN: |"
		<<setw(15)<<"Title: |"
		<<setw(15)<<"Publisher: |"
		<<setw(15)<<"Country: |"
		<<setw(5)<<"Year: |"
		<<setw(5)<<"Pages: |"
		<<setw(10)<<"Count: |"
		<<setw(10)<<"Cost: |"
	<<endl;
}
