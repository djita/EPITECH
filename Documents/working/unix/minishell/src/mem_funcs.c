/*
** mem_funcs.c for mysh in /home/guillo_e//Documents/working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Jan 31 16:22:42 2012 lyoma guillou
** Last update Fri Feb 10 17:22:49 2012 lyoma guillou
*/

#include "my_sh.h"

void	*my_memset(void *buffer, int s, int len)
{
  char	*mem;
  int	i;

  i = 0;
  mem = buffer;
  while (i < len)
    mem[i++] = s;
  return (buffer);
}
