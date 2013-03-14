#include <iostream>
#include <string>

#include "Picture.h"
#include "Toy.h"

Toy::Toy() : type(BASIC_TOY), name(""), pic(new Picture(""))
{

}

Toy::Toy(ToyType type, std::string const &name, std::string const &filename) 
  : type(type), name(name), pic(new Picture(filename))
{

}

int Toy::getType() const
{
  return this->type;
}

std::string const Toy::getName() const
{
  return this->name;
}

void Toy::setName(std::string const &name)
{
  this->name = name;
}

bool Toy::setAscii(std::string const &filename)
{
  if (filename.c_str())
    return this->pic->getPictureFromFile(filename);
  return false;
}

std::string const & Toy::getAscii() const
{
  return this->pic->data;
}
