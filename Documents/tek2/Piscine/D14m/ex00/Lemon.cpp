#include <string>
#include "Fruit.h"
#include "Lemon.h"

Lemon::Lemon() : Fruit("lemon", 3)
{

}

Lemon::~Lemon()
{

}

std::string const & Lemon::getName() const { return this->_name; }
