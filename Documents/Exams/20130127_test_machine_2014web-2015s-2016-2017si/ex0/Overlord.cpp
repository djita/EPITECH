#include <iostream>
#include "AUnit.hpp"
#include "Overlord.hpp"

Overlord::Overlord() : AUnit() { std::cout << "Creation d'un Overlord" << std::endl; }

Overlord::Overlord(const Overlord &other) : AUnit()
{
  this->_x = other._x;
  this->_y = other._y;
  this->_damages = other._damages;
  std::cout << "Creation d'un Overlord" << std::endl;
}

Overlord::Overlord(const AUnit &unit) : AUnit()
{
  this->_x = unit.getX();
  this->_y = unit.getY();
  this->_damages = unit.getDam();
  std::cout << "Creation d'un Overlord" << std::endl;
}

Overlord::~Overlord() { std::cout << "Destruction d'un Overlord" << std::endl; }

void Overlord::attack(int x, int y)
{
  this->_x = x;
  this->_y = y;
  std::cout << "Deplacement en x : " << x << " y : " << y << std::endl;
  std::cout << "Un Overlord ne peut attaquer" << std::endl;
}

void Overlord::move(int x, int y)
{
  this->_x = x;
  this->_y = y;
  std::cout << "Deplacement en x : " << x << " y : " << y << std::endl;
}

Overlord const & Overlord::operator=(AUnit const &other)
{
  this->_x = other.getX();
  this->_y = other.getY();
  this->_damages = other.getDam();
  return *this;
}
