#include "Warlock.h"
#include <string>
#include <iostream>

Warlock::Warlock(std::string _name, std::string _title) : name(_name), title(_title)
{
  std::cout << name << ": This looks like another boring day." << std::endl; 
}

Warlock::Warlock(Warlock const & other) : name(other.name), title(other.title) {}
Warlock::~Warlock()
{
  std::cout << name << ": Ahhh, I see it clearly. This is the plane of SUCK..." << std::endl;
}

std::string Warlock::getName() const { return this->name; }
std::string Warlock::getTitle() const { return this->title; }

void Warlock::setTitle(std::string title) { this->title = title; }

void Warlock::introduce() const
{
  std::cout << name << ": I am " << name << ", " << title << " !" << std::endl;
}

Warlock const & Warlock::operator=(Warlock const &other)
{
  name = other.name;
  title = other.title;
  return *this;
}

