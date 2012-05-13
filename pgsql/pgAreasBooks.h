#pragma once
#include "pgModel.h"
#include "AreasBooks.h"

class pgAreasBooks : public pgModel<AreasBooks>
{
public:
	pgAreasBooks(pgDriver* driver);
	pgAreasBooks(pgDriver* driver, string table_name);
};
