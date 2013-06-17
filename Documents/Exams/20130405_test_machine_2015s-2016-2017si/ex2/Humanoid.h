#ifndef HUMANOID_H_
#define HUMANOID_H_

#include "IHumanoid.h"

class Humanoid : public IHumanoid
{
 private:
  std::string	name;
  int		age;
  int		height;
  int		weight;

 public:
  Humanoid();
  Humanoid(std::string _name);
  Humanoid(std::string _name, int _age, int _height, int _weight);

  Humanoid(Humanoid const &other);

  virtual ~Humanoid();

  virtual void	walk();
  virtual void	run();

  virtual std::string const &	getName() const;
  virtual void			setName(std::string _name);

  virtual int		getHeight() const;
  virtual void		setHeight(int _height);

  virtual int		getWeight() const;
  virtual void		setWeight(int _weight);

  virtual int		getAge() const;
  virtual void		setAge(int _age);  

  Humanoid & operator=(Humanoid const &other);
};

#endif
