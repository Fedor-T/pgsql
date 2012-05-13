#pragma once
#include "pgModel.h"
#include "Area.h"

class pgArea : public pgModel<Area>
{
public:
	pgArea(pgDriver* driver);
	pgArea(pgDriver* driver, string table_name);
};
