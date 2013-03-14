//
// carrier.hh for carrier in /home/guillo_e//Documents/working/tek2/piscine/D08/ex03
// 
// Made by lyoma guillou
// Login   <guillo_e@epitech.net>
// 
// Started on  Wed Jan 16 17:28:32 2013 lyoma guillou
// Last update Wed Jan 16 21:51:49 2013 lyoma guillou
//

#ifndef CARRIER_H_
# define CARRIER_H_

# include <iostream>
# include <string>

# include "droid.hh"

class		Carrier
{
  std::string	Id;
  size_t	Energy;
  size_t const	Attack;
  size_t const	Toughness;
  size_t	Speed;
  Droid*	Droids[5];

public:
  Carrier(std::string);
  ~Carrier(void);

  std::string	getId(void) const;
  size_t	getEnergy(void) const;
  size_t	getAttack(void) const;
  size_t	getToughness(void) const;
  size_t	getSpeed(void) const;
  size_t	getNbDroids(void) const;

  Carrier&	operator<<(Droid*&);
  Carrier&	operator<<(size_t &);
  Carrier&	operator>>(Droid*&);
  Droid*&	operator[](size_t);
  Droid*	operator[](size_t) const;
  bool		operator()(size_t, size_t);
  Carrier&	operator~();
};

std::ostream&	operator<<(std::ostream&, Carrier const &);

#endif 
