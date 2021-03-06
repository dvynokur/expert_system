#pragma once

# include <iostream>

class Rule {
public:
	Rule();
	~Rule();

	void			AddLeft(std::string line);
	void			AddRight(std::string line);
	// void			PrintRule(void);
	std::string		getLeftPart(void);
	std::string		getRightPart(void);
	bool			getWasHere(void);
	void			setWasHere(bool value);

private:
	Rule &operator=(Rule const & src) ;
	Rule(Rule const & src) = delete;

	std::string		_left_part;
	std::string		_right_part;
	bool			_wasHere;
};
