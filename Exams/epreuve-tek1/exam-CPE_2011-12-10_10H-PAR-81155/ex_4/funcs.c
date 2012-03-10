/*
** funcs.c for infin_mult in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 10 11:05:22 2011 exam_user
** Last update Sat Dec 10 11:43:58 2011 exam_user
*/

#include <stdlib.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char		*my_revstr(char *str)
{
  char		*rev;
  int		i;
  int		j;

  if ((rev = malloc(my_strlen(str) * sizeof(*rev))) == NULL)
    return (NULL);
  j = 0;
  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      rev[j] = str[i];
      j = j + 1;
      i = i - 1;
    }
  return (rev);
}

char		*my_strset(char *str, int len)
{
  int		i;

  i = 0;
  while (i < len)
    {
      str[i] = '\0';
      i = i + 1;
    }
  return (str);
}
