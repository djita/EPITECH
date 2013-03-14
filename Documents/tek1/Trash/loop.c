/*
** loop.c for main in /home/guillo_e//Documents/working/test
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Mar  7 14:41:48 2012 lyoma guillou
** Last update Wed Mar  7 14:45:49 2012 lyoma guillou
*/

#include <unistd.h>

int	main()
{
  int	pgid;

  pgid = getpgrp();
  printf("%d\n", pgid);
  while (42);
  return (0);
}
