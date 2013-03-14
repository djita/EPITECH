#include "scv.h"
#include "IScv.h"
#include "unit.h"

scv::scv(std::string name, int posX, int posY)
  : unit(name, "SCV T-280", posX, posY, 5, 60, 60)
{
  this->_gold = 0;
  this->_gas = 0;
  std::cout << "SCV ready to go, sir." << std::endl;
}

scv::scv(scv const &other) : unit(other)
{
  this->_gold = other._gold;
  this->_gas = other._gas;
  std::cout << "SCV ready to go, sir." << std::endl;
}

scv::~scv(void)
{
  std::cout << "* noise of an exploding SCV *" << std::endl;
}

void	scv::gather(int x, int y, int type)
{
  if (type == 1 || type == 2)
    {
      this->posX = x;
      this->posY = y;
      std::cout << "Yes sir, I'm gathering " << ((type == 1) ? "gold" : "gas");
      std::cout << " in " << x << "/" << y << ".";
      (type == 1) ? this->_gold += 8 : this->_gas += 8;
    }
  else
    std::cout << "No way sir.";
  std::cout << std::endl;
}

void	scv::repair(int x, int y, std::string const &target)
{
  this->posX = x;
  this->posY = y;
  std::cout << "Yes sir, repairing " << target << " in ";
  std::cout << x << "/" << y << std::endl;
}

void	scv::buildCommandCenter(void)
{
  std::cout << "Command center finished sir !" << std::endl;
}

void	scv::buildBarrack(void)
{
  std::cout << "Barrack finished sir !" << std::endl;
}

void	scv::buildSupplyDepot(void)
{
  std::cout << "Supply depot finished sir !" << std::endl;
}

void	scv::buildBunker(void)
{
  std::cout << "Bunker finished sir !" << std::endl;
}

void	scv::createBuilding(int type)
{
  build[0] = &IScv::buildCommandCenter;
  build[1] = &IScv::buildBarrack;
  build[2] = &IScv::buildSupplyDepot;
  build[3] = &IScv::buildBunker;
  
  if (type >= 1 && type <= 4)
    (this->*build[type - 1])();
  else
    std::cout << "No such building sir !" << std::endl;
}
