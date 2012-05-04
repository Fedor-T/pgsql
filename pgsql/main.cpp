#pragma comment(lib,"postgres.lib")
#pragma comment(lib,"libecpg.lib")
#pragma comment(lib,"libpgport.lib")
#pragma comment(lib,"libpq.lib")

#include "SqlTransaction.h"

void main()
{
	SqlTransaction sql("library", "12345");
	sql.selectAuthors();
}
