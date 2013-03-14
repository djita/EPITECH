#ifndef ZERGLING_H_
#define ZERGLING_H_

#include "AUnit.hpp"

class Zergling : public AUnit
{
public:
  Zergling();
  Zergling(Zergling const &);
  explicit Zergling(AUnit const &);
  ~Zergling();

  virtual void attack(int x, int y);
  virtual void move(int x, int y);
  Zergling & operator=(AUnit const &);
};

#endif
