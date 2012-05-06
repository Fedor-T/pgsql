#if defined(WIN32) || defined(_WIN32)
#pragma comment(lib,"postgres.lib")
#pragma comment(lib,"libecpg.lib")
#pragma comment(lib,"libpgport.lib")
#pragma comment(lib,"libpq.lib")
#endif

#include "SqlTransaction.h"

int main()
{
	SqlTransaction sql("library", "12345");
	sql.selectAuthors();
	return 0;
}
