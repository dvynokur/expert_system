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

