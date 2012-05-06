#include "pgDriver.h"

pgDriver::pgDriver(PGconn *conn)
{
	connection = conn;
}
PGresult* pgDriver::execSQL(std::string sql)
{
	return PQexec(connection, sql.c_str());
}
pgDriver::~pgDriver(void)
{
}
