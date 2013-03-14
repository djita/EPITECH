/*
** Teddy.h for Teddy in /home/guillo_e//Documents/working/tek2/piscine/Rush2/workspace
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Jan 19 11:40:31 2013 lyoma guillou
** Last update Sat Jan 19 14:15:10 2013 lyoma guillou
*/

#ifndef TEDDY_H_
# define TEDDY_H_

# include <string>

# include "Object.h"

class Teddy : virtual public Toy
{
 public:
  Teddy(std::string const &title = "Teddy");
  Teddy(Teddy const &);
  ~Teddy(void);

  virtual bool	isTaken(void);
};

#endif
