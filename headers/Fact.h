#pragma once

#include <iostream>

class Fact {
public:
	Fact();
	~Fact();

	void	ChangeStatus(int status);
	void	ChangeIsQuery(bool q);
	void	setName(char name);
	char	getName(void);
	bool	getStatus(void);
	bool	getAnswered(void);
	void	setAnswered(void);

private:
	Fact &operator=(Fact const & src) = delete;
	Fact(Fact const & src) = delete;

	int		_status;
	bool	_query;
	char	_name;
	bool	_answered;
};
