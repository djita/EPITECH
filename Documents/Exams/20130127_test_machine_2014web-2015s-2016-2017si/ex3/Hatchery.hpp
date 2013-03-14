#ifndef HATCHERY_H_
#define HATCHERY_H_

#include "AUnit.hpp"

class Hatchery
{
public:
  template<typename T>
  static AUnit * create()
  {
    return new T();
  }
};

#endif
