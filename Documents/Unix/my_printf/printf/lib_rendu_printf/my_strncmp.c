/*
** my_strncmp.c for strncmp in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct 10 13:45:04 2011 lyoma guillou
** Last update Wed Nov 16 14:35:47 2011 lyoma guillou
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1 && s2 && i < n)
    {
      if (s1[i] == s2[i])
	return (0);
      if (s1[i] > s2[i])
	return (1);
      if (s1[i] < s2[i])
	return (-1);
      i++;
    }
}
