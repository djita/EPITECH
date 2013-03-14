/*
** my_logintty.c for my_logintty.c in /home/bigup/prog/tek2/proj/my_script/
**
** Made by dimitri doyen
** Login   <doyen_d@epitech.net>
**
** Started on  Fri Feb 25 14:12:37 2011 dimitri doyen
** Last update Sun Mar  3 02:35:39 2013 Lyoma Guillou
*/

#include "my_script.h"

int             my_login_tty(int fd)
{
  dup2(fd, 0);
  dup2(fd, 1);
  dup2(fd, 2);

  return (0);
}
