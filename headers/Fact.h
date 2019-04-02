#ifndef FACT_H
# define FACT_H

# include <iostream>

class Fact
{
public:
	Fact();
	~Fact();

	void	ChangeStatus(bool status);

private:
	Fact &operator=(Fact const & src) = delete;
	Fact(Fact const & src) = delete;

	bool	_status;
	char	_name;
};

#endif