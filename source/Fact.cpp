#include "../headers/Fact.h"

Fact::Fact() : _status(false) {};
Fact::~Fact() {};

void	Fact::ChangeStatus(bool status) {
	this->_status = status;
}