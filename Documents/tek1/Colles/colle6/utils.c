/*
** utils.c for utils in /home/deleta_m//Projets/Colles/Colle_6
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May 21 19:36:23 2012 marc deletang
** Last update Mon May 21 20:09:46 2012 lyoma guillou
*/

#include <stdlib.h>
#include <unistd.h>

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

void	*xmalloc(int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (!ptr)
    {
      my_putstr("Error while allocating memory\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  if (my_strlen(str1) != my_strlen(str2))
    return (1);
  while (str1[i] && str2[i])
    {
      if (str1[i] != str2[i])
	return (str1[i] - str2[i]);
      i++;
    }
  return (0);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
