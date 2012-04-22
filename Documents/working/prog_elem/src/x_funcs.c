/*
** x_funcs.c for lem-in in /home/guillo_e//Documents/working/prog_elem/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr  2 17:46:05 2012 lyoma guillou
** Last update Thu Apr  5 16:24:46 2012 lyoma guillou
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <parse.h>

int		xread(int fd, char *buffer, int len)
{
  int		ret;

  ret = read(fd, buffer, len);
  if (ret < 0)
    {
      fprintf(stderr, "Could not read\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int		xwrite(int fd, char *buffer, int len)
{
  int		ret;

  ret = write(fd, buffer, len);
  if (ret < 0)
    {
      fprintf(stderr, "Could not write\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

void		*xmalloc(int size)
{
  void		*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      fprintf(stderr, "Could not alloc\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
