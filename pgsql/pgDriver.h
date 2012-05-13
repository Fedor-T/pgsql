#pragma once

#include <libpq-fe.h>
#include <string>

class pgDriver
{
public:
	pgDriver(PGconn *conn);
	PGresult* execSQL(std::string sql);
	PGresult* selectsDataSQL(std::string sql);
private:
	PGconn *connection;
};
