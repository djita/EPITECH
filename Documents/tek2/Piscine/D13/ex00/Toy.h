#ifndef TOY_H_
#define TOY_H_

#include <string>

#include "Picture.h"

class Toy
{
 public:
  enum ToyType
  {
    BASIC_TOY,
    ALIEN
  };

  ToyType type;
  std::string name;
  Picture *pic;

  Toy();
  Toy(ToyType type, std::string const &name, std::string const &filename);

  int getType() const;
  std::string const getName() const;

  void setName(std::string const &name);

  bool setAscii(std::string const &filename);
  std::string const &getAscii() const;
};

#endif
