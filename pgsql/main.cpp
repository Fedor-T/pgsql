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
	
	data a;
	//test data
	a["firstname"] = "ttttttttt";
	a["lastname"] = "ffffffff";
	a["fathername"] = "ddddddddd";
	a["id"] = "2";
	author.create(Author(a));

	return 0;
}
