#pragma once
#include "pgModel.h"
#include "Book.h"
#include "Author.h"
#include "pgAuthorsBooks.h"

class pgBook : public pgModel<Book>
{
public:
	pgBook(pgDriver* driver);
	pgBook(pgDriver* driver, string table_name);
	vector<Author> authorsFor(Book book);
	void addAuthorToBook(Book book, Author author);
};
