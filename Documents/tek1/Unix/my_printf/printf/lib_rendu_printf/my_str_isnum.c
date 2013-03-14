/*
** my_str_isnum.c for my_str_isnum in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct 10 18:35:29 2011 lyoma guillou
** Last update Wed Nov 16 14:35:48 2011 lyoma guillou
*/

#include "my.h"

int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  if (str[0] != '\0')
    {  
      while (str[i])
	{
	  if (is_num(str[i]))
	    return (0);
	  i++;
	}
    }
  return (1);
}
