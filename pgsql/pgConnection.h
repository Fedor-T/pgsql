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
	/*void establishConnection(char* dbName, char* user, char* password, char* host = "127.0.0.1", char* port = "5432");
	int connectionEstablished();
	void closeConnection();
	int insertData(char* fname, char*lname, char* oname);
	void selectAuthors();*/
private:
	PGconn *connection;
	pgDriver* driver;
};
