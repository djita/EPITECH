#include <iostream>

#include "IHumanoid.h"
#include "IChangeling.h"
#include "IFerengi.h"

#include "Humanoid.h"
#include "Changeling.h"
#include "Ferengi.h"

template<typename T>void	rip(T ** const & other)
{
  (void) other;
  std::cout << "YOU NO WERK?" << std::endl;
}

template<Ferengi &>void		rip(Ferengi * const & other)
{
  (void) other;
  std::cout << "Ferengi: Welcome my brother!!" << std::endl;
}

template<Changeling &>void	Ferengi::rip(Changeling * const & other)
{
  (void) other;
  std::cout << "Ferengi: All changeling must die!!" << std::endl;
}

template<Humanoid &>void	Ferengi::rip(Humanoid * const & other)
{
  (void) other;
  std::cout << "Ferengi: I can rip you off fucking humanoid!!" << std::endl;
}


Ferengi::Ferengi()
  : name(""), age(0), height(0), weight(0)
{
  std::cout << "Ferengi: I'm born!!" << std::endl;
}

Ferengi::Ferengi(std::string _name)
  : name(_name), age(0), height(0), weight(0)
{
  std::cout << "Ferengi: I'm born!!" << std::endl;
}

Ferengi::Ferengi(std::string _name, int _age, int _height, int _weight)
  : name(_name), age(_age), height(_height), weight(_weight)
{
  std::cout << "Ferengi: I'm born!!" << std::endl;
}

Ferengi::Ferengi(Ferengi const &other)
  : name(other.name), age(other.age), height(other.height), weight(other.weight) {}

Ferengi::~Ferengi() { std::cout << "Ferengi: I die!!" << std::endl; }

void	Ferengi::walk() { std::cout << "Ferengi: I’m walking sir." << std::endl; }
void	Ferengi::run() { std::cout << "Ferengi: I’m running sir." << std::endl; }

std::string const &	Ferengi::getName() const
{
  std::cout << "Ferengi: I’m giving my name." << std::endl;
  return name;
}

void			Ferengi::setName(std::string _name)
{
  std::cout << "Ferengi: I’m setting my name." << std::endl;
  name = _name;
}

int		Ferengi::getHeight() const
{
  std::cout << "Ferengi: I’m giving my height." << std::endl;
  return height;
}

void		Ferengi::setHeight(int _height)
{
  std::cout << "Ferengi: I’m setting my height." << std::endl;
  height = _height;
}

int		Ferengi::getWeight() const
{
  std::cout << "Ferengi: I’m giving my weight." << std::endl;
  return weight;
}

void		Ferengi::setWeight(int _weight)
{
  std::cout << "Ferengi: I’m setting my weight." << std::endl;
  weight = _weight;
}

int		Ferengi::getAge() const
{
  std::cout << "Ferengi: I’m giving my age." << std::endl;
  return age;
}

void		Ferengi::setAge(int _age)
{
  std::cout << "Ferengi: I’m setting my age." << std::endl;
  age = _age;
}

Ferengi&	Ferengi::operator=(Ferengi const &other)
{
  name = other.name;
  age = other.age;
  height = other.height;
  weight = other.weight;
  return *this;
}
