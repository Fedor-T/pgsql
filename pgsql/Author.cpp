#include "Author.h"

Author::Author(data attributes): Model("Author")
{
	data::iterator iterator;
	for (iterator = attributes.begin(); iterator != attributes.end(); iterator++)
	{
		modelData[iterator->first] = iterator->second;
	}
}

void Author::print()
{
	if(modelData["id"] == "0") return;
	cout<<setw(5)<<modelData["id"]<<"|"<<setw(14)<<modelData["firstName"]<<"|"<<setw(14)<<modelData["lastName"]<<"|"<<setw(14)<<modelData["fatherName"]<<"|"<<endl;
}

void Author::printHeader()
{
	cout<<setw(6)<<"id: |"<<setw(15)<<"FirstName: |"<<setw(15)<<"LastName: |"<<setw(15)<<"FathrName: |"<<endl;
}