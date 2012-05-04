#include "SqlTransaction.h"


SqlTransaction::SqlTransaction(char* dbName, char* password)
{
	string sql;
	sql+="user=postgres password=";
	sql+=password;
	sql+=" dbname=";
	sql+=dbName;
	sql+=" host=127.0.0.1 port=5432";
	connection = PQconnectdb(sql.c_str());
}	

SqlTransaction::~SqlTransaction()
{
	PQfinish(connection);
}

int SqlTransaction::insertData(char* fname, char*lname, char* oname)
{
	string sql;
	sql.append("INSERT INTO authors VALUES ('1', '");
	sql.append(fname);
	sql.append("', '");
	sql.append(lname);
	sql.append("', '");
	sql.append(oname);
	sql.append("');");
	PGresult *res = PQexec(connection, sql.c_str());
	if(PQresultStatus(res)!= PGRES_COMMAND_OK)
	{
		cout<<"Fail";
		PQclear(res);
		return 0;
	}
	PQclear(res);
	return 1;
}

void SqlTransaction::selectAuthors()
{
	string sql;
	sql.append("SELECT * FROM authors;");
	PGresult *res = PQexec(connection, sql.c_str());
	int row_count = PQntuples(res);
	int	col_count = PQnfields(res);
	for(int i=0; i<row_count;i++)
	{
		for(int j=0; j<col_count;j++)
		{
			string s = PQgetvalue(res, i,j);
			cout<<s.c_str();
		}
		cout<<endl;
	}
}