#include "../headers/Reading.h"

Reading::Reading() {};
Reading::~Reading() {};

Reading::Reading(int argc, char **argv)
{
	auto		*ExpSys = new(Expert_System);
	// auto		*Calc = new(Calculation);
	// size_t		counter = 0;
	size_t		i = 0;

	if (argc == 2)
	{
		std::fstream		file(argv[1]);
		if (file)
		{
			while (std::getline(file, this->line)) {
				Checker::CheckLine(this->line, *ExpSys);
			}
			ExpSys->AddAllFacts();
			ExpSys->UpdateInitStatus();
			ExpSys->AddQueriesToFacts();

			// std::cout << "Facts: " << std::endl;
			// ExpSys->PrintFacts();
			// ExpSys->PrintRules();

			while (i < ExpSys->getQueries().length())
			{
				if (ExpSys->FindingAnswers(ExpSys->getQueries()[i]))
					i = 0;
				i++;
			}

			// for (int i = 0; i < ExpSys->getQueries(); ++i)
			// {
			// 	if (ExpSys->FindingAnswers())
			// }


			// for (const char & c : ExpSys->getQueries())
			// 	ExpSys->FindingAnswers(c);

			// for(std::string::iterator i = ExpSys->getQueries().begin(); i != ExpSys->getQueries().end(); ++i)
			// {
			// 	std::cout << "in reading " << std::endl;
			// 	if (ExpSys->FindingAnswers(*i))
			// 		i = ExpSys->getQueries().begin();
			// }

			ExpSys->PrintResult();
		}
		else
			throw ExceptionExpSys("There must be a file");
	}
	else
		throw ExceptionExpSys("Program must have a file as an argument!");
}