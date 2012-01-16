/*
** my_strupcase.c for my_strupcase in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct 10 14:13:25 2011 lyoma guillou
** Last update Wed Nov 16 14:35:46 2011 lyoma guillou
*/

#include "my.h"

int	is_minialpha(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      str[i] = str[i] - ('a' - 'A');
      i++;
    }
  return (str);
}