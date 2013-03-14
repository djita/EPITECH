/*
** LittlePony.h for LittlePony in /home/guillo_e//Documents/working/tek2/piscine/Rush2/workspace
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Jan 19 11:39:36 2013 lyoma guillou
** Last update Sat Jan 19 14:15:10 2013 lyoma guillou
*/

#ifndef LITTLEPONY_H_
# define LITTLEPONY_H_

# include <string>

# include "Object.h"

class LittlePony : virtual public Toy
{
 public:
  LittlePony(std::string const &title = "LittlePony");
  LittlePony(LittlePony const &);
  ~LittlePony(void);

  virtual bool	isTaken(void);
};

#endif
