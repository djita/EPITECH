#ifndef WARLOCK_H_
#define WARLOCK_H_

#include "ASpell.h"
#include "ATarget.h"
#include <string>
#include <list>

class Warlock
{
  std::string name;
  std::list<std::string> titles;
  std::list<std::string> quotes;

  ASpell * spell;

  Warlock(Warlock const &);
  Warlock const & operator=(Warlock const &);
 public:
  Warlock(std::string name);
  ~Warlock();

  std::string getName() const;
  void addTitle(std::string const & title);
  void removeTitle(std::string const & title);

  void addQuote(std::string const & quote);
  void removeQuote(std::string const & quote);

  void introduce();
  void talk() const;

  void learnSpell(ASpell *);
  void forgetSpell(std::string spellname);
  void launchSpell(std::string spellname, ATarget &);
};

#endif
