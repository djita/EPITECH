//
// LittlePony.cpp for LittlePony in /home/guillo_e//Documents/working/tek2/piscine/Rush2/workspace
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Sat Jan 19 11:41:47 2013 lyoma guillou
// Last update Sat Jan 19 14:15:11 2013 lyoma guillou
//

#include <string>
#include <iostream>

#include "Toy.h"
#include "LittlePony.h"

LittlePony::LittlePony(std::string const &title) : Toy(title)
{

}

LittlePony::LittlePony(LittlePony const &other) : Toy(other.getTitle())
{

}

LittlePony::~LittlePony(void)
{

}

bool	LittlePony::isTaken(void)
{
  if (this->Taken)
    std::cout << "yo man" << std::endl;
  return this->Taken;
}
