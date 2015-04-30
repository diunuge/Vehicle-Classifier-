#pragma once

#include <iostream> 

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class DatabaseHandler
{
private:
	//static DatabaseHandler * _singletonDatabase;

	//static const std::string mysqlURL;
	//static const std::string mysqlDatabase;
	//static const std::string mysqlUser;
	//static const std::string mysqlPass;

private:
	sql::Driver * driver;
	sql::Connection * con;
	sql::Statement * stmt;
	sql::ResultSet * res;

public:
	static DatabaseHandler* const getInstance();
	sql::Statement * getStatement();

private:
	DatabaseHandler(void);
};

