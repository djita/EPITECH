#ifndef OVERSEER_H_
#define OVERSEER_H_

#include "AUnit.hpp"

class Overseer : public AUnit
{
public:
  Overseer();
  Overseer(Overseer const &);
  explicit Overseer(AUnit const &);
  ~Overseer();

  void attack(int x, int y);
  void move(int x, int y);
  Overseer & operator=(AUnit const &);
};

#endif
