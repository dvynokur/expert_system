#include "../headers/Reading.h"

Reading::Reading() {};
Reading::~Reading() {};

Reading::Reading(int argc, char **argv)
{
	auto		*ExpSys = new(Expert_System);

	if (argc == 2)
	{
		std::fstream		file(argv[1]);
		if (file)
		{
			std::cout << "there is a file" << std::endl;
			while (std::getline(file, this->line))
			{
				Checker::CheckLine(this->line, *ExpSys);
				std::cout << "another line" << std::endl;
			}
		}
		else
			throw ExceptionExpSys("There must be a file");
	}
	else
		throw ExceptionExpSys("Program must have a file as an argument!");
}