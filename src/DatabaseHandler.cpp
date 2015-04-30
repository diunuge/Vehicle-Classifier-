#include "stdafx.h"
#include "DatabaseHandler.h"

DatabaseHandler* _singletonDatabase = NULL;

const std::string mysqlURL = "http://192.168.137.2:3306";
const std::string mysqlUser = "root";
const std::string mysqlPass = "mysql";
const std::string mysqlDatabase = "finch";

DatabaseHandler::DatabaseHandler(void)
{
	try
	{
		driver = get_driver_instance();
		con = driver->connect(mysqlURL, mysqlUser, mysqlPass);
		con->setSchema(mysqlDatabase);
	}
	catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
}

DatabaseHandler* const DatabaseHandler::getInstance()
{
	if(!_singletonDatabase)
	{
		_singletonDatabase = new DatabaseHandler();
	}

	return _singletonDatabase;
}

sql::Statement * DatabaseHandler::getStatement()
{
	try
	{
		stmt = con->createStatement();
	}
	catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}

	return stmt;
}
