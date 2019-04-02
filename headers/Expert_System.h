#ifndef EXPERT_SYSTEM
# define EXPERT_SYSTEM

# include <iostream>
# include <vector>
# include "ExceptionExpSys.h"

class Expert_System
{
public:
	Expert_System();
	~Expert_System();

	void	AddQueries(std::string line);
	bool	IsQueries(void);

private:
	Expert_System &operator=(Expert_System const & src) = delete;
	Expert_System(Expert_System const & src) = delete;

	std::string		_queries;
};


#endif