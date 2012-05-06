#include "pgConnection.h"
#include <fstream>
#include "configuration.h"

pgConnection::pgConnection(void)
{
	configuration::data config;
	ifstream cfgfile("config.cfg");
	cfgfile >> config;
	cfgfile.close();

	string sql;
	sql+="user=";
	sql+=config["user"];
	sql+=" password=";
	sql+=config["password"];
	sql+=" dbname=";
	sql+=config["dbname"];
	sql+=" host=";
	sql+=config["host"];
	sql+=" port=";
	sql+=config["port"];
	connection = PQconnectdb(sql.c_str());
	if(connectionEstablished())
	{
		initDriver();
		cout<<"connection success";
	}
	else{
		cout<<"connection failed";
		exit(1);
	}
}

pgConnection::~pgConnection(void)
{
	if(connectionEstablished())
	{
		PQfinish(connection);	
		cout<<"connection closed";
	}
}

pgDriver* pgConnection::getDriver()
{
	return driver;
}

bool pgConnection::connectionEstablished()
{
	return (PQstatus(connection) == CONNECTION_OK);
}
int pgConnection::initDriver()
{
	driver = new pgDriver(connection);
	if(driver)
		return 1;
	else
		return 0;
}
