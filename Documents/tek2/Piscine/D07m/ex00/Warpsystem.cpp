//
// Warpsystem.cpp for warpsystem in /home/guillo_e//Documents/working/tek2/piscine/D07m/ex00
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Jan 15 09:20:13 2013 lyoma guillou
// Last update Tue Jan 15 14:33:39 2013 lyoma guillou
//

#include "Warpsystem.hh"

WarpSystem::QuantumReactor::QuantumReactor()
{
  this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
  return ;
}

bool		WarpSystem::QuantumReactor::isStable()
{
  return this->_stability;
}

void		WarpSystem::QuantumReactor::setStability(bool val)
{
  this->_stability = val;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *elem)
{
  this->_coreReactor = elem;
}

WarpSystem::Core::~Core()
{
  return ;
}

WarpSystem::QuantumReactor	*WarpSystem::Core::checkReactor()
{
  return this->_coreReactor;
}
