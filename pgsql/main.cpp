#if defined(WIN32) || defined(_WIN32)
#pragma comment(lib,"postgres.lib")
#pragma comment(lib,"libecpg.lib")
#pragma comment(lib,"libpgport.lib")
#pragma comment(lib,"libpq.lib")
#endif

#include <cstdlib>
#include "SqlTransaction.h"

char* DBNAME = "library";
char* USER = "pgadmin";
char* PASSWORD = "pgadmin";

int main()
{
	SqlTransaction sql;
	sql.establishConnection(DBNAME, USER, PASSWORD);
	cout << "Connection to database - ";
	if(sql.connectionEstablished() != true)
	{
		cout << "FAILED" << endl;
		sql.closeConnection();
		exit(1);
	}
	cout << "OK" << endl;
	return 0;
}
