#include <cstdlib>
#include "activepg.h"

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
