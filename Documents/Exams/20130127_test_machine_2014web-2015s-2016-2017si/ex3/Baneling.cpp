#include <iostream>
#include "AUnit.hpp"
#include "Baneling.hpp"

Baneling::Baneling() : AUnit()
{
  this->_damages = 15;
  this->_type = AUnit::BANE;
  std::cout << "Mutation d'un Zergling en Baneling" << std::endl;
}

Baneling::Baneling(Baneling const &other) : AUnit()
{
  this->_x = other._x;
  this->_y = other._y;
  this->_damages = other._damages;
  this->_type = other._type;
  std::cout << "Mutation d'un Zergling en Baneling" << std::endl;
}

Baneling::Baneling(AUnit const &unit) : AUnit()
{
  this->_x = unit.getX();
  this->_y = unit.getY();
  this->_damages = 15;
  this->_type = AUnit::BANE;
  std::cout << "Mutation d'un Zergling en Baneling" << std::endl;
}

Baneling::~Baneling() { std::cout << "Baneling a explose" << std::endl; }

void Baneling::attack(int x, int y)
{
  this->_x = x;
  this->_y = y;
  std::cout << "Deplacement en x : " << x << " y : " << y << std::endl;
  std::cout << "Dommage Baneling : " << _damages << std::endl;
}

void Baneling::move(int x, int y)
{
  this->_x = x;
  this->_y = y;
  std::cout << "Deplacement en x : " << x << " y : " << y << std::endl;
}

Baneling & Baneling::operator=(AUnit const &other)
{
  this->_x = other.getX();
  this->_y = other.getY();
  this->_damages = other.getDam();
  this->_type = AUnit::BANE;
  return *this;
}
