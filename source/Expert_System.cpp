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

void		Expert_System::AddQueries(std::string line)
{
	if (this->IsQueries())
		throw ExceptionExpSys("Input is not valid: More than 1 line with queries");

	if (!std::regex_match(line, std::regex("^([A-Z]+)$")))
		throw ExceptionExpSys("Input is not valid: A fact can be any uppercase alphabetical character");

	this->_queries = line;
	std::cout << "queries: " << this->_queries << std::endl;
}

void		Expert_System::AddInitFacts(std::string line)
{
	if (this->IsInitFacts())
		throw ExceptionExpSys("Input is not valid: More than 1 line with initial facts");

	if (!std::regex_match(line, std::regex("^([A-Z]+)$")))
		throw ExceptionExpSys("Input is not valid: A fact can be any uppercase alphabetical character");

	this->_init_facts = line;
	std::cout << "init facts: " << this->_init_facts << std::endl;

}

bool		Expert_System::FindFacts(char name)
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

void		Expert_System::AddQueriesToFacts(void)
{
	for(char & c : this->_queries)
	{
		auto i = this->Facts.begin();

		while (i != this->Facts.end())
		{
			if ((*i)->getName() == c)
			{
				(*i)->ChangeIsQuery();
				break ;
			}
			i++;
		}
		if (i == this->Facts.end())
		{
			auto *OneFact = new(Fact);
			OneFact->setName(c);
			OneFact->ChangeIsQuery();
			this->Facts.push_back(OneFact);
		}
	}
}

void		Expert_System::AddAllFacts(void)
{
	if (this->Rules.empty())
		throw ExceptionExpSys("Input is not valid: There are no rules");

	auto i = this->Rules.begin();

	while (i != this->Rules.end())
	{
		for(char& c : (*i)->getLeftPart()) {
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

bool		Expert_System::CheckPriority(char a, char b)
{
	if ((a == '+' && b == '!'))
		return (true);
	if ((a == '|' && b == '!') || (a == '|' && b == '+'))
		return (true);
	if ((a == '^' && b == '!') || (a == '^' && b == '+') || (a == '^' && b == '|'))
		return (true);
	return (false);
}

std::string	Expert_System::ConvertString(std::string expr)
{
	std::vector<char>	output;
	std::vector<char>	operations;

	for(char & c : expr)
	{
		if (c >= 65 && c <= 90) {
			output.push_back(c);
		}
		else
		{
			if (operations.empty())
				operations.push_back(c);
			else
			{
				if (c == '(')
					operations.push_back(c);
				else if (c == ')')
				{
					if (!(std::find(operations.begin(), operations.end(), '(') != operations.end()))
						throw ExceptionExpSys("Error: Opening parenthesis missing");
					else
					{
						while (operations.back() != '(')
						{
							output.push_back(operations.back());
							operations.pop_back();
						}
						operations.pop_back();
					}
				}
				else if (c == '!' || c == '+' || c == '|' || c == '^')
				{
					while (operations.size() > 0 && this->CheckPriority(c, operations.back()))
					{
						output.push_back(operations.back());
						operations.pop_back();
					}
					operations.push_back(c);
				}
				else
					throw ExceptionExpSys("Error: Something wrong with expressions");
			}
		}
	}
	if (std::find(operations.begin(), operations.end(), '(') != operations.end() || 
		std::find(operations.begin(), operations.end(), ')') != operations.end())
		throw ExceptionExpSys("Error: Something wrong with expressions");
	if (!operations.empty())
	{
		while (!operations.empty())
		{
			output.push_back(operations.back());
			operations.pop_back();
		}
	}
	std::string s(output.begin(), output.end());
	return (s);
}

void		Expert_System::UpdateInitStatus(void)
{
	if (this->Facts.empty())
		throw ExceptionExpSys("Input is not valid: There are no Facts");

	auto i = this->Facts.begin();
	while (i != this->Facts.end())
	{
		if (this->_init_facts.find((*i)->getName()) != std::string::npos)
		    (*i)->ChangeStatus(true);
		i++;
	}
}

void		Expert_System::SolveRule(std::string s)
{
	bool res = false;

	std::vector<char> v(s.begin(), s.end());
	std::vector<char> output;

	for (const char & c : v)
	{
		if (c >= 65 && c <= 90)
			output.push_back(c);
 		else
		{
			if ((c == '+' || c == '|' || c == '^') && output.size() > 1) {
				res = this->ReturnFactStatus(output.back());
				output.pop_back();
				if (c == '+')
					res = res & ReturnFactStatus(output.back());
				else if (c == '|')
					res = res | ReturnFactStatus(output.back());
				else
					res = res ^ ReturnFactStatus(output.back());
				output.pop_back();
				output.push_back(res);		
			}
			else if (c == '!' && output.size() > 0) {
				
				res = !(ReturnFactStatus(output.back()));
				output.pop_back();
				output.push_back(res);
			}
			else
				throw ExceptionExpSys("Error. Wrong expression.");
		}
	}

	// std::cout << "output back: " << char(output.back()) << std::endl;
	if (output.size() != 1)
		throw ExceptionExpSys("Error. Wrong expression");


	std::cout << "Solved Rule " << s << " = " << res << std::endl;

}

bool		Expert_System::ReturnFactStatus(char c)
{
	if (c == 1)
		return (true);
	if (c == 0)
		return (false);

	auto i = this->Facts.begin();
	bool res = false;

	while (i != this->Facts.end())
	{
		if ((*i)->getName() == c)
			res = (*i)->getStatus();
		i++;
	}
	return (res);
}

void		Expert_System::AddRule(std::string line)
{
	std::string		left = "";
	std::string		right = "";
	auto			*OneRule = new(Rule);

	if (line.find("<=>") != std::string::npos)
		throw ExceptionExpSys("Biconditional rules are a bonus. Please, use normal rules.");
	if (!std::regex_match(line, std::regex("^([A-Z()!+|^]+)([=>]{2})([A-Z()!+|^]+)$")) && line.compare(""))
		throw ExceptionExpSys("Input is not valid: Mistake in a rule");
	if (line.find("=>") != std::string::npos)
	{
		left = line.substr(0, line.find("=>"));
		right = line.substr(line.find("=>") + 2);

		if (!left.compare("") || !right.compare(""))
			throw ExceptionExpSys("Input is not valid: Incomplete rule");
		OneRule->AddLeft(this->ConvertString(left));
		OneRule->AddRight(this->ConvertString(right));
		this->Rules.push_back(OneRule);
	}
}

void		Expert_System::PrintRules(void)
{
	auto i = this->Rules.begin();

	while (i != this->Rules.end())
	{
		(*i)->PrintRule();

		i++;

	}

}

void		Expert_System::PrintFacts(void)
{
	auto i = this->Facts.begin();

	while (i != this->Facts.end())
	{
		std::cout << (*i)->getName();
		std::cout << ", the status is " << (*i)->getStatus() << ", is query: " << (*i)->getIsQuery();
		std::cout << std::endl;
		i++;
	}
}

std::string	Expert_System::getQueries(void) {
	return (this->_queries);
}
