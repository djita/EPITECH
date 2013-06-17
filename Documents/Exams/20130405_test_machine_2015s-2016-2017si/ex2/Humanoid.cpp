#include <iostream>

#include "IHumanoid.h"
#include "Humanoid.h"

Humanoid::Humanoid()
  : name(""), age(0), height(0), weight(0)
{
  std::cout << "Humanoid: I'm born!!" << std::endl;
}

Humanoid::Humanoid(std::string _name)
  : name(_name), age(0), height(0), weight(0)
{
  std::cout << "Humanoid: I'm born!!" << std::endl;
}

Humanoid::Humanoid(std::string _name, int _age, int _height, int _weight)
  : name(_name), age(_age), height(_height), weight(_weight)
{
  std::cout << "Humanoid: I'm born!!" << std::endl;
}

Humanoid::Humanoid(Humanoid const &other)
  : name(other.name), age(other.age), height(other.height), weight(other.weight) {}

Humanoid::~Humanoid() { std::cout << "Humanoid: I die!!" << std::endl; }

void	Humanoid::walk() { std::cout << "Humanoid: I’m walking sir." << std::endl; }
void	Humanoid::run() { std::cout << "Humanoid: I’m running sir." << std::endl; }

std::string const &	Humanoid::getName() const
{
  std::cout << "Humanoid: I’m giving my name." << std::endl;
  return name;
}

void			Humanoid::setName(std::string _name)
{
  std::cout << "Humanoid: I’m setting my name." << std::endl;
  name = _name;
}

int		Humanoid::getHeight() const
{
  std::cout << "Humanoid: I’m giving my height." << std::endl;
  return height;
}

void		Humanoid::setHeight(int _height)
{
  std::cout << "Humanoid: I’m setting my height." << std::endl;
  height = _height;
}

int		Humanoid::getWeight() const
{
  std::cout << "Humanoid: I’m giving my weight." << std::endl;
  return weight;
}

void		Humanoid::setWeight(int _weight)
{
  std::cout << "Humanoid: I’m setting my weight." << std::endl;
  weight = _weight;
}

int		Humanoid::getAge() const
{
  std::cout << "Humanoid: I’m giving my age." << std::endl;
  return age;
}

void		Humanoid::setAge(int _age)
{
  std::cout << "Humanoid: I’m setting my age." << std::endl;
  age = _age;
}

Humanoid&	Humanoid::operator=(Humanoid const &other)
{
  name = other.name;
  age = other.age;
  height = other.height;
  weight = other.weight;
  return *this;
}
