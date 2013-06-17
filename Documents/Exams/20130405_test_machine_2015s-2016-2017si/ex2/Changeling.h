#ifndef CHANGELING_H_
#define CHANGELING_H_

#include "IChangeling.h"

class Changeling : public IChangeling
{
 private:
  std::string		name;
  int			age;
  int			height;
  int			weight;
  IChangeling::status	status;

 public:
  Changeling();
  Changeling(std::string _name);
  Changeling(std::string _name, int _age, int _height, int _weight);

  Changeling(Changeling const &other);

  virtual ~Changeling();

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

  virtual IChangeling::status	getStatus() const;
  virtual void		liquefy();
  virtual void		solidify();

  Changeling & operator=(Changeling const &other);
};

#endif
