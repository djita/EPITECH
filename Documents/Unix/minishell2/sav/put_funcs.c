/*
** str_utils.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 21 14:03:03 2011 lyoma guillou
** Last update Mon Feb 13 14:08:07 2012 lyoma guillou
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_sh.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_puterr(char *err)
{
  write(2, err, my_strlen(err));
}
