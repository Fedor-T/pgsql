#if defined(WIN32) || defined(_WIN32)
#pragma comment(lib,"postgres.lib")
#pragma comment(lib,"libecpg.lib")
#pragma comment(lib,"libpgport.lib")
#pragma comment(lib,"libpq.lib")
#endif

#include <fstream>
#include <cstdlib>
#include "SqlTransaction.h"
#include "configuration.h"

int main()
{
	configuration::data appconfig;
	ifstream cfgfile("config.cfg");
	cfgfile >> appconfig;
	cfgfile.close();

	SqlTransaction sql;
	sql.establishConnection(appconfig["dbname"], appconfig["user"], appconfig["password"]);
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
