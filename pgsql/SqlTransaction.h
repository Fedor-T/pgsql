#ifndef SQLTRANSACTION_H
#define SQLTRANSACTION_H
#if defined(WIN32) || defined(_WIN32)
#include <libpq-fe.h>
#include <cstring>
#include <iostream>
#else
#include <postgresql/libpq-fe.h>
#include <string.h>
#include <iostream>
#endif
using namespace std;

class SqlTransaction
{
public:
	SqlTransaction(char* dbName, char* password);
	~SqlTransaction();
	int insertData(char* fname, char*lname, char* oname);
	void selectAuthors();
private:
	PGconn *connection;
};

#endif
