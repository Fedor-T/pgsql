#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <cstdlib>
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
		data::iterator iterator = modelData.begin();
		cout<<iterator->first;
		iterator++;
		do
		{
			if(iterator->first != "id")
			{
				cout<<", ";
				cout<<iterator->first;
			}
		}while(++iterator != modelData.end());
		cout<<")"<<endl;
	}

	virtual void print()
	{
		data::iterator iterator = modelData.begin();
		cout<<setw(15)<<modelData[iterator->first];
		iterator++;
		do
		{
			cout<<", ";
			cout<<setw(15)<<modelData[iterator->first];
		}while(++iterator != modelData.end());
		cout<<endl;
	}
	virtual void printHeader()
	{
		data::iterator iterator = modelData.begin();
		cout<<setw(15)<<iterator->first;
		iterator++;
		do
		{
			cout<<", ";
			cout<<setw(15)<<iterator->first;
		}while(++iterator != modelData.end());
		cout<<endl;
	}

	string insertColumns()
	{
		stringstream result;
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
		result<<") ";
		return result.str();
	}

	string values(){
		stringstream result;
		data::iterator iterator = modelData.begin();
		result<< "("<<"\'"<<modelData[iterator->first]<<"\'";
		iterator++;
		do
		{
			if(iterator->first != "id")
			{
				result<<", ";
				result<<"\'"<<modelData[iterator->first]<<"\'";
			}
		}while(++iterator != modelData.end());
		result<<") ";
		return result.str();
	}

	string updateValues()
	{
		stringstream result;
		result<< insertColumns()<<"=";
		result<< values()<<ends;
		return result.str();
	}
	string getId()
	{
		return modelData["id"];
	}

	void setId(string id)
	{
	  modelData["id"] = id;
	}

	bool isEmpty()
	{
		return (modelData.size() ? false : true);
	}

protected:
	data modelData;
	string modelName;
};
