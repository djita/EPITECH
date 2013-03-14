//
// droidmemory.cpp for droidmemory in /home/guillo_e//Documents/working/tek2/piscine/D08/ex01
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Wed Jan 16 13:52:44 2013 lyoma guillou
// Last update Wed Jan 16 15:27:42 2013 lyoma guillou
//

#include <iostream>
#include <cstdlib>

#include "droidmemory.hh"

DroidMemory::DroidMemory() : FingerPrint(random()), Exp(0)
{
  
}

DroidMemory::DroidMemory(DroidMemory const &other) : FingerPrint(other.FingerPrint), Exp(other.Exp)
{
  
}

DroidMemory::~DroidMemory()
{

}

size_t			DroidMemory::getFingerPrint(void)
{
  return this->FingerPrint;
}

size_t			DroidMemory::getExp(void)
{
  return this->Exp;
}

void			DroidMemory::operator<<(DroidMemory const & veteran)
{
  this->Exp += veteran.Exp;
  this->FingerPrint ^= veteran.FingerPrint;
}

void			DroidMemory::operator>>(DroidMemory & newbie)
{
  newbie.Exp += this->Exp;
  newbie.FingerPrint ^= this->FingerPrint;
}

DroidMemory&		DroidMemory::operator+=(DroidMemory const & chip)
{
  *this << chip;
  return *this;
}

DroidMemory&		DroidMemory::operator+=(size_t exp)
{
  this->Exp += exp;
  return *this;
}

DroidMemory&		DroidMemory::operator+(DroidMemory const &other)
{
  *this += other;
  return *this;
}

std::ostream&		operator<<(std::ostream& os, DroidMemory &chip)
{
  os << "DroidMemory '" << chip.getFingerPrint() << "', " << chip.getExp();
  return os;
}
