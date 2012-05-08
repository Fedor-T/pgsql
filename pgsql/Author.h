#pragma once
#include "Model.h"

class Author : public Model
{
public:
	Author(data attributes);
	Author();
	void print();
	void printHeader();
};
