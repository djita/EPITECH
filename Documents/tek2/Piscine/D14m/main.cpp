#include <iostream>
#include <string>

#include "Fruit.h"
#include "Lemon.h"
#include "Banana.h"
#include "FruitBox.h"
#include "FruitNode.h"

int main(void)
{
  FruitBox box(2);
  Lemon l;
  Banana b;

  std::cout << l.getVitamins() << std::endl;
  std::cout << b.getVitamins() << std::endl;
  std::cout << l.getName() << std::endl;
  std::cout << b.getName() << std::endl;
  Fruit& f = l;

  std::cout << f.getVitamins() << std::endl;
  std::cout << f.getName() << std::endl;

  std::cout << std::endl;
  std::cout << "list tests:" << std::endl;
  std::cout << std::boolalpha;
  std::cout << box.putFruit(&l) << std::endl;
  std::cout << box.putFruit(&b) << std::endl;
  std::cout << box.putFruit(&l) << std::endl;
  std::cout << std::noboolalpha << std::endl;
  box.pickFruit();
  std::cout << box.nbFruits() << std::endl;
  return 1337;
}
