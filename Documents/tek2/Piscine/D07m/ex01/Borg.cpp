//
// Borg.cpp for Borg in /home/guillo_e//Documents/working/tek2/piscine/D07m/ex01
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Jan 15 14:46:21 2013 lyoma guillou
// Last update Tue Jan 15 15:28:57 2013 lyoma guillou
//

#include <iostream>
#include <string>

#include "Borg.hh"

Borg::Ship::Ship(void)
{
  this->_side = 300;
  this->_maxWarp = 9;

  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship(void)
{
  return ;
}

void		Borg::Ship::setupCore(WarpSystem::Core *core)
{
  if (core && core->checkReactor())
    this->core = core;
}

void		Borg::Ship::checkCore(void)
{
  WarpSystem::QuantumReactor	*reactor;

  reactor = this->core->checkReactor();
  if (reactor)
    {
      std::cout << ((reactor->isStable()) ? "Everything is in order." : "Critical failure imminent.");
      std::cout << std::endl;
    }
}
