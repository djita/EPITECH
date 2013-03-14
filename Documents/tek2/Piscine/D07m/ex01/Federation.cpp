//
// Federation.cpp for federation in /home/guillo_e//Documents/working/tek2/piscine/D07m/ex00
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Jan 15 09:27:59 2013 lyoma guillou
// Last update Tue Jan 15 15:33:10 2013 lyoma guillou
//

#include <iostream>

#include "Warpsystem.hh"
#include "Federation.hh"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;

  std::cout << "The ship USS " << this->_name << " has been finished. ";
  std::cout << "It is " << this->_length << " m in length and "; 
  std::cout << this->_width << " m in width." << std::endl;
  std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
  return ;
}

void		Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
  if (core && core->checkReactor())
    {
      std::cout << "USS " << this->_name;
      std::cout << ": The core is set." << std::endl;
      this->core = core;
    }
}

void		Federation::Starfleet::Ship::checkCore(void)
{
  WarpSystem::QuantumReactor	*reactor;

  reactor = this->core->checkReactor();
  if (reactor)
    {
      std::cout << "USS " << this->_name;
      std::cout << ": The core is " << ((reactor->isStable()) ? "stable" : "unstable");
      std::cout << " at the time." << std::endl;
    }
}

void		Federation::Starfleet::Ship::promote(Captain *captain)
{
  std::cout << captain->getName() << ": I'm glad to be the captain of the USS ";
  std::cout << this->_name << "." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;

  std::cout << "The independant ship " << this->_name;
  std::cout << " just finished its construction. It is " << this->_length;
  std::cout << " m in length and " << this->_width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
  return ;
}

void		Federation::Ship::setupCore(WarpSystem::Core *core)
{
  if (core && core->checkReactor())
    {
      std::cout << "USS " << this->_name;
      std::cout << ": The core is set." << std::endl;
      this->core = core;
    }
}

void		Federation::Ship::checkCore(void)
{
  WarpSystem::QuantumReactor	*reactor;

  reactor = this->core->checkReactor();
  if (reactor)
    {
      std::cout << "USS " << this->_name;
      std::cout << ": The core is " << ((reactor->isStable()) ? "stable" : "unstable");
      std::cout << " at the time." << std::endl;
    }
}

Federation::Starfleet::Captain::Captain(std::string name)
{
  this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{
  return ;
}

std::string	Federation::Starfleet::Captain::getName()
{
  return this->_name;
}

int		Federation::Starfleet::Captain::getAge()
{
  return this->_age;
}

void		Federation::Starfleet::Captain::setAge(int age)
{
  this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
  this->_name = name;

  std::cout << "Ensign " << this->_name;
  std::cout << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign(void)
{
  return ;
}
