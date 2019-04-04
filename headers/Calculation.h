#ifndef CALCULATION_H
# define CALCULATION_H

# include <iostream>
# include "ExceptionExpSys.h"
# include "Expert_System.h"

class Calculation
{
public:
	Calculation();
	~Calculation();
	Calculation(Expert_System & ExpSys);
	void		FindingAnswers(Expert_System & ExpSys);

	bool		CheckIsAnswer(void);
	void		AssignAnswer(void);
	

private:
	Calculation &operator=(Calculation const & src) = delete;
	Calculation(Calculation const & src) = delete;

	bool		_solved;
};


#endif
