/*
** utils2.c for utils2 in /home/deleta_m//Projets/Colles/Colle_7
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Tue May 29 19:15:30 2012 marc deletang
** Last update Tue May 29 22:50:30 2012 lyoma guillou
*/

#include <stdlib.h>
#include <unistd.h>
#include "txtcnt.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
}

void	my_bzero(void *ptr, int n)
{
  int	i;
  int	*tmp;

  i = 0;
  tmp = ptr;
  while (i != n)
    {
      tmp[i] = 0;
      i++;
    }
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] && str2[i] && str1[i] == str2[i])
    i++;
  return (str1[i] - str2[i]);
}
