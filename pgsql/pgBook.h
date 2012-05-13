#pragma once
#include "pgmodel.h"
#include "Book.h"
#include "pgAuthor.h"

class pgBook : public pgModel<Book>
{
public:
	pgBook(pgDriver* driver);
	pgBook(pgDriver* driver, string table_name);
};
