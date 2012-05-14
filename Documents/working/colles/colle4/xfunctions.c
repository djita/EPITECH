/*
** xfunctions.c for xfunctions in /home/deleta_m//Projets/Colles/Colle_4
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May  7 19:38:44 2012 marc deletang
** Last update Mon May  7 21:22:34 2012 lyoma guillou
*/

#include <unistd.h>
#include <stdlib.h>

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    exit(1);
  return (ptr);
}

int		xwrite(int fd, char *buff, int size)
{
  int		ret;

  ret = write(fd, buff, size);
  if (ret < 0)
    exit(1);
  return (ret);
}
