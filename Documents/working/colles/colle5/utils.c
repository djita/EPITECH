/*
** utils.c for utils.c in /home/deleta_m//Projets/Colles/Colle_5
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May 14 19:19:33 2012 marc deletang
** Last update Mon May 14 20:49:02 2012 lyoma guillou
*/

#include <stdlib.h>
#include <unistd.h>

#include "game_of_life.h"

int	xread(int fd, char *buff, int size)
{
  int	ret;

  ret = read(fd, buff, size);
  if (ret < 0)
    {
      my_putstr("Read Error\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

void	*xmalloc(int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (!ptr)
    {
      my_putstr("Malloc Error\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}

void	*my_memset(void *ptr, int c, int len)
{
  int	i;
  int	*tmp;

  i = 0;
  tmp = ptr;
  while (i <= len)
    {
      tmp[i] = c;
      ++i;
    }
  return (ptr);
}

void	my_bzero(void *ptr, int len)
{
  int	i;
  int	*tmp;

  i = 0;
  tmp = ptr;
  while (i < len)
    {
      tmp[i] = 0;
      ++i;
    }
}
