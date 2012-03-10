/*
** my_strdup.c for my_strdup in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Oct 12 09:11:47 2011 lyoma guillou
** Last update Wed Oct 12 09:28:16 2011 lyoma guillou
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

void	*xmalloc(int size)
{
  char	*ptr;

  ptr = malloc(size * sizeof(char));
  if (ptr == NULL)
    return (NULL);
  return (ptr);
}

char	*my_strdup(char *src)
{
  int	i;
  int	j;
  char	*dup;

  i = my_strlen(src);
  j = 0;
  dup = xmalloc(i);
  while (j <= i)
    {
      dup[j] = src[j];
      j++;
    }
  return (dup);
}
