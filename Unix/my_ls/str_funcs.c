/*
** str_funcs.c for my_ls in /home/guillo_e//working/unix/my_ls
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Dec  4 05:30:51 2011 lyoma guillou
** Last update Sun Dec  4 06:32:25 2011 lyoma guillou
*/

#include "my_ls.h"

char		*my_strncpy(char *dst, char *src, int n)
{
  int		i;

  i = 0;
  while (i < n)
    {
      dst[i] = src[i];
      i = i + 1;
    }
  dst[i] = '\0';
  return (dst);
}
