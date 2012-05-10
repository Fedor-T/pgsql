#include <cstdlib>
#if defined(WIN32) || defined(_WIN32)
	#pragma comment(lib, "pgsql.lib")
#endif
#include "activepg.h"
int main()
{
	pgConnection dbConnecion;
	pgAuthor author(dbConnecion.getDriver());
	
	data a;
	//test data
	vector<Author> authors = author.all();
	vector<Author>::iterator iterator;
	authors[0].printHeader();
	for( iterator = authors.begin(); iterator != authors.end(); iterator++)
		iterator->print();
	a["firstname"] = "ttttttttt";
	a["lastname"] = "ffffffff";
	a["fathername"] = "ddddddddd";
	a["id"] = "2";
	author.create(Author(a));

	return 0;
}
