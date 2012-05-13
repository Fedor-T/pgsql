#include "pgBook.h"

pgBook::pgBook(pgDriver *driver):pgModel(driver, "books"){}
pgBook::pgBook(pgDriver *driver, string tname):pgModel(driver, tname){}

vector<Author> pgBook::authorsFor(Book book)
{
	string sql = where("authors", book.authorsCondition());
	PGresult *result = driver->selectsDataSQL(sql);
	data itemAttributes;
	vector<Author> authors;
	int rows = PQntuples(result);
	if(rows)
	{
		for(int j=0;j<rows;j++)
		{
			for (int i=0; i<PQnfields(result); i++)
			{
				itemAttributes[PQfname(result, i)] = PQgetvalue(result, j, i);
			}
			Author item(itemAttributes);
			authors.push_back(item);
		}
		PQclear(result);
	}
	else
	{
		cout<<"Authors don\'t exist!"<<endl;
	}
	return authors;
}

vector<Area> pgBook::areasFor(Book book)
{
	string sql = where("areas", book.areasCondition());
	PGresult *result = driver->selectsDataSQL(sql);
	data itemAttributes;
	vector<Area> areas;
	int rows = PQntuples(result);
	if(rows)
	{
		for(int j=0;j<rows;j++)
		{
			for (int i=0; i<PQnfields(result); i++)
			{
				itemAttributes[PQfname(result, i)] = PQgetvalue(result, j, i);
			}
			Area item(itemAttributes);
			areas.push_back(item);
		}
		PQclear(result);
	}
	else
	{
		cout<<"Areas don\'t exist!"<<endl;
	}
	return areas;
}

void pgBook::addAuthorToBook(Book book, Author author)
{
	pgAuthorsBooks authorsBooksRelation(this->driver);
	data authorBookData;
	authorBookData["author_id"] = author.getId();
	authorBookData["book_id"] = book.getId();
	AuthorsBooks item(authorBookData);
	authorsBooksRelation.create(item);
}

void pgBook::addAreaToBook(Book book, Area area)
{
	pgAreasBooks areasBooksRelation(this->driver);
	data areaBookData;
	areaBookData["area_id"] = area.getId();
	areaBookData["book_id"] = book.getId();
	AreasBooks item(areaBookData);
	areasBooksRelation.create(item);
}
