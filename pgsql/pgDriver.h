#pragma once

#if defined(WIN32) || defined(_WIN32)
#include <libpq-fe.h>
#include <string>
#else
#include <postgresql/libpq-fe.h>
#include <string.h>
#endif

class pgDriver
{
public:
	pgDriver(PGconn *conn);
	PGresult* execSQL(std::string sql);
	~pgDriver(void);
private:
	PGconn *connection;
};
