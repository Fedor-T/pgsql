#ifndef SQLTRANSACTION_H
#define SQLTRANSACTION_H
#if defined(WIN32) || defined(_WIN32)
#include <libpq-fe.h>
#include <cstring>
#else
#include <postgresql/libpq-fe.h>
#include <string.h>
#endif
#include <iostream>
using namespace std;

class SqlTransaction
{
public:
	SqlTransaction();
	~SqlTransaction();
	void establishConnection(char* dbName, char* user, char* password, char* host = "127.0.0.1", char* port = "5432");
	int connectionEstablished();
	void closeConnection();
	int insertData(char* fname, char*lname, char* oname);
	void selectAuthors();
private:
	PGconn *connection;
};

#endif
