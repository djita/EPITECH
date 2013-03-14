#ifndef BANELING_H_
#define BANELING_H_

#include "AUnit.hpp"

class Baneling : public AUnit
{
public:
  Baneling();
  Baneling(Baneling const &);
  explicit Baneling(AUnit const &);
  ~Baneling();

  void attack(int x, int y);
  void move(int x, int y);
  Baneling & operator=(AUnit const &);
};

#endif
