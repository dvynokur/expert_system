#include <iostream>
#include <sstream>
#include "headers/Reading.h"
#include "headers/ExceptionExpSys.h"

int		main(int argc, char **argv)
{
	try {
		Reading		read(argc, argv);
	} catch (ExceptionExpSys & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}