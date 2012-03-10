/*
** my_revstr.c for infin_add in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 12 10:54:13 2011 exam_user
** Last update Sat Nov 12 12:48:31 2011 exam_user
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_revstr(char *str)
{
  char	*dst;
  int	i;

  dst = malloc(my_strlen(str) * sizeof(*dst));
  if (dst == NULL)
    return (NULL);
  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      if (str[0] == '-')
	dst[my_strlen(str) -1 -i] = -str[i];
      else
	dst[my_strlen(str) -1 -i] = str[i];
      i = i - 1;
    }
  dst[my_strlen(str)] = '\0';
  return (dst);
}
