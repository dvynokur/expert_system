#include "../headers/Expert_System.h"

Expert_System::Expert_System() : _queries("") {};
Expert_System::~Expert_System() {};

bool		Expert_System::IsQueries(void)
{
	if (!(this->_queries.compare("")))
		return 0;
	else
		return 1;
}

void	Expert_System::AddQueries(std::string line)
{
	if (this->IsQueries())
		throw ExceptionExpSys("Input is not valid: More than 1 line with querries");
	this->_queries = line;
}