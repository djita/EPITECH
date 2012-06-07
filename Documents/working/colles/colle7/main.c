/*
** main.c for text_count in /home/guillo_e//Documents/working/colles/colle7
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue May 29 19:11:51 2012 lyoma guillou
** Last update Tue May 29 21:37:53 2012 lyoma guillou
*/

#include "txtcnt.h"

int		main(int ac, char **av)
{
  t_opts	flags;

  if (ac >= 2)
    {
      flags = get_opt(ac, av);
      text_count(ac - flags.start, av + flags.start, flags.flag);
    }
  return (0);
}
