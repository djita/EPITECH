/*
** string.c for infin_mult in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 24 10:36:10 2011 exam_user
** Last update Thu Nov 24 12:17:35 2011 exam_user
*/

#include <stdlib.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

int		is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

char		*my_revstr(unsigned char *str)
{
  int		i;
  int		j;
  char		*dst;

  i = 0;
  j = 0;
  while (str[i])
    i++;
  if ((dst = malloc(i * sizeof(*dst))) == NULL)
    return (NULL);
  i = i - 1;
  while (i >= 0)
    {
      dst[j] = str[i];
      i--;
      j++;
    }
  return (dst);
}

int		my_numlen(unsigned char *str)
{
  int		i;

  i = 0;
  while (str[i])	
    i++;
  if (str[0] == '-')
    return (i - 1);
  return (i);
}
