#pragma once
#include "pgModel.h"
#include "Book.h"
#include "Author.h"
#include "Area.h"
#include "pgAuthorsBooks.h"
#include "pgAreasBooks.h"

class pgBook : public pgModel<Book>
{
public:
	pgBook(pgDriver* driver);
	pgBook(pgDriver* driver, string table_name);
	vector<Author> authorsFor(Book book);
	vector<Area> areasFor(Book book);
	void addAuthorToBook(Book book, Author author);
	void addAreaToBook(Book book, Area area);
};
