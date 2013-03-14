#include <iostream>
#include "ICommand.hpp"
#include "Controller.hpp"

void Controller::addTask(ICommand *cmd)
{
  this->_tasks.push_back(cmd);
  std::cout << "Tache ajoutee" << std::endl;
}

void Controller::execute()
{
  if (3 > this->_tasks.size())
    std::cout << "Nombre de taches inferieur a 3" << std::endl;
  else
    {
      std::iterator iT = this->_tasks.front();
      while (iT != iT.end())
	{
	  iT.front()->execute();
	  iT++;
	}
    }
}
