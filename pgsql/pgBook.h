#pragma once
#include "pgModel.h"
#include "Book.h"
#include "Author.h"

class pgBook : public pgModel<Book>
{
public:
	pgBook(pgDriver* driver);
	pgBook(pgDriver* driver, string table_name);
	vector<Author> authorsFor(Book book);
};
