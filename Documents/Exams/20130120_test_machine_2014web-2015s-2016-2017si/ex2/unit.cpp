#include <iostream>
#include <string>

#include "unit.h"

unit::unit(std::string const name, std::string const type, int posX, int posY, int dam, int cHP, int mHP)
  : name(new std::string(name)), type(new std::string(type)), posX(posX), posY(posY), dam(dam), cHP(cHP), mHP(mHP)
{

}

unit::unit(unit const &other) : name(other.name), type(other.type), posX(other.posX), posY(other.posY), dam(other.dam), cHP(other.cHP), mHP(other.mHP)
{

}

unit::~unit(void)
{

}

std::string const unit::getName() const
{
  return *this->name;
}

std::string const unit::getType() const
{
  return *this->type;
}

int unit::getPosX() const
{
  return this->posX;
}

int unit::getPosY() const
{
  return this->posY;
}

int unit::getDam() const
{
  return this->dam;
}

int unit::getCHP() const
{
  return this->cHP;
}

int unit::getMHP() const
{
  return this->mHP;
}

unit& unit::operator=(unit const &other)
{
  delete this->name;
  delete this->type;

  this->name = new std::string(*other.name);
  this->type = new std::string(*other.type);
  this->posX = other.posX;
  this->posY = other.posY;
  this->dam = other.dam;
  this->cHP = other.cHP;
  this->mHP = other.mHP;
  return *this;
}

unit& unit::operator+=(int heal)
{
  if (this->cHP > 0)
    {
      this->cHP += heal;
      if (this->cHP >= this->mHP)
	this->cHP = this->mHP;
    }
  return *this;
}

unit& unit::operator-=(int dmg)
{
  if (this->cHP > 0)
    {
      this->cHP -= dmg;
      if (this->cHP <= 0)
	this->cHP = 0;
    }
  return *this;
}

std::ostream& operator<<(std::ostream& os, unit const &_unit)
{
  os << _unit.getName() << " is a " << _unit.getType() << " in ";
  os << _unit.getPosX() << "/" << _unit.getPosY() << " with ";
  os << _unit.getCHP() << "/" << _unit.getMHP() << "HP damaging at ";
  os << _unit.getDam();
  return os;
}
