#ifndef EXCEPTIONEXPSYS_H
# define EXCEPTIONEXPSYS_H

# include <exception>
# include <string>
# include <sstream>

class ExceptionExpSys
{
private:
	std::string		_err;
	const			ExceptionExpSys & operator=(const ExceptionExpSys &);

public:
	ExceptionExpSys(void);
	ExceptionExpSys(ExceptionExpSys const & src);
	ExceptionExpSys(std::string const &e);
	~ExceptionExpSys(void) throw();

	char const		*what(void) const throw();
};

#endif