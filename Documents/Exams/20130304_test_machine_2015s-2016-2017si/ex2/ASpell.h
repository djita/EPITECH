#ifndef ASPELL_H_
#define ASPELL_H_

#include "ATarget.h"
#include <string>

class ASpell
{
 protected:
  std::string name;
  std::string effects;

 public:
  ASpell(std::string _name, std::string _effects);
  ASpell(ASpell const &);
  ~ASpell();

  std::string getName() const;
  std::string getEffects() const;

  void launch(ATarget const target);

  virtual ASpell * clone() = 0;

  ASpell & operator=(ASpell const &);
};

#endif
