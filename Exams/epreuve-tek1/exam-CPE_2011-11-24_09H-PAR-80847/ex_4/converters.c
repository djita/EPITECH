/*
** converters.c for infin_mult in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 24 11:49:10 2011 exam_user
** Last update Thu Nov 24 11:53:47 2011 exam_user
*/

#include <stdlib.h>

char		*my_memset(unsigned char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      str[i] = 0;
      i++;
    }
  return (str);
}

int		*char_to_int(unsigned char *str)
{
  int		i;
  int		*num;

  i = 0;
  if ((num = malloc(my_numlen(str) * sizeof(*num))) == NULL)
    return (NULL);
  while (str[i])
    {
      num[i] = str[i];
      i++;
    }
  return (num);
}

char		*int_to_char(int *num)
{
  int		i;
  char		*str;

  i = 0;
  if ((str = malloc(my_numlen(num) * sizeof(*num))) == NULL)
    return (NULL);
  while (num[i])
    {
      str[i] = num[i];
      i++;
    }
  return (str);
}
