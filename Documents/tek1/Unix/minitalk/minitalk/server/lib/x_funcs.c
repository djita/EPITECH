/*
** x_funcs.c for minitalk in /home/guillo_e//Documents/working/unix/minitalk/server/lib
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Mar  5 17:49:58 2012 lyoma guillou
** Last update Thu Mar 15 18:16:30 2012 lyoma guillou
*/

#include	<serv.h>
#include	<unistd.h>
#include	<stdlib.h>

int		xwrite(int fd, char *buf, int size)
{
  int		ret;

  ret = write(fd, buf, size);
  if (ret < 0)
    exit(EXIT_FAILURE);
  return (ret);
}

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      my_puterr("memory allocation problem.\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
