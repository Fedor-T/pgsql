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
		data itemAttributes;
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

	ModelName last()
	{
		strstream sql;
		sql << "SELECT * FROM ";
		sql << tableName;
		sql << " ORDER BY id desc LIMIT 1;"<<ends;
		PGresult *result = driver->selectsDataSQL(sql.str());
		data itemAttributes;
		if(PQntuples(result))
		{
			for (int i=0; i<PQnfields(result); i++)
			{
				itemAttributes[PQfname(result, i)] = PQgetvalue(result, 0, i);
			}
			PQclear(result);
		}
		ModelName item(itemAttributes);
		return item;
	}
	
	bool create(ModelName item)
	{
		strstream sql;
		sql << "INSERT INTO " << tableName;
		sql << item.insertColumns();
		sql << item.values()<<';'<<ends;
		if(driver->execSQL(sql.str()))
			return true
		else
			return false
		
	}

	bool update(ModelName item)
	{
		//TODO: write
		return false;
	}
	
	bool destroy(int id)
	{
		strstream sql;
		sql<<"DELETE FROM "<< tableName;
		sql<<" WHERE id="<<id<<";"<<ends;
		if(driver->execSQL(sql.str()))
			return true;
		else
			return false;
	}

	vector<ModelName> all()
	{
		if(items.size()) return items;
		strstream sql;
		sql << "SELECT * FROM ";
		sql << tableName;
		sql <<";"<<ends;
		PGresult *result = driver->selectsDataSQL(sql.str());
		data itemAttributes;
		int rows = PQntuples(result);
		if(rows)
		{
			for(int j=0;j<rows;j++)
			{
				for (int i=0; i<PQnfields(result); i++)
				{
					itemAttributes[PQfname(result, i)] = PQgetvalue(result, j, i);
				}
				ModelName item(itemAttributes);
				items.push_back(item);
			}
			PQclear(result);
		}
		else
		{
			cout<<tableName<<" empty table!"<<endl;
		}
		return items;
	}

	vector<ModelName> items;
};
