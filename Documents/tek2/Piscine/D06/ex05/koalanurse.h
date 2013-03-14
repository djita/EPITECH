/*
** koalanurse.h for koalanurse in /home/guillo_e//Documents/working/tek2/piscine/D06/ex03
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Jan 14 16:47:10 2013 lyoma guillou
** Last update Mon Jan 14 20:26:58 2013 lyoma guillou
*/

#ifndef KOALANURSE_H_
# define KOALANURSE_H_

# include <string>
# include "sickkoala.h"

class KoalaNurse
{
  int	id;
  int	status;

 public:
  KoalaNurse(int);
  ~KoalaNurse();

  void		giveDrug(std::string, SickKoala *);
  std::string	readReport(std::string);
  void		timeCheck(void);
  int		getID(void);
};

#endif
