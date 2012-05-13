#include "pgConnection.h"
#include <fstream>
#include <cstdlib>
#include "configuration.h"

pgConnection::pgConnection(void)
{
	configuration::data config;
	ifstream cfgfile("./config.cfg");
	if(!cfgfile)
	{
	  cout<<"Load config fail, check file config.cfg or run app from bin catalog pwd-> $user/$path/pgsql/bin"<<endl;
	  exit(1);
	}
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
		cout<<"connection success"<<endl;
	}
	else{
		cout<<"connection failed"<<endl;
		exit(1);
	}
}

pgConnection::~pgConnection(void)
{
	if(connectionEstablished())
	{
		PQfinish(connection);
		cout<<"connection closed"<<endl;
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
	return (driver = new pgDriver(connection))? 1 : 0;
}
