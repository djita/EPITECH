#ifndef ICOMMAND_H_
#define ICOMMAND_H_

class ICommand
{
public:
  virtual ~ICommand();

  virtual void execute() = 0;  
};

#endif
