#pragma once
#include "model.h"

class Author : public Model
{
public:
	Author(data attributes);
	Author();
	void print();
	static void printHeader();
};
