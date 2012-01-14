/*
** str_utils.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 21 14:03:03 2011 lyoma guillou
** Last update Sun Jan  1 22:30:25 2012 lyoma guillou
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_sh.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char	*my_strfus(char *str, char *ptr)
{
  char	*src;
  int	i;

  i = 0;
  if ((src = malloc((my_strlen(str) + my_strlen(ptr)) * sizeof(*src))) == NULL)
    return (NULL);
  while (i < (my_strlen(str) + my_strlen(ptr)))
    {
      if (i >= my_strlen(str))
	src[i] = ptr[i - my_strlen(str)];
      else
	src[i] = str[i];
      i = i + 1;
    }
  src[i] = '\0';
  return (src);
}
