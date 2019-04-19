#include "../headers/Fact.h"

Fact::Fact() : _status(false), _query(false), _answered(false), _wasHere(false) {};
Fact::~Fact() {};

void	Fact::ChangeStatus(int status) {
	this->_status = status;
}

void	Fact::ChangeIsQuery(bool q) {
	this->_query = q;
}

void	Fact::setName(char name) {
	this->_name = name;
}

char	Fact::getName(void) {
	return (this->_name);
}

bool	Fact::getStatus(void) {
	return (this->_status);
}

// bool	Fact::getIsQuery(void) {
// 	return (this->_query);
// }

bool	Fact::getAnswered(void) {
	return (this->_answered);
}

void	Fact::setAnswered(void) {
	this->_answered = true;
}

// bool	Fact::WasHere(void) {
// 	return (this->_wasHere);
// }

void	Fact::setWasHere(void) {
	this->_wasHere = true;
}