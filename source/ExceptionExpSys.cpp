#include "../headers/ExceptionExpSys.h"

ExceptionExpSys::ExceptionExpSys() : _err("") { ; };
ExceptionExpSys::~ExceptionExpSys() throw () { ; };

ExceptionExpSys::ExceptionExpSys(std::string const &error) : _err(RED + error + RESET) { ; }

char const		*ExceptionExpSys::what(void) const throw() {
	return this->_err.c_str();
}