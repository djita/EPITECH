//
// droid.cpp for droid in /home/guillo_e//Documents/working/tek2/piscine/D08/ex00
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Wed Jan 16 09:06:53 2013 lyoma guillou
// Last update Wed Jan 16 16:36:34 2013 lyoma guillou
//

#include <iostream>
#include <string>

#include "droid.hh"

Droid::Droid(std::string id) : Id(id), Energy(50), Attack(25), Toughness(15)
{
  this->Status = new std::string("Standing by");
  this->BattleData = new DroidMemory;
  std::cout << "Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const & other)
  : Id(other.Id) , Energy(other.Energy) , Attack(other.Attack) , Toughness(other.Toughness)
{
  this->Status = new std::string(*(other.Status));
  this->BattleData = new DroidMemory(*(other.BattleData));
  std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
  std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
  delete this->Status;
}

std::string	Droid::getId(void) const
{
  return this->Id;
}

size_t		Droid::getEnergy(void) const
{
  return this->Energy;
}

size_t		Droid::getAttack(void) const
{
  return this->Attack;
}

size_t		Droid::getToughness(void) const
{
  return this->Toughness;
}

std::string	Droid::getStatus(void) const
{
  return *(this->Status);
}

void		Droid::setId(std::string id)
{
  this->Id = id;
}

void		Droid::setEnergy(size_t energy)
{
  this->Energy = energy;
}

void		Droid::setStatus(std::string* status)
{
  delete this->Status;
  this->Status = status;
}

Droid&		Droid::operator=(Droid const & other)
{
  if (&other != this)
    {
      this->Id = other.Id;
      this->Energy = other.Energy;
      this->setStatus(new std::string(*(other.Status)));
    }
  return *this;
}

Droid&		Droid::operator<<(size_t& tank)
{
  size_t	reload;
  size_t	max = 100;

  if (this->Energy + &tank >= 0 && (this->Energy + tank) <= max)
    this->Energy += tank;
  else
    {
      reload = 100 - this->Energy;
      this->Energy += reload;
      tank -= reload;
    }
  return *this;
}

bool		Droid::operator==(Droid const &other) const
{
  return (this->Status == other.Status);
}

bool		Droid::operator!=(Droid const &other) const
{
  return (this->Status != other.Status);
}

std::ostream&	operator<<(std::ostream& os, Droid const &d)
{
  os << "Droid '" << d.getId() << ", " << d.getStatus() << ", " << d.getEnergy();
  return os;
}
