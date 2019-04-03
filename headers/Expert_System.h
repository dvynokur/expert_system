#ifndef EXPERT_SYSTEM
# define EXPERT_SYSTEM

# include <iostream>
# include <vector>
# include "ExceptionExpSys.h"
# include "Fact.h"
# include "Rule.h"

class Expert_System
{
public:
	Expert_System();
	~Expert_System();

	void				AddQueries(std::string line);
	void				AddRule(std::string line);
	void				AddInitFacts(std::string line);
	void				AddAllFacts(void);
	bool				IsQueries(void);
	bool				IsInitFacts(void);
	void				PrintRules(void);
	void				PrintFacts(void);
	bool				FindFacts(char name);
	void				UpdateInitStatus(void);
	// std::string			getInitFacts(void);

	std::vector<Rule *>	Rules;
	std::vector<Fact *>	Facts;

private:
	Expert_System &operator=(Expert_System const & src) = delete;
	Expert_System(Expert_System const & src) = delete;

	std::string				_queries;
	std::string				_init_facts;
	
};


#endif