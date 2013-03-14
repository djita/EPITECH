/*
** Toy.h for Toy in /home/guillo_e//Documents/working/tek2/piscine/Rush2/workspace
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Jan 19 11:35:33 2013 lyoma guillou
** Last update Sat Jan 19 14:10:13 2013 lyoma guillou
*/

#ifndef TOY_H_
# define TOY_H_

# include <string>

# include "Object.h"

class Toy : virtual public Object
{
 public:
  Toy(std::string const &name = "");
  Toy(Toy const &);
  ~Toy(void);

  virtual bool	isTaken(void) = 0;
  void		setTaken(bool);

  std::string const getToyName(void) const;
  Toy& operator=(Toy const &);
};

#endif
