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
	Author::printHeader();
	author.last().printColumns();
	data a;
	//test data
	a["firstname"] = "test";
	a["lastname"] = "aaaa";
	a["fathername"] = "bbbb";

	author.find(4).print();
	return 0;
}
