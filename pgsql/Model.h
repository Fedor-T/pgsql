#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <strstream>
#include <map>
using namespace std;

struct data: map<string, string>{};

class Model
{
public:
	Model(string mName, int col ,int _id, data attributes)
	{
		columns = col;
		columnNames = new string[col];
		map<string, string>::iterator iter;
		int i=0;
		for (iter = attributes.begin(); iter != attributes.end(); iter++)
		{
			columnNames[i++] = iter->first;
		}
		modelName = mName;
		id = _id;
	}
	Model(int col ,int _id)
	{
		columns = col;
		id = _id;
	}

	void printColumns()
	{
		cout<<modelName<<"(";
		for(int i=0;i<columns;i++)
			cout<<columnNames[i]<<((i+1 != columns)?", ":"");
		cout<<")"<<endl;
	}
	
	virtual void print()=0;
	virtual string insertColumns() = 0;
	virtual string values() = 0;
protected:
	int id;
	int columns;
	string *columnNames;
	string modelName;
};
