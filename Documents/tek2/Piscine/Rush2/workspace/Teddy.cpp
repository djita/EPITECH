//
// Teddy.cpp for Teddy in /home/guillo_e//Documents/working/tek2/piscine/Rush2/workspace
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Sat Jan 19 11:41:51 2013 lyoma guillou
// Last update Sat Jan 19 15:06:17 2013 lyoma guillou
//

#include <string>
#include <iostream>

#include "Toy.h"
#include "Teddy.h"

Teddy::Teddy(std::string const &title) : Toy(title)
{

}

Teddy::Teddy(Teddy const &other) : Toy(other.getTitle())
{

}

Teddy::~Teddy(void)
{
  
}

bool	Teddy::isTaken(void)
{
    std::cout << "gra hu" << std::endl;
}
