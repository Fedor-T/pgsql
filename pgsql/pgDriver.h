#pragma once

#if defined(WIN32) || defined(_WIN32)
#include <libpq-fe.h>
#include <string>
#else
#include <libpq-fe.h>
#include <string>
#endif

class pgDriver
{
public:
	pgDriver(PGconn *conn);
	PGresult* execSQL(std::string sql);
	PGresult* selectsDataSQL(std::string sql);
private:
	PGconn *connection;
};
