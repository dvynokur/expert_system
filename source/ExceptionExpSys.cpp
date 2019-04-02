#include "../headers/ExceptionExpSys.h"

ExceptionExpSys::ExceptionExpSys() : _err("") { ; };
ExceptionExpSys::~ExceptionExpSys() throw () { ; };

ExceptionExpSys::ExceptionExpSys(std::string const &error) : _err(error) { ; }

char const		*ExceptionExpSys::what(void) const throw() {
	return this->_err.c_str();
}