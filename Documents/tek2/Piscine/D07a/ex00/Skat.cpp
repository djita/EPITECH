//
// Skat.cpp for skat in /home/guillo_e//Documents/working/tek2/piscine/D07a/ex00
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Tue Jan 15 17:19:33 2013 lyoma guillou
// Last update Tue Jan 15 18:09:17 2013 lyoma guillou
//

#include <iostream>
#include <string>

#include "Skat.h"

Skat::Skat()
{
  this->_name = "bob";
  this->_nbStimPaks = 15;
}

Skat::Skat(std::string const& name, int stimPaks) : _name(name), _nbStimPaks(stimPaks)
{
}

Skat::~Skat(void)
{
  return ;
}

int			Skat::stimPaks()
{
  return this->_nbStimPaks;
}

const std::string&	Skat::name()
{
  return this->_name;
}

void			Skat::shareStimPaks(int number, int *stock)
{
  if (number <= this->_nbStimPaks)
    {
      *stock += number;
      this->_nbStimPaks -= number;
      std::cout << "Keep the change." << std::endl;
    }
  else
    std::cout << "Don't be greedy" << std::endl;
}

void			Skat::addStimPaks(unsigned int number)
{
  if (!number)
    std::cout << "Hey boya, did you forget something ?" << std::endl;
  this->_nbStimPaks += number;
}

void			Skat::useStimPaks()
{
  if (this->_nbStimPaks > 0)
    {
      this->_nbStimPaks -= 1;
      std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    }
  else
    std::cout << "Mediiiiiic" << std::endl;
}

void			Skat::status()
{
  std::cout << "Soldier " << this->_name;
  std::cout << " reporting " << this->_nbStimPaks << " stimpaks remaining sir !" << std::endl;
}
