//
// droid.cpp for droid in /home/guillo_e//Documents/working/tek2/piscine/D08/ex00
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Wed Jan 16 09:06:53 2013 lyoma guillou
// Last update Wed Jan 16 17:47:44 2013 lyoma guillou
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

Droid::Droid(Droid const & other) : Id(other.Id), Energy(50), Attack(25), Toughness(15)
{
  this->Status = new std::string(*(other.Status));
  this->BattleData = new DroidMemory(*(other.BattleData));
  std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
  std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
  delete this->Status;
  delete this->BattleData;
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
  return (this->getStatus() == other.getStatus());
}

bool		Droid::operator!=(Droid const &other) const
{
  return (this->getStatus() != other.getStatus());
}

bool		Droid::operator()(std::string const *task, size_t exp)
{
  if (this->Energy >= 10 && this->BattleData)
    {
      this->Energy -= 10;
      if (this->Energy > 0)
	{
	  if (*(this->BattleData) >= exp)
	    {
	      this->setStatus(new std::string(*task + " - Completed!"));
	      *(this->BattleData) += exp / 2;
	      return true;
	    }
	  this->setStatus(new std::string(*task + " - Failed!"));
	  *(this->BattleData) += exp;
	}
      else
	this->setStatus(new std::string("Battery Low"));
    }
  return false;

}
  
  std::ostream&	operator<<(std::ostream& os, Droid const &d)
  {
    os << "Droid '" << d.getId() << ", " << d.getStatus() << ", " << d.getEnergy();
    return os;
  }
