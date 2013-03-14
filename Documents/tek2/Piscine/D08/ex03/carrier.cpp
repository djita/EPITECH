//
// carrier.cpp for carrier in /home/guillo_e//Documents/working/tek2/piscine/D08/ex03
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Wed Jan 16 17:28:25 2013 lyoma guillou
// Last update Wed Jan 16 21:51:30 2013 lyoma guillou
//

#include <cstdlib>

#include "carrier.hh"
#include "droid.hh"

Carrier::Carrier(std::string id) : Id(id), Energy(300), Attack(100), Toughness(90), Speed(0)
{
  for (size_t i = 0; i < 5; ++i)
    this->Droids[i] = NULL;
}

Carrier::~Carrier(void)
{
  for (size_t i = 0; i < 5; ++i)
    if (NULL != this->Droids[i])
      delete Droids[i];
}

std::string	Carrier::getId(void) const
{
  return this->Id;
}

size_t		Carrier::getEnergy(void) const
{
  return this->Energy;
}

size_t		Carrier::getAttack(void) const
{
  return this->Attack;
}

size_t		Carrier::getToughness(void) const
{
  return this->Toughness;
}

size_t		Carrier::getSpeed(void) const
{
  return this->Speed;
}

size_t		Carrier::getNbDroids(void) const
{
  size_t	nb = 0;

  for (size_t i = 0; i < 5; ++i)
    if (NULL != this->Droids[i])
      ++nb;
  return nb;
}

Carrier&	Carrier::operator<<(Droid*& droid)
{
  for (size_t i = 0; i < 5; ++i)
    if (!this->Droids[i])
      {
	if (0 == this->Speed)
	  this->Speed = 100;
	this->Droids[i] = droid;
	droid = NULL;
	this->Speed -= 10;
	break;
      }
  return *this;
}

Carrier&	Carrier::operator<<(size_t& tank)
{
  size_t	reload;
  size_t	max = 600;

  if (this->Energy + &tank >= 0 && (this->Energy + tank) <= max)
    this->Energy += tank;
  else
    {
      reload = 600 - this->Energy;
      this->Energy += reload;
      tank -= reload;
    }
  return *this;
}

Carrier&	Carrier::operator>>(Droid*& droid)
{
  for (size_t i = 0; i < 5; ++i)
    if (!droid && this->Droids[i])
      {
	droid = this->Droids[i];
	this->Droids[i] = NULL;
	this->Speed += 10;
	if (100 == this->Speed)
	  this->Speed = 0;
	break;
      }
  return *this;
}

Droid*&		Carrier::operator[](size_t pos)
{
  return (this->Droids[pos]);
}

Droid*		Carrier::operator[](size_t pos) const
{
  return (this->Droids[pos]);
}

bool		Carrier::operator()(size_t x, size_t y)
{
  size_t	cost;
  std::string	free = "Free";

  cost = (abs(x) + abs(y)) * (10 + this->getNbDroids());
  if (this->Speed > 0 && this->Energy >= cost)
    {
      this->Energy -= cost;
      return true;
    }
  return false;
}

Carrier&	Carrier::operator~(void)
{
  size_t	adjust;

  adjust = 10 * this->getNbDroids();
  if (0 != adjust)
    this->Speed = 100 - adjust;
  return *this;
}


std::ostream&		operator<<(std::ostream& os, Carrier const &ship)
{
  os << "Carrier '" << ship.getId() << "' Droid(s) on-board:" << std::endl;
  for (size_t i = 0; i < 5; ++i)
    {
      os << "[" << i << "] : ";
      if (NULL != ship[i])
	os << *ship[i];
      else
	os << "Free";
      os << std::endl;
    }
  os << "Speed : " << ship.getSpeed() << ", Energy " << ship.getEnergy();
  return os;
}
