#ifndef IFERENGI_H_
#define IFERENGI_H_

#include "IHumanoid.h"

#include <string>

class IFerengi : public IHumanoid
{
 public:
  virtual ~IFerengi() {};

  virtual void	walk() = 0;
  virtual void	run() = 0;

  virtual std::string const &	getName() const = 0;
  virtual void			setName(std::string _name) = 0;

  virtual int		getHeight() const = 0;
  virtual void		setHeight(int _height) = 0;

  virtual int		getWeight() const = 0;
  virtual void		setWeight(int _weight) = 0;

  virtual int		getAge() const = 0;
  virtual void		setAge(int _age) = 0;
};

#endif
