#ifndef OVERLORD_H_
#define OVERLORD_H_

#include "AUnit.hpp"

class Overlord : public AUnit
{
public:
  Overlord();
  Overlord(const Overlord &);
  explicit Overlord(const AUnit &);
  ~Overlord();

  virtual void attack(int x, int y);
  virtual void move(int x, int y);
  Overlord const & operator=(AUnit const &);
};

#endif
