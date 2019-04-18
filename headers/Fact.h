#ifndef FACT_H
# define FACT_H

# include <iostream>

class Fact
{
public:
	Fact();
	~Fact();

	void	ChangeStatus(int status);
	void	ChangeIsQuery(bool q);
	void	setName(char name);
	char	getName(void);
	bool	getStatus(void);
	bool	getIsQuery(void);
	bool	getAnswered(void);
	void	setAnswered(void);
	void	setWasHere(void);
	bool	WasHere(void);

private:
	Fact &operator=(Fact const & src) = delete;
	Fact(Fact const & src) = delete;

	int		_status;
	bool	_query;
	char	_name;
	bool	_wasHere;
	bool	_answered;
};

#endif