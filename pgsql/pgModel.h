#pragma once
#include <vector>
#include <string>
#include "pgdriver.h"

using namespace std;

template <class ModelName>
class pgModel
{
public:
	pgModel(pgDriver *pgdriver, char* tname)
	{
		driver = pgdriver;
		tableName = tname;
	}
	~pgModel(void){}

	void push(ModelName item)
	{
		items.push_back(item);
	}

	int count()
	{ 
		return itesm.size();
	}

	ModelName find(int id)
	{
		string sql="SELECT * FROM";
		sql += tableName;
		sql += "WHERE id=";
		sql += id;
		ModelName item;
		return item;
	}
	
	vector<ModelName> items;
	pgDriver *driver;
private:
	string tableName;
};
