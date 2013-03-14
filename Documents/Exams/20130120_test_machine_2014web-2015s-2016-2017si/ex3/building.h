#ifndef BUILDING_H_
#define BUILDING_H_

#include <iostream>
#include <string>

class building
{
  std::string const *name;
  std::string const *type;
  int posX;
  int posY;
  int cHP;
  int mHP;
  bool isFlying_;

 public:
  building(std::string const name = "", std::string const type = "",
	   int posX = 0, int posY = 0, int cHP = 0, int mHP = 0, bool isFlying = false);
  building(std::string const type = "", int posX = 0, int posY = 0);
  ~building();

  std::string const getName() const;
  std::string const getType() const;
  int getPosX() const;
  int getPosY() const;
  int getCHP() const;
  int getMHP() const;
  bool isFlying() const;

  void fly(int, int);
  void land(void);

  building& operator+=(int);
  building& operator-=(int);
};

std::ostream& operator<<(std::ostream&, building const &);

#endif
