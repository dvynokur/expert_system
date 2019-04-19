#pragma once

# include <iostream>
# include <algorithm>
# include <cctype>
# include "ExceptionExpSys.h"
# include "Expert_System.h"

class Checker {
public:
	Checker();
	~Checker();

	static bool		CheckLine(std::string line, Expert_System & ExpSys);

private:
	Checker &operator=(Checker const & src);
	Checker(Checker const & src);
};
