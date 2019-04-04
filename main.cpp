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

	bool A = true;
	bool B = true;

	bool C = true;
	bool D = true;

	// A & B = C & D;

	std::cout << "C: " << C << std::endl;


	// std::cout << "D: " << D << std::endl;
	
	return 0;
}