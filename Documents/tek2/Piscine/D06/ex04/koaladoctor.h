/*
** koaladoctor.h for koaladoctor in /home/guillo_e//Documents/working/tek2/piscine/D06/ex04
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Jan 14 17:43:58 2013 lyoma guillou
** Last update Mon Jan 14 18:58:40 2013 lyoma guillou
*/

#ifndef KOALADOCTOR_H_
# define KOALADOCTOR_H_

# include <string>
# include "sickkoala.h"

class	KoalaDoctor
{
  std::string	name;
  size_t	status;

 public:
  KoalaDoctor(std::string);
  ~KoalaDoctor();

  void	diagnose(SickKoala *);
  void	timeCheck(void);
};

#endif
