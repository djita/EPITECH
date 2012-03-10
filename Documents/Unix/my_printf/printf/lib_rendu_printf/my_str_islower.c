/*
** my_str_islower.c for my_str_islower in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct 10 18:54:45 2011 lyoma guillou
** Last update Wed Nov 16 14:35:48 2011 lyoma guillou
*/

#include "my.h"

int	is_low_alpha(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  if (str[0] != '\0')
    {
      while (str[i])
	{
	  if (is_low_alpha(str[i]))
	    return (0);
	  i++;
	}
    }
  return (1);
}
