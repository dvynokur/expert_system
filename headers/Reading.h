#ifndef READING_H
# define READING_H

# include <iostream>
# include <fstream>
# include "ExceptionExpSys.h"
# include "Checker.h"
# include "Expert_System.h"

class Reading
{
private:
	Reading & operator=(Reading const & src);
	Reading(Reading const & src);
public:
	Reading();
	Reading(int argc, char **argv);
	~Reading();
	std::string		line;
};

#endif