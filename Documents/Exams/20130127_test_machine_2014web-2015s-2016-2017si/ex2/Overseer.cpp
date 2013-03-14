#include <iostream>
#include "AUnit.hpp"
#include "Overseer.hpp"

Overseer::Overseer() : AUnit()
{
  this->_type = AUnit::SEER;
  std::cout << "Mutation d'un Overlord en Overseer" << std::endl;
}

Overseer::Overseer(Overseer const &other) : AUnit()
{
  this->_x = other._x;
  this->_y = other._y;
  this->_damages = other._damages;
  this->_type = other._type;
  std::cout << "Mutation d'un Overlord en Overseer" << std::endl;
}

Overseer::Overseer(AUnit const &unit) : AUnit()
{
  this->_x = unit.getX();
  this->_y = unit.getY();
  this->_damages = unit.getDam();
  this->_type = AUnit::SEER;
  std::cout << "Mutation d'un Overlord en Overseer" << std::endl;
}

Overseer::~Overseer() { std::cout << "Destruction d'un Overseer" << std::endl; }

void Overseer::attack(int x, int y)
{
  this->_x = x;
  this->_y = y;
  std::cout << "Deplacement en x : " << x << " y : " << y << std::endl;
  std::cout << "Un Overseer ne peut attaquer mais detecte" << std::endl;
}

void Overseer::move(int x, int y)
{
  this->_x = x;
  this->_y = y;
  std::cout << "Deplacement en x : " << x << " y : " << y << std::endl;
}

Overseer & Overseer::operator=(AUnit const &other)
{
  this->_x = other.getX();
  this->_y = other.getY();
  this->_damages = other.getDam();
  this->_type = AUnit::SEER;
  return *this;
}
