/*
** sickkoala.h for sickkoala in /home/guillo_e//Documents/working/tek2/piscine/D06/ex02
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Jan 14 15:07:26 2013 lyoma guillou
** Last update Mon Jan 14 19:31:37 2013 lyoma guillou
*/

#ifndef SICKKOALA_H_
# define SICKKOALA_H_

# include <string>

class SickKoala
{
  std::string	name;

 public:
  SickKoala(std::string);
  ~SickKoala();
  
  void		poke();
  bool		takeDrug(std::string);
  void		overDrive(std::string);
  std::string	getName();
};

#endif
