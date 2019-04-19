#pragma once

# include <exception>
# include <string>
# include <sstream>
# include <regex>

class ExceptionExpSys: public std::exception {

public:
	ExceptionExpSys(void);
	ExceptionExpSys(ExceptionExpSys const & src);
	ExceptionExpSys(std::string const &e);
	~ExceptionExpSys(void) throw();

	char const		*what(void) const throw();

private:
	std::string		_err;
	const			ExceptionExpSys & operator=(const ExceptionExpSys &);
};
