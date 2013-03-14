/*
** sickkoalalist.h for sickkoalalist in /home/guillo_e//Documents/working/tek2/piscine/D06/ex05
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Jan 14 20:33:16 2013 lyoma guillou
** Last update Mon Jan 14 21:00:25 2013 lyoma guillou
*/

#ifndef SICKKOALALIST_H_
# define SICKKOALALIST_H_

# include <string>

# include "sickkoala.h"

class			SickKoalaList
{
  SickKoala		*koala;
  SickKoalaList		*next;

 public:
  SickKoalaList(SickKoala *);
  ~SickKoalaList();

  bool			isEnd();
  void			append(SickKoalaList *);
  SickKoala*		getFromName(std::string);
  SickKoalaList*	remove(SickKoalaList*);

};

#endif
