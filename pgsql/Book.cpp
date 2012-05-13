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
