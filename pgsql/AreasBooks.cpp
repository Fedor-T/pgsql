#include "AreasBooks.h"

AreasBooks::AreasBooks(data attributes): Model("AreasBooks")
{
	data::iterator iterator;
	for (iterator = attributes.begin(); iterator != attributes.end(); iterator++)
	{
		modelData[iterator->first] = iterator->second;
	}
}
