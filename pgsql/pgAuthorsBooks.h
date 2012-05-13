#pragma once
#include "pgModel.h"
#include "AuthorsBooks.h"

class pgAuthorsBooks : public pgModel<AuthorsBooks>
{
public:
	pgAuthorsBooks(pgDriver* driver);
	pgAuthorsBooks(pgDriver* driver, string table_name);
};
