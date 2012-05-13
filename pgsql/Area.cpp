#include "Area.h"

Area::Area(data attributes): Model("Area")
{
	data::iterator iterator;
	for (iterator = attributes.begin(); iterator != attributes.end(); iterator++)
	{
		modelData[iterator->first] = iterator->second;
	}
}

void Area::print()
{
	if(modelData["id"] == "0") return;
	cout<<setw(5)<<modelData["id"]<<"|"<<setw(59)<<modelData["name"]<<"|"<<endl;
}

void Area::printHeader()
{
	cout<<setw(6)<<"id: |"<<setw(60)<<"Name: |"<<endl;
}
