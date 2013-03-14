#include <iostream>
#include "Zergling.hpp"
#include "AUnit.hpp"

Zergling::Zergling() : AUnit()
{
  this->_damages = 5;
  std::cout << "Creation d'un Zergling" << std::endl;
}

Zergling::Zergling(Zergling const &other) : AUnit()
{
  this->_x = other._x;
  this->_y = other._y;
  this->_damages = other._damages;
  std::cout << "Creation d'un Zergling" << std::endl;
}

Zergling::Zergling(AUnit const &unit) : AUnit()
{
  this->_x = unit.getX();
  this->_y = unit.getY();
  this->_damages = 5;
  std::cout << "Creation d'un Zergling" << std::endl;
}

Zergling::~Zergling() { std::cout << "Zergling est mort" << std::endl; }

void Zergling::attack(int x, int y)
{
  this->_x = x;
  this->_y = y;
  std::cout << "Deplacement en x : " << x << " y : " << y << std::endl;
  std::cout << "Dommage Zergling : " << _damages << std::endl;
}

void Zergling::move(int x, int y)
{
  this->_x = x;
  this->_y = y;
  std::cout << "Deplacement en x : " << x << " y : " << y << std::endl;
}

Zergling & Zergling::operator=(AUnit const &other)
{
  this->_x = other.getX();
  this->_y = other.getY();
  this->_damages = other.getDam();
  return *this;
}
