#ifndef FACT_H
# define FACT_H

# include <iostream>

class Fact
{
public:
	Fact();
	~Fact();

	void	ChangeStatus(bool status);
	void	setName(char name);
	char	getName(void);
	bool	getStatus(void);

private:
	Fact &operator=(Fact const & src) = delete;
	Fact(Fact const & src) = delete;

	bool	_status;
	char	_name;
};

#endif