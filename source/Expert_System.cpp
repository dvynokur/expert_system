#include "../headers/Expert_System.h"

Expert_System::Expert_System() : _queries(""), _init_facts("") {};
Expert_System::~Expert_System() {};

bool		Expert_System::IsQueries(void)
{
	if (!(this->_queries.compare("")))
		return 0;
	else
		return 1;
}

bool		Expert_System::IsInitFacts(void)
{
	if (!(this->_init_facts.compare("")))
		return 0;
	else
		return 1;
}

void	Expert_System::AddQueries(std::string line)
{
	if (this->IsQueries())
		throw ExceptionExpSys("Input is not valid: More than 1 line with queries");

	if (!std::regex_match(line, std::regex("^([A-Z]+)$")))
		throw ExceptionExpSys("Input is not valid: A fact can be any uppercase alphabetical character");

	this->_queries = line;
	std::cout << "queries: " << this->_queries << std::endl;
}

void	Expert_System::AddInitFacts(std::string line)
{
	if (this->IsInitFacts())
		throw ExceptionExpSys("Input is not valid: More than 1 line with initial facts");

	if (!std::regex_match(line, std::regex("^([A-Z]+)$")))
		throw ExceptionExpSys("Input is not valid: A fact can be any uppercase alphabetical character");

	this->_init_facts = line;
	std::cout << "init facts: " << this->_init_facts << std::endl;

}

bool	Expert_System::FindFacts(char name)
{
	if (this->Facts.empty())
		return (0);
	auto i = this->Facts.begin();
	while (i != this->Facts.end())
	{
		if ((*i)->getName() == name)
			return (1);
		i++;
	}
	return (0);
}

void	Expert_System::AddAllFacts(void)
{
	if (this->Rules.empty())
		throw ExceptionExpSys("Input is not valid: There are no rules");

	auto i = this->Rules.begin();

	while (i != this->Rules.end())
	{
		// std::string str = ???;
		for(char& c : (*i)->getLeftPart()) {
			// std::cout << c << std::endl;
			if (c >= 65 && c <= 90 && !this->FindFacts(c))
			{
				auto *OneFact = new(Fact);
				OneFact->setName(c);
				this->Facts.push_back(OneFact);
			}
		}
		for(char& c : (*i)->getRightPart()) {
			if (c >= 65 && c <= 90 && !this->FindFacts(c))
			{
				auto *OneFact = new(Fact);
				OneFact->setName(c);
				this->Facts.push_back(OneFact);
			}

		}
		i++;
	}
}

void	Expert_System::AddRule(std::string line)
{
	std::string		left = "";
	std::string		right = "";
	auto			*OneRule = new(Rule);


	if (!std::regex_match(line, std::regex("^([A-Z()!+|^<]+)([=>]{2})([A-Z()!+|^]+)$")) && line.compare(""))
		throw ExceptionExpSys("Input is not valid: Mistake in a rule");
	if (line.find("=>") != std::string::npos)
	{
		left = line.substr(0, line.find("=>"));
		right = line.substr(line.find("=>") + 2);

		if (!left.compare("") || !right.compare(""))
			throw ExceptionExpSys("Input is not valid: Incomplete rule");
		OneRule->AddLeft(left);
		OneRule->AddRight(right);
		this->Rules.push_back(OneRule);
	}
}

void	Expert_System::PrintRules(void)
{
	auto i = this->Rules.begin();

	while (i != this->Rules.end())
	{
		(*i)->PrintRule();
		i++;
	}
}

void	Expert_System::PrintFacts(void)
{
	auto i = this->Facts.begin();

	while (i != this->Facts.end())
	{
		std::cout << (*i)->getName();
		std::cout << ", the status is " << (*i)->getStatus();
		std::cout << std::endl;
		i++;
	}
}
