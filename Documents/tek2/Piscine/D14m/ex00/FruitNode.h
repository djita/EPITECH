#ifndef FRUITNODE_H_
#define FRUITNODE_H_

#include "Fruit.h"

class FruitNode
{ 
 public:
  Fruit *_fruit;
  FruitNode *_next;

  FruitNode();

  std::string const & getFruitName() const;
};

#endif
