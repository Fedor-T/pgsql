#pragma once
#include "pgModel.h"
#include "Instance.h"
	
class pgInstance : public pgModel<Instance>
{
public:
	pgInstance(pgDriver* driver);
	pgInstance(pgDriver* driver, string table_name);
	
};
