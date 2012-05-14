#pragma once
#include "Model.h"

class Book : public Model
{
public:
	Book(void);
	Book(data attribute);
	string authorsCondition();
	string areasCondition();
	void print();
	void printHeader();
};
