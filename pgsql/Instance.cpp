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
	cout<<setw(5)<<modelData["id"]<<"|"<<setw(9)<<modelData["book_id"]<<"|"<<setw(19)<<modelData["inventory_number"]<<"|"<<setw(11)<<modelData["is_avail"]<<"|"<<setw(14)<<modelData["position"]<<"|"<<endl;
}

void Instance::printHeader()
{
	cout<<setw(6)<<"id: |"<<setw(9)<<"Book ID: |"<<setw(20)<<"Inventory number: |"<<setw(12)<<"is avail: |"<<setw(11)<<"Position: |"<<endl;
}
