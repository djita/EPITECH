#include "Fruit.h"
#include "FruitBox.h"
#include "FruitNode.h"

FruitNode::FruitNode() : _fruit(NULL), _next(NULL) {}

std::string const & FruitNode::getFruitName() const { return this->_fruit->getName(); }

FruitBox::FruitBox(int size)
{
  FruitNode *first = new FruitNode();
  FruitNode *last = first;

  for (int i = 0; i < size; ++i)
    {
      FruitNode *tmp = new FruitNode();
      last->_next = tmp;
      last = last->_next;
    }
  last->_next = NULL;
  this->_box = first;
  this->_size = size;
}

FruitBox::~FruitBox()
{
  FruitNode* tmp;
  int len;

  tmp = this->_box;
  tmp = tmp->_next;
  len = this->_size;
  for (int i = 0; i < len; ++i)
    {
      tmp = tmp->_next;
      delete this->_box->_next;
      this->_box->_next = tmp;
    }
  delete this->_box;
}

int FruitBox::nbFruits() const
{
  FruitNode *tmp;
  int i = 0;
  
  tmp = this->_box;
  for (i = 0; NULL != tmp->_next; ++i)
    tmp = tmp->_next;
  return i;
}

bool FruitBox::putFruit(Fruit *f)
{
  FruitNode *tmp;
  int len;

  tmp = this->_box;
  len = this->_size;
  if (NULL != f)
    for (int i = 0; i < len && f != tmp->_fruit; ++i)
      {
	if (!tmp->_fruit)
	  {
	    tmp->_fruit = f;
	    return true;
	  }
	tmp = tmp->_next;
      }
  return false;
}

Fruit* FruitBox::pickFruit()
{
  FruitNode *tmp;
  Fruit *f;
  int len;

  tmp = this->_box;
  len = this->_size;
  for (int i = 0; i < len; ++i)
    if (NULL != tmp->_fruit)
      {
	f = tmp->_fruit;
	tmp->_fruit = NULL;
	return f;
      }
  return NULL;
}

FruitNode* FruitBox::head() const
{
  FruitNode* tmp;
  int len;

  tmp = this->_box;
  len = this->_size;
  for (int i = 0; i < len && NULL != tmp; ++i)
    tmp = tmp->_next;
  return tmp;
}
