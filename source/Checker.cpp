#include "../headers/Checker.h"

Checker::Checker() {};
Checker::~Checker() {};

bool		Checker::CheckLine(std::string line, Expert_System & ExpSys)
{
	line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());

	std::string line_without_comment = line.substr(0, line.find("#"));

	if (line_without_comment[0] == '?')
		ExpSys.AddQueries(line_without_comment);


	return (1);
}