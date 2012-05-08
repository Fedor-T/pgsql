#include "pgDriver.h"
#include <iostream> 

pgDriver::pgDriver(PGconn *conn)
{
	connection = conn;
}
PGresult* pgDriver::selectsDataSQL(std::string sql)
{
	PGresult *result = PQexec(connection, sql.c_str());
	if (PQresultStatus(result) != PGRES_TUPLES_OK)
	{
		std::cout<<PQerrorMessage(connection)<<std::endl;
		PQclear(result);
		return 0;
	}else
		return result;
}

PGresult* pgDriver::execSQL(std::string sql)
{
	PGresult *result = PQexec(connection, sql.c_str());
	if (PQresultStatus(result) != PGRES_COMMAND_OK)
    {
		std::cout<<PQerrorMessage(connection)<<std::endl;
		PQclear(result);
		return 0;
    }else
		return result;
}
