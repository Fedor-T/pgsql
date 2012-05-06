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
	Model(string mName)
	{
		modelName = mName;
	}

	void printColumns()
	{
		cout<<modelName<<"(";
		data::iterator iterator;
		for (iterator = modelData.begin(); iterator != modelData.end(); iterator++)
		{
			cout<<iterator->first<<", ";
		}
		cout<<")"<<endl;
	}
	
	virtual void print()=0;
	string insertColumns()
	{
		strstream result;
		data::iterator iterator = modelData.begin();
		result<< "("<<iterator->first;
		iterator++;
		do
		{
			if(iterator->first != "id")
			{
				result<<", ";
				result<<iterator->first;
			}
		}while(++iterator != modelData.end());
		result<<") "<<ends;
		cout<<result.str();
		return result.str();
	}

	string values(){
		strstream result;
		data::iterator iterator = modelData.begin();
		result<< "VALUES("<<"\'"<<modelData[iterator->first]<<"\'";
		iterator++;
		do
		{
			if(iterator->first != "id")
			{
				result<<", ";
				result<<"\'"<<modelData[iterator->first]<<"\'";
			}
		}while(++iterator != modelData.end());
		result<<") "<<ends;
		cout<<result.str();
		return result.str();
	}
protected:
	data modelData;
	string modelName;
};
