#include "../headers/Rule.h"

Rule::Rule() : _left_part(""), _right_part(""), _wasHere(false) {};
Rule::~Rule() {};

void		Rule::AddLeft(std::string line) {
	this->_left_part = line;
}

void		Rule::AddRight(std::string line) {
	this->_right_part = line;
}

// void		Rule::PrintRule(void)
// {
// 	std::cout << "left: " << this->_left_part << std::endl;
// 	std::cout << "right: " << this->_right_part << std::endl;
// }

std::string		Rule::getLeftPart(void) {
	return (this->_left_part);
}

std::string		Rule::getRightPart(void) {
	return (this->_right_part);
}

bool		Rule::getWasHere(void) {
	return (this->_wasHere);
}

void		Rule::setWasHere(bool value) {
	this->_wasHere = value;
}
