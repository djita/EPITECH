/*
** mem_funcs.c for mysh in /home/guillo_e//Documents/working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Jan 31 16:22:42 2012 lyoma guillou
** Last update Wed Feb 29 14:32:03 2012 lyoma guillou
*/

#include <my_sh.h>

void		*my_memset(void *buffer, int s, int len)
{
  char		*mem;
  int		i;

  i = 0;
  mem = buffer;
  while (i < len)
    mem[i++] = s;
  return (buffer);
}

void		*my_memcpy(void *dst, void *src, int len)
{
  int		*cst_dst;
  int		*cst_src;
  int		i;

  i = 0;
  cst_dst = dst;
  cst_src = src;
  while (i < len)
    {
      cst_dst[i] = cst_src[i];
      ++i;
    }
  cst_dst[i] = '\0';
  return (dst);
}
