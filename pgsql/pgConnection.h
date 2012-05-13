#pragma once
#include <iostream>
#include "pgDriver.h"


using namespace std;

class pgConnection
{
public:
	pgConnection(void);
	~pgConnection(void);
	bool connectionEstablished();
	int initDriver();
	pgDriver* getDriver();
private:
	PGconn *connection;
	pgDriver* driver;
};
