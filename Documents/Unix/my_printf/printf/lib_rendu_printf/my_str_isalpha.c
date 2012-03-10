/*
** my_str_isalpha.c for my_str_isalpha in /home/guillo_e//afs/rendu/lib/my/cfiles
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Oct 11 12:33:18 2011 lyoma guillou
** Last update Wed Nov 16 14:35:48 2011 lyoma guillou
*/

#include "my.h"

int     is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

int     my_str_isalpha(char *str)
{
  int   i;

  i = 0;
  if (str[0] != '\0')
    {
      while (str[i])
        {
          if (is_alpha(str[i]) == 0)
            return (0);
          i++;
        }
    }
  return (1);
}
