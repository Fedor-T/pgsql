#pragma once
#include "pgmodel.h"
#include "author.h"
	
class pgAuthor : public pgModel<Author>
{
public:
	pgAuthor(pgDriver* driver);
	pgAuthor(pgDriver* driver, char* table_name);
	~pgAuthor(void);
};
