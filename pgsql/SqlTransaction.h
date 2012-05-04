#include <libpq-fe.h>
#include <cstring>
#include <iostream>
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