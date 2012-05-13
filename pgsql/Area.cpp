#include "Area.h"

Area::Area(data attributes): Model("Area")
{
	data::iterator iterator;
	for (iterator = attributes.begin(); iterator != attributes.end(); iterator++)
	{
		modelData[iterator->first] = iterator->second;
	}
}
