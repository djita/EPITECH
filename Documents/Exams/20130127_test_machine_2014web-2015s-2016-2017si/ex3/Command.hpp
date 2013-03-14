#ifndef COMMAND_H_
#define COMMAND_H_

#include "ICommand.hpp"

template<class T>
class Command<T> : public ICommand
{
public:
  T *unit;
  int _x;
  int _y;
  void (T::fct)(int x, int y);

  Command<T>(T *unit, &T::ptr, int x, int y) : _x(x), _y(y), fct(ptr) {}
  virtual void execute() { this->unit->fct(x, y); }
};

#endif
