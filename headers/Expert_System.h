#ifndef EXPERT_SYSTEM
# define EXPERT_SYSTEM

# include <iostream>
# include <vector>
# include "ExceptionExpSys.h"
# include "Fact.h"
# include "Rule.h"
# include <string>

# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE				"\x1b[34m"
# define MAGENTA			"\x1b[35m"
# define CYAN				"\x1b[36m"
# define BLACK				"\x1b[37m"
# define RESET				"\x1b[0m"

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
	void				AddQueriesToFacts(void);
	bool				CheckPriority(char a, char b);
	bool				ReturnFactStatus(char a);
	bool				IsSolvable(std::string rule);
	std::string			ConvertString(std::string expr);
	std::string			getQueries(void);
	bool				FindingAnswers(char c);
	bool				OnlyOneUnknown(std::string rule);
	void				UpdateFacts(char c, int res);
	std::string			ReplaceRule(std::string rule, char c, char rep);
	size_t				getCounter(void);
	void				PrintResult(void);


// Calculation

	// bool				FindConnectedFacts(char name);
	bool				SolveRule(std::string s);

	std::vector<Rule *>	Rules;
	std::vector<Fact *>	Facts;
	

private:
	Expert_System &operator=(Expert_System const & src) = delete;
	Expert_System(Expert_System const & src) = delete;

	std::string				_queries;
	std::string				_init_facts;

	size_t					_counter;

};


#endif