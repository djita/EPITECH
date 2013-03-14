//
// Object.cpp for Object in /home/guillo_e//Documents/working/tek2/piscine/Rush2/workspace
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Sat Jan 19 13:53:38 2013 lyoma guillou
// Last update Sat Jan 19 14:12:11 2013 lyoma guillou
//

#include <string>

#include "Object.h"

Object::Object(std::string const &title) : Taken(false), Title(title)
{

}

Object::~Object(void)
{

}

std::string const &	Object::getTitle(void) const
{
  return this->Title;
}
