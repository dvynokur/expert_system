#include "../headers/Calculation.h"

Calculation::Calculation() {} ;
Calculation::~Calculation() {} ;
Calculation::Calculation(Expert_System & ExpSys) : _solved(false) {
	this->FindingAnswers(ExpSys);
}

void		Calculation::FindingAnswers(Expert_System & ExpSys)
{
	std::string		answers = ExpSys.getQueries();
	// std::cout << "answers: " << ExpSys.getQueries() << std::endl;
	// ExpSys.PrintFacts();
	// ExpSys.PrintRules();



	for(char & c : answers)
	{

		// if (this->CheckIsAnswer())
		// 	return ;

		auto i = ExpSys.Rules.begin();


		while (i != ExpSys.Rules.end())
		{
			if ((*i)->getLeftPart().find(c) != std::string::npos)
			{
				// std::cout << "C: " << c << std::endl;
				// std::cout << std::endl << "c: " << c << ", Right part: ";
				ExpSys.SolveRule((*i)->getRightPart());

				// UpdateFacts();
			}
			if ((*i)->getRightPart().find(c) != std::string::npos)
			{

				// std::cout << "C: " << c << std::endl;
				// std::cout << std::endl << "c: " << c << ", Left part: ";

				ExpSys.SolveRule((*i)->getLeftPart());


				// UpdateFacts();
			}
			i++;
		}
	}



	// CheckIsAnswer();
	// for all facts:
	// 	if (ExpSys.FindConnectedFacts())
	// 		SolveRule();
	// 		ExpSys.UpdateFacts();
	// 		if answered
	// 			AssignAnswer();
	// 		no - repeat;
	
	
}

bool		Calculation::CheckIsAnswer(void) {
	return (this->_solved);
}

void		Calculation::AssignAnswer(void) {
	this->_solved = true;
}

