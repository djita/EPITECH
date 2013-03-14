#ifndef FRUITBOX_H_
#define FRUITBOX_H_

#include "Fruit.h"
#include "FruitNode.h"

class FruitBox
{
  FruitNode* _box;
  int _size;

 public:
  FruitBox(int size = 0);
  ~FruitBox();

  int nbFruits() const;
  bool putFruit(Fruit *f);
  Fruit* pickFruit();
  FruitNode* head() const;
};

#endif
