#ifndef FERENGI_H_
#define FERENGI_H_

#include <iostream>

#include "IHumanoid.h"
#include "IChangeling.h"
#include "IFerengi.h"
#include "Humanoid.h"
#include "Changeling.h"

class Ferengi : public IFerengi
{
 private:
  std::string	name;
  int		age;
  int		height;
  int		weight;

 public:
  Ferengi();
  Ferengi(std::string _name);
  Ferengi(std::string _name, int _age, int _height, int _weight);

  Ferengi(Ferengi const &other);

  virtual ~Ferengi();

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

  template<typename T>void	rip(T * const & other);  
  template<Ferengi &>void	rip(Ferengi * const & other);
  template<Changeling &>void	rip(Changeling * const & other);
  template<Humanoid &>void	rip(Humanoid * const & other);

  Ferengi & operator=(Ferengi const &other);
};

#endif
