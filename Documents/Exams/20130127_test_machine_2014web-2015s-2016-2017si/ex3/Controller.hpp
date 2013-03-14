#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <list>
#include "ICommand.hpp"

class Controller
{
public:
  std::list<ICommand *> _tasks;
  void addTask(ICommand *);
  void execute();
};

#endif
