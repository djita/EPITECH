#ifndef ATARGET_H_
#define ATARGET_H_

#include "ASpell.h"
#include <string>

class ATarget
{
  std::string type;
 public:
  ATarget(std::string _type);
  ATarget(ATarget const &);
  ~ATarget();

  std::string getType() const;

  void getHitBySpell(ASpell const &);

  virtual ATarget * clone() = 0;

  ATarget & operator=(ATarget const &);
};

#endif
