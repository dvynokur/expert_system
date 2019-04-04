#include "../headers/Fact.h"

Fact::Fact() : _status(false), _query(false) {};
Fact::~Fact() {};

void	Fact::ChangeStatus(bool status) {
	this->_status = status;
}

void	Fact::ChangeIsQuery(void) {
	this->_query = true;
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

bool	Fact::getIsQuery(void) {
	return (this->_query);
}
