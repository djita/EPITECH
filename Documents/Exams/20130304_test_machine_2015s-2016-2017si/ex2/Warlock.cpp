#include "Warlock.h"
#include <cstdlib>
#include <string>
#include <iterator>
#include <iostream>

Warlock::Warlock(std::string name) : name(name)
{
  std::cout << name << ": This looks like another boring day." << std::endl; 
}

Warlock::Warlock(Warlock const & other) : name(other.name), titles(other.titles) {}
Warlock::~Warlock()
{
  std::cout << name << ": Ahhh, I see it clearly. This is the plane of SUCK..." << std::endl;
}

std::string Warlock::getName() const { return this->name; }
void Warlock::addTitle(std::string const & title) { titles.push_back(title); }
void Warlock::removeTitle(std::string const & title)
{
  std::list<std::string>::iterator it;

  it = titles.begin();
  while (it != titles.end())
    {
      if (*it == title)
	it = titles.erase(it);
      ++it;
    }
}

void Warlock::addQuote(std::string const & quote) { quotes.push_back(quote); }
void Warlock::removeQuote(std::string const & quote)
{
  std::list<std::string>::iterator it;

  it = quotes.begin();
  while (it != quotes.end())
    {
      if (*it == quote)
	it = quotes.erase(it);
      ++it;
    }
}

void Warlock::introduce()
{
  std::list<std::string>::iterator it;

  std::cout << name << ": I am " << name;
  if (!titles.empty())
    {
      it = titles.begin();
      while (it != titles.end())
	{
	  std::cout << ", ";
	  std::cout << *it;
	  ++it;
	}
    }
  std::cout << " ! And the mayor of a little village on the coast. ";
  std::cout << "Very scenic during springtime, you should visit sometime !" << std::endl;
}

void Warlock::talk() const
{
  std::list<std::string>::const_iterator it;
  unsigned int x;

  if (!quotes.empty())
    {
      it = quotes.begin();
      for (x = rand() % quotes.size(); x > 0; --x)
	++it;
      std::cout << name << ": " << *it << std::endl; 
    }
}

void Warlock::learnSpell(ASpell * spell) { this->spell = spell; }
void Warlock::forgetSpell(std::string spellname)
{
  if (spell.getName() == spellname)
    spell = NULL;
}

void Warlock::launchSpell(std::string spellname, ATarget & target)
{
  if (spell.getName() == spellname)
    spell->launch(target);
}

Warlock const & Warlock::operator=(Warlock const &other)
{
  name = other.name;
  titles = other.titles;
  return *this;
}
