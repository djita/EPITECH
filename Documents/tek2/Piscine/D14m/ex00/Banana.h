#ifndef BANANA_H_
#define BANANA_H_

class Banana : public Fruit
{
 public:
  Banana();
  ~Banana();

  virtual std::string const & getName() const;
};

#endif
