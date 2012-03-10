/*
** x_funcs.c for mysh in /home/guillo_e//Documents/working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb 13 19:46:34 2012 lyoma guillou
Last update Wed Feb 15 18:27:09 2012 lyoma guillou
*/

#include <my_sh.h>

int		xwrite(int fd, void *ptr, int size)
{
  int		len;
  
  if ((len = write(fd, ptr, size)) < 0)
    exit(EXIT_FAILURE);
  return (len);
}

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      my_puterr("Could not alloc\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
