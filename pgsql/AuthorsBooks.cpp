#include "AuthorsBooks.h"

AuthorsBooks::AuthorsBooks(data attributes): Model("AuthorsBooks")
{
	data::iterator iterator;
	for (iterator = attributes.begin(); iterator != attributes.end(); iterator++)
	{
		modelData[iterator->first] = iterator->second;
	}
}