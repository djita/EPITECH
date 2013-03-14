//
// droid.hh for droid in /home/guillo_e//Documents/working/tek2/piscine/D08/ex00
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Wed Jan 16 09:06:49 2013 lyoma guillou
// Last update Wed Jan 16 16:57:28 2013 lyoma guillou
//

#ifndef DROID_H_
# define DROID_H_

# include <string>

# include "droidmemory.hh"

class		Droid
{
  std::string	Id;
  size_t	Energy;
  size_t const	Attack;
  size_t const	Toughness;
  std::string*	Status;

  DroidMemory*	BattleData;

public:
  Droid(std::string);
  Droid(Droid const &);
  ~Droid(void);

  std::string	getId(void) const;
  size_t	getEnergy(void) const;
  size_t	getAttack(void) const;
  size_t	getToughness(void) const;
  std::string	getStatus(void) const;
  void		setId(std::string);
  void		setEnergy(size_t);
  void		setStatus(std::string*);

  Droid&	operator=(Droid const &);
  Droid&	operator<<(size_t &);
  bool		operator==(Droid const &) const;
  bool		operator!=(Droid const &) const;
  bool		operator()(std::string const *, size_t);
};

std::ostream&	operator<<(std::ostream&, Droid const &);

#endif
