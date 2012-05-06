#include "SqlTransaction.h"

SqlTransaction::SqlTransaction()
{

}

SqlTransaction::~SqlTransaction()
{
	if(connectionEstablished()) closeConnection();
}

void SqlTransaction::establishConnection(string dbName, string user, string password, string host, string port)
{
	string sql;
	sql+="user=";
	sql+=user;
	sql+=" password=";
	sql+=password;
	sql+=" dbname=";
	sql+=dbName;
	sql+=" host=";
	sql+=host;
	sql+=" port=";
	sql+=port;
	connection = PQconnectdb(sql.c_str());
}

int SqlTransaction::connectionEstablished()
{
	return (PQstatus(connection) == CONNECTION_OK);
}

void SqlTransaction::closeConnection()
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
	int col_count = PQnfields(res);
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
