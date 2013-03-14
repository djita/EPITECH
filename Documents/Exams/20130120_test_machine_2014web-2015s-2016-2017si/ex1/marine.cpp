//
// marine.cpp for marine in /exam//rendu/ex1
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Fri Jan 18 19:03:23 2013 lyoma guillou
// Last update Fri Jan 18 19:21:50 2013 lyoma guillou
//

#include <iostream>
#include <string>

#include "unit.h"
#include "marine.h"

marine::marine(std::string const name, int posX, int posY)
  : unit(name, "Marine", posX, posY, 6, 40, 40)
{
  std::cout << "Do you want a piece of me, boy ?" << std::endl;
}

marine::marine(marine const &other) : unit(other)
{
  std::cout << "Do you want a piece of me, boy ?" << std::endl;
}

marine::~marine(void)
{
  std::cout << "Aaaargh..." << std::endl;
}

void marine::move(int x, int y)
{
  this->posX = x;
  this->posY = y;
  std::cout << "Rock'n'roll !!!" << std::endl;
}

void marine::stimpack(void)
{
  this->dam += 1;
  this->cHP -= 10;
  std::cout << "Ho yeah..." << std::endl;
}

marine& marine::operator=(marine const &other)
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
