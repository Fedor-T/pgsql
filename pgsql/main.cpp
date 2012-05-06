#if defined(WIN32) || defined(_WIN32)
#pragma comment(lib,"postgres.lib")
#pragma comment(lib,"libecpg.lib")
#pragma comment(lib,"libpgport.lib")
#pragma comment(lib,"libpq.lib")
#endif

#include <cstdlib>
#include "pgConnection.h"
#include "pgAuthor.h"
int main()
{
	pgConnection dbConnecion;
	pgAuthor author(dbConnecion.getDriver());
	int i = 1;
	author.find(i).print();
	return 0;
}
