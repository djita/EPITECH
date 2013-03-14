/*
** String.h for String in /home/guillo_e//Documents/working/tek2/piscine/D03/ex00
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Jan 11 09:04:12 2013 lyoma guillou
** Last update Fri Jan 11 09:17:15 2013 lyoma guillou
*/

#ifndef STRING_H_
# define STRING_H_

typedef struct	s_string
{
  char		*str;
}		String;

void		StringInit(String *this, char const *s);
void		StringDestroy(String *this);


#endif
