#ifndef UNIT_H_
#define UNIT_H_

#include <iostream>
#include <string>

class unit
{
 protected:
  std::string const *name;
  std::string const *type;
  int posX;
  int posY;
  int dam;
  int cHP;
  int mHP;

 public:
  unit(std::string const name = "", std::string const type = "", 
       int posX = 0, int posY = 0, int dam = 0, int cHP = 0, int mHP = 0);
  unit(unit const &);
  ~unit();

  std::string const getName() const;
  std::string const getType() const;
  int getPosX() const;
  int getPosY() const;
  int getDam() const;
  int getCHP() const;
  int getMHP() const;
 
  unit& operator=(unit const &);
  unit& operator+=(int);
  unit& operator-=(int);
};

std::ostream& operator<<(std::ostream& os, unit const &_unit);

#endif
