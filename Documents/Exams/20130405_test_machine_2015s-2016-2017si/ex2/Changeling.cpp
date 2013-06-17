#include <iostream>

#include "IChangeling.h"
#include "Changeling.h"

Changeling::Changeling()
  : name(""), age(0), height(0), weight(0), status(IChangeling::SOLID)
{
  std::cout << "Changeling: I'm born!!" << std::endl;
}

Changeling::Changeling(std::string _name)
  : name(_name), age(0), height(0), weight(0), status(IChangeling::SOLID)
{
  std::cout << "Changeling: I'm born!!" << std::endl;
}

Changeling::Changeling(std::string _name, int _age, int _height, int _weight)
  : name(_name), age(_age), height(_height), weight(_weight), status(IChangeling::SOLID)
{
  std::cout << "Changeling: I'm born!!" << std::endl;
}

Changeling::Changeling(Changeling const &other)
  : name(other.name), age(other.age), height(other.height), weight(other.weight) {}

Changeling::~Changeling() { std::cout << "Changeling: I die!!" << std::endl; }

void	Changeling::walk() { std::cout << "Changeling: I’m walking sir." << std::endl; }
void	Changeling::run() { std::cout << "Changeling: I’m running sir." << std::endl; }

std::string const &	Changeling::getName() const
{
  std::cout << "Changeling: I’m giving my name." << std::endl;
  return name;
}

void			Changeling::setName(std::string _name)
{
  std::cout << "Changeling: I’m setting my name." << std::endl;
  name = _name;
}

int		Changeling::getHeight() const
{
  std::cout << "Changeling: I’m giving my height." << std::endl;
  return height;
}

void		Changeling::setHeight(int _height)
{
  std::cout << "Changeling: I’m setting my height." << std::endl;
  height = _height;
}

int		Changeling::getWeight() const
{
  std::cout << "Changeling: I’m giving my weight." << std::endl;
  return weight;
}

void		Changeling::setWeight(int _weight)
{
  std::cout << "Changeling: I’m setting my weight." << std::endl;
  weight = _weight;
}

int		Changeling::getAge() const
{
  std::cout << "Changeling: I’m giving my age." << std::endl;
  return age;
}

void		Changeling::setAge(int _age)
{
  std::cout << "Changeling: I’m setting my age." << std::endl;
  age = _age;
}

IChangeling::status	Changeling::getStatus() const { return status; }
void		Changeling::liquefy() { status = IChangeling::LIQUID; }
void		Changeling::solidify() { status = IChangeling::SOLID; }

Changeling&	Changeling::operator=(Changeling const &other)
{
  name = other.name;
  age = other.age;
  height = other.height;
  weight = other.weight;
  return *this;
}
