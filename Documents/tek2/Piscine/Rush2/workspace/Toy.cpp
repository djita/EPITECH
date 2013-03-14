//
// Toy.cpp for Toy in /home/guillo_e//Documents/working/tek2/piscine/Rush2/workspace
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Sat Jan 19 11:45:13 2013 lyoma guillou
// Last update Sat Jan 19 14:12:47 2013 lyoma guillou
//

#include <iostream>
#include <string>

#include "Toy.h"

Toy::Toy(std::string const &name) : Object(name)
{

}

Toy::Toy(Toy const &other) : Object(other.getTitle())
{

}

Toy::~Toy(void)
{

}

void	Toy::setTaken(bool set)
{
  this->Taken = set;
}

Toy&	Toy::operator=(Toy const &other)
{
  this->Title = other.getTitle();
  return *this;
}
