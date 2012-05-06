#pragma once
#include <vector>
#include <map>
#include <string>
#include <strstream>
#include "pgdriver.h"
using namespace std;

template <class ModelName>
class pgModel
{
	string tableName;
	pgDriver *driver;
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
		strstream sql;
		sql << "SELECT * FROM ";
		sql << tableName;
		sql << " WHERE id=";
		sql << id <<";"<<ends;
		PGresult *result = driver->selectsDataSQL(sql.str());
		map<string, string> itemAttributes;
		if(PQntuples(result))
		{
			for (int i=0; i<PQnfields(result); i++)
			{
				itemAttributes[PQfname(result, i)] = PQgetvalue(result, 0, i);
			}
			PQclear(result);
		}
		else
		{
			cout<<tableName<<" with id="<<id<<" not found!"<<endl;
			itemAttributes["id"] = '\0';
		}
		ModelName item(itemAttributes);
		return item;
	}

	vector<ModelName> items;
};
