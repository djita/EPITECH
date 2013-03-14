#include <iostream>
#include "AUnit.hpp"

AUnit::AUnit() : _x(0), _y(0), _damages(0) {}

AUnit::AUnit(AUnit const &other) : _x(other._x), _y(other._y), _damages(other._damages) {}

AUnit::~AUnit() {}

int AUnit::getX() const { return this->_x; }
int AUnit::getY() const { return this->_y; }
int AUnit::getDam() const { return this->_damages; }

void AUnit::setX(int x) { this->_x = x; }
void AUnit::setY(int y) { this->_y = y; }
void AUnit::setDam(int damages) { this->_damages = damages; }

void AUnit::pos() const
{
  std::cout << "Position x : " << this->_x << " y : " << this->_y;
  std::cout << " <(8<) <(8)> (>3)>" << std::endl;
}

AUnit const & AUnit::operator=(AUnit const &other)
{
  this->_x = other._x;
  this->_y = other._y;
  this->_damages = other._damages;
  return *this;
}
