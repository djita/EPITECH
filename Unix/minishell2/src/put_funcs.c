/*
** str_utils.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 21 14:03:03 2011 lyoma guillou
** Last update Wed Feb 15 18:27:08 2012 lyoma guillou
*/

#include <my_sh.h>

void		my_putchar(char c)
{
  xwrite(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

void		my_putstr(char *str)
{
  xwrite(1, str, my_strlen(str));
}

void		my_puterr(char *err)
{
  xwrite(2, err, my_strlen(err));
}
