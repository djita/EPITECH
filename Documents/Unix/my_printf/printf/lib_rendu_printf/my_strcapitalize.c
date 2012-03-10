/*
** my_strcapitalize.c for my_strcapitalize in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct 10 14:46:13 2011 lyoma guillou
** Last update Wed Nov 16 14:35:49 2011 lyoma guillou
*/

#include "my.h"

char	*my_strcapitalize(char *str)
{
  int	i;
  int	x;

  i = 0;
  x = 1;
  while (str[i])
    {
      if (x == 1)
	{
	  if (is_low_alpha(str[i]) == 1)
	    str[i] = str[i] - ('a' - 'A');
	  x = 0;
	}
      if (is_low_alpha(str[i]) == 0 && is_up_alpha(str[i]) == 0)
	x = 1;
      if (is_num(str[i]))
	x = 0;
      i++;
    }
  return (str);
}
