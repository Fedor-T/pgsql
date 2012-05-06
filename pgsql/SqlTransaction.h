#ifndef SQLTRANSACTION_H
#define SQLTRANSACTION_H
#if defined(WIN32) || defined(_WIN32)
#include <libpq-fe.h>
#else
#include <postgresql/libpq-fe.h>
#endif

#include <cstring>
#include <iostream>
using namespace std;

class SqlTransaction
{
public:
	SqlTransaction();
	~SqlTransaction();
	void establishConnection(string dbName, string user, string password, string host = "127.0.0.1", string port = "5432");
	int connectionEstablished();
	void closeConnection();
	int insertData(char* fname, char*lname, char* oname);
	void selectAuthors();
private:
	PGconn *connection;
};

#endif
