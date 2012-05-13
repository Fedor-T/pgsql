#pragma once
#include "pgModel.h"
#include "Author.h"
	
class pgAuthor : public pgModel<Author>
{
public:
	pgAuthor(pgDriver* driver);
	pgAuthor(pgDriver* driver, string table_name);
	
};
