/*
** main.c for my_files in /home/guillo_e//working/unix/my_ls
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Nov 30 13:45:54 2011 lyoma guillou
** Last update Sun Dec  4 05:15:10 2011 lyoma guillou
*/

#include <unistd.h>
#include "my_ls.h"

int		main(int ac, char **av)
{
  if (ac >= 2)
    data_recover(av[1]);
  else
    data_recover(".");
  return (0);
}
