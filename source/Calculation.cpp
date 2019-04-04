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
			if ((*i)->getLeftPart().find(c) != std::string::npos || 
				(*i)->getRightPart().find(c) != std::string::npos)
			{
				std::cout << "C: " << c << std::endl;
				ExpSys.SolveRule(*i);
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

