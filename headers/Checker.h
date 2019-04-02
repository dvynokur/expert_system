#ifndef CHECKER_H
# define CHECKER_H

# include <iostream>
# include <regex>
# include <algorithm>
# include <string>
# include <cctype>
# include "ExceptionExpSys.h"
# include "Expert_System.h"

class Checker
{
public:
	Checker();
	~Checker();

	static bool		CheckLine(std::string line, Expert_System & ExpSys);

private:
	Checker &operator=(Checker const & src);
	Checker(Checker const & src);
};


#endif