#include <iostream>
#include <string>
#include "building.h"

building::building(std::string const name, std::string const type, int posX, int posY, int cHP, int mHP, bool isFlying) : name(name), type(type), posX(posX), posY(posY), cHP(cHP), mHP(mHP), isFlying(isFlying)
{

}

building::building(std::string const type, int posX, int posY) 
  : name(""), type(type), posX(posX), posY(posY), cHP(0), mHP(0), isFlying(false)
{

}

building::~building()
{

}

std::string const building::getName(void) const
{
  return this->name;
}

std::string const building::getType(void) const
{
  return this->type;
}

int building::getPosX() const
{
  return this->posX ;
}

int building::getPosY() const
{
  return this->posY;
}

int building::getCHP() const
{
  return this->cHP;
}

int building::getMHP() const
{
  return this->mHP;
}
 
bool building::isFlying() const
{
  return this->isFlying_;
}

void building::fly(int x, int y)
{
  if (true == this->isFlying_)
    std::cout << "Building's already flying, sir !";
  else
    {
      std::cout << "Flying sequence started, sir ! Moving to " << x << "/" << y << ".";
      this->posX = x;
      this->posY = y;
    }
  std::cout << std::endl;
}

void building::land(void)
{
  if (true == this->isFlying_)
    std::cout << "Landing sequence started !";
  else
    std::cout << "Building's not flying sir !";
  std::cout << std::endl;
}

building& building::operator+=(int heal)
{
  if (this->cHP > 0)
    {
      this->cHP += heal;
      if (this->cHP > this->mHP)
	this->cHP = this->mHP;
    }
}

building& building::operator-=(int dmg)
{
  if (this->cHP > 0)
    {
      this->cHP -= dmg;
      if (this->cHP <= 0)
	this->cHP = 0;
    }
}

std::ostream& operator<<(std::ostream& os, building const &building)
{
  os << "The building is a " << ((building.isFlying()) ? "flying " : "landed ");
  os << building.getName() << " in " << building.getPosX() << "/" << building.getPosY();
  os << " with " << building.getCHP() << "HP." <<std::endl;
  return os;
}
