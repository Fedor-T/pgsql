#include <cstdlib>
#if defined(WIN32) || defined(_WIN32)
#pragma comment(lib, "pgsql.lib")
#endif
#include "activepg.h"

void printMenu();
void addBook(pgBook &bookModel);
void list(pgBook &bookModel);
void remove();

int main()
{
	pgConnection bdConnection;
	pgBook bookModel(bdConnection.getDriver());
	pgAuthor Author(bdConnection.getDriver());

	int choice=1;
	while(choice)
	{
		  printMenu();
		  cin>>choice;
		  cin.clear();
		  cin.ignore(cin.rdbuf()->in_avail());
		  switch(choice)
		  {
				case 1:
				  list(bookModel);
				  break;
				case 2:
				  addBook(bookModel);
				  break;
				case 3:
				  cout<<"remove";
				  break;
				case 0:
				  cout<<"exit";
				  break;
		  }
	}
	return 0;
}

void printMenu()
{
	cout<<endl;
	for(int i=0;i<80; i++)
		  cout<<"_";
	cout<<endl;
	cout<<"1: Book list."<<endl;
	cout<<"2: Add book."<<endl;
	cout<<"3: Remov book."<<endl;
	cout<<"0: Exit."<<endl<<endl;
}

void list(pgBook &bookModel)
{
	vector<Book> books = bookModel.all();
	vector<Book>::iterator i_book;
	if(books.size())
		books[0].printHeader();
	for( i_book = books.begin(); i_book != books.end(); i_book++)
		i_book->print();
}

void addBook(pgBook &bookModel)
{
	vector<string> fields = bookModel.getFields();
	data a;
	string tmp;
	vector<string>::iterator iter;
	getline(cin, tmp);
	for(iter = fields.begin(); iter != fields.end(); iter++)
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout<<"Type "<<iter->c_str()<<": ";
		getline(cin, tmp);
		a[iter->c_str()] = tmp;
	}
	Book book(a);
	bookModel.create(book);
}
