#ifndef FRUIT_H_
#define FRUIT_H_

#include <string>

class Fruit
{
 protected:
  std::string _name;
  int _vitamins;

  Fruit();
  Fruit(std::string const &, int);
  ~Fruit();

 public:
  int getVitamins() const;
  virtual std::string const & getName() const = 0;

  Fruit & operator=(Fruit const &);
};

#endif
