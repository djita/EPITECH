#ifndef ICHANGELING_H_
#define ICHANGELING_H_

#include <string>

#include "IHumanoid.h"

class IChangeling : public IHumanoid
{
 public:
  typedef enum
  {
    SOLID,
    LIQUID
  }	status;
	  
  virtual ~IChangeling() {};

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

  virtual IChangeling::status	getStatus() const = 0;
  virtual void		liquefy() = 0;
  virtual void		solidify() = 0;;
};

#endif
