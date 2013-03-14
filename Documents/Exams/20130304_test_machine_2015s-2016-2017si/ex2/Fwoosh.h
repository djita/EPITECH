#ifndef FWOOSH_H_
#define FWOOSH_H_

#include "ASpell.h"

class Fwoosh : public ASpell
{
 public:
  Fwoosh();

  virtual Fwoosh * clone();
};

#endif
