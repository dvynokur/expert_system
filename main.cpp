#include <iostream>
#include <sstream>
#include "headers/Reading.h"
#include "headers/ExceptionExpSys.h"

int		main(int argc, char **argv)
{
	std::cout << "\x1b[33m" << "================================" << "\x1b[0m" << std::endl;

	try {
		Reading		read(argc, argv);
	} catch (ExceptionExpSys & e) {
		std::cout << e.what() << std::endl;
	}

	bool a = false;
	bool b = true;
	bool c = true;

	// std::cout << "proverka : " << ((b && c) || a) << std::endl;
	
	return 0;
}