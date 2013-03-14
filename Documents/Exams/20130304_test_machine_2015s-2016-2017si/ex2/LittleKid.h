#ifndef LITTLEKID_H_
#define LITTLEKID_H_

#include "ATarget.h"

class LittleKid : public ATarget
{
 public:
  LittleKid();

  virtual LittleKid * clone();
};

#endif
