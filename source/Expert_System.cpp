#include "../headers/Expert_System.h"

Expert_System::Expert_System() : _queries(""), _init_facts(""), _counter(1) {};
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
				(*i)->ChangeIsQuery(true);
				break ;
			}
			i++;
		}
		if (i == this->Facts.end())
		{
			auto *OneFact = new(Fact);
			OneFact->setName(c);
			OneFact->ChangeIsQuery(true);
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
			(*i)->ChangeStatus(1);
		i++;
	}
}

bool		Expert_System::SolveRule(std::string s)
{
	bool res = false;

	std::vector<char> v(s.begin(), s.end());
	std::vector<char> output;

	if (s.length() == 1)
	{
		if (s[0] == 1)
			return (1);
		else if (s[0] == 0)
			return (0);
		else
			return (ReturnFactStatus(s[0]));
	}

	for (const char & c : v)
	{
		if ((c >= 65 && c <= 90) || c == 1 || c == 0)
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
			{
				// std::cout << "c in error: " << c << std::endl;
				throw ExceptionExpSys("Error. Wrong expression.");
			}
		}
	}


	// std::cout << "output back: " << char(output.back()) << std::endl;
	if (output.size() != 1)
		throw ExceptionExpSys("Error. Wrong expression");


	// std::cout << "Solved Rule " << s << " = " << res << std::endl;
	return (res);
}

bool		Expert_System::OnlyOneUnknown(std::string rule)
{
	int		counter = 0;

	for (const char & c : rule)
	{
		auto i = this->Facts.begin();
		if (c >= 65 && c <= 90)
		{
			// std::cout << c << " ";
			while (i != this->Facts.end())
			{
				if ((*i)->getName() == c && (*i)->getIsQuery() == true)
					counter++;
				i++;
			}
		}
	}
	if (counter == 1)
		return (true);
	else
		return (false);
}

void		Expert_System::UpdateFacts(char c, int res)
{
	auto i = this->Facts.begin();

	while (i != this->Facts.end())
	{
		if ((*i)->getName() == c)
		{
			(*i)->ChangeStatus(res);
			(*i)->ChangeIsQuery(false);
		}
		i++;
	}
}

std::string Expert_System::ReplaceRule(std::string rule, char c, char rep)
{
	std::string res = rule;

	for (int i = 0; i < res.length(); ++i) {
		if (res[i] == c)
			res[i] = rep;
  	}

	return (res);
}

bool		Expert_System::FindingAnswers(char c)
{
	bool res = false;

	auto i = this->Rules.begin();

	while (i != this->Rules.end())
	{
		if ((*i)->getLeftPart().find(c) != std::string::npos && OnlyOneUnknown((*i)->getLeftPart()) && IsSolvable((*i)->getRightPart()))
		{
			res = SolveRule((*i)->getRightPart());
			if (res == SolveRule(ReplaceRule((*i)->getLeftPart(), c, 1)))
				UpdateFacts(c, 1);
			else if (res == SolveRule(ReplaceRule((*i)->getLeftPart(), c, 0)))
				UpdateFacts(c, 0);
			else
				UpdateFacts(c, 2);
			return (true);
		}
		if ((*i)->getRightPart().find(c) != std::string::npos && OnlyOneUnknown((*i)->getRightPart()) && IsSolvable((*i)->getLeftPart()))
		{
			res = this->SolveRule((*i)->getLeftPart());
			if (res == SolveRule(ReplaceRule((*i)->getRightPart(), c, 1)))
				UpdateFacts(c, 1);
			else if (res == SolveRule(ReplaceRule((*i)->getRightPart(), c, 0)))
				UpdateFacts(c, 0);
			else 
				UpdateFacts(c, 2);
			return (true);
		}
		i++;
	}
	return (false);
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

bool		Expert_System::IsSolvable(std::string rule)
{
	for (const char & c : rule)
	{
		auto i = this->Facts.begin();
		if (c >= 65 && c <= 90)
		{
			// std::cout << c << " ";
			while (i != this->Facts.end())
			{
				if ((*i)->getName() == c && (*i)->getIsQuery() == true)
					return (false);
				i++;
			}
		}
	}
	return (true);
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

void		Expert_System::PrintResult(void)
{
	for (const char & c : this->getQueries())
	{
		auto i = this->Facts.begin();

		while (i != this->Facts.end())
		{
			if ((*i)->getName() == c)
			{
				std::cout << YELLOW << "Rule " << BLUE << c << YELLOW << " is "; 
				if ((*i)->getStatus() == 0)
					std::cout << RED << "false" << std::endl;
				else if ((*i)->getStatus() == 1)
					std::cout << GREEN << "true" << std::endl;
				else
					std::cout << CYAN << "ambiguous" << std::endl;
			}
			i++;
		}
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

size_t		Expert_System::getCounter(void) {
	return (this->_counter);
}
