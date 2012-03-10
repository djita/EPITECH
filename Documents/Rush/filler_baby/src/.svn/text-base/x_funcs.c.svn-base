/*
** x_funcs.c for filler_baby in /home/guillo_e//Documents/working/rush/filler_baby/algo
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Feb 25 15:27:47 2012 lyoma guillou
** Last update Sun Feb 26 00:40:03 2012 lyoma guillou
*/

#include <filler.h>

int		xwrite(int fd, char *buffer, int len)
{
  int		i;

  i = 0;
  if ((i = write(fd, buffer, len)) < 0)
    {
      write(2, "Invalid write\n", strlen("Invalid write\n"));
      exit(EXIT_FAILURE);
    }
  return (i);
}

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      write(2, "Invalid malloc\n", strlen("Invalid malloc\n"));
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
