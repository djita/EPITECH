#include <string>
#include "Fruit.h"

Fruit::Fruit() : _name(""), _vitamins(0) {}

Fruit::Fruit(std::string const & name, int vitamins) : _name(name), _vitamins(vitamins) {}

Fruit::~Fruit() {}

int Fruit::getVitamins() const { return this->_vitamins; }

Fruit & Fruit::operator=(Fruit const &other)
{
  this->_name = other._name;
  this->_vitamins = other._vitamins;
  return *this;
}
