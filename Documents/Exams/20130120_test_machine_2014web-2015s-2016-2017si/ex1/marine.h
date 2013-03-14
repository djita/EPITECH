/*
** marine.h for marine in /exam//rendu/ex1
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Jan 18 19:03:27 2013 lyoma guillou
** Last update Fri Jan 18 19:16:06 2013 lyoma guillou
*/

#ifndef MARINE_H_
#define MARINE_H_

#include <iostream>
#include <string>

#include "unit.h"

class marine : virtual public unit
{
 public:
  marine(std::string const name = "", int posX = 0, int posY = 0);
  marine(marine const &);
  ~marine(void);

  void move(int x, int y);
  void stimpack(void);
  marine& operator=(marine const &);
};

#endif
