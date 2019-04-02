#include "../headers/Reading.h"

Reading::Reading() {};
Reading::~Reading() {};

Reading::Reading(int argc, char **argv)
{
	auto		*ExpSys = new(Expert_System);
	Rule		*TempRule;

	if (argc == 2)
	{
		std::fstream		file(argv[1]);
		if (file)
		{
			while (std::getline(file, this->line))
			{
				Checker::CheckLine(this->line, *ExpSys);
				
			}
			ExpSys->PrintRules();
		}
		else
			throw ExceptionExpSys("There must be a file");
	}
	else
		throw ExceptionExpSys("Program must have a file as an argument!");
}