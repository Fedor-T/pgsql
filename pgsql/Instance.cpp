#include "Instance.h"

Instance::Instance(data attributes): Model("Instance")
{
	data::iterator iterator;
	for (iterator = attributes.begin(); iterator != attributes.end(); iterator++)
	{
		modelData[iterator->first] = iterator->second;
	}
}

void Instance::print()
{
	if(modelData["id"] == "0") return;
	cout<<setw(5)<<modelData["id"]<<"|"<<setw(5)<<modelData["book_id"]<<"|"<<endl;
}

void Instance::printHeader()
{
	cout<<setw(6)<<"id: |"<<setw(5)<<"Book ID: |"<<endl;
}
