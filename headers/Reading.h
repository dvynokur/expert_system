#pragma once

# include <fstream>
# include "ExceptionExpSys.h"
# include "Checker.h"
# include "Expert_System.h"
# include "Rule.h"

class Reading {
public:
	Reading();
	Reading(int argc, char **argv);
	~Reading();
	std::string		line;

private:
	Reading & operator=(Reading const & src);
	Reading(Reading const & src);
};
