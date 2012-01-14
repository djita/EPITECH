/*
** my_strcmp.c for my_strcmp in /home/guillo_e//afs/rendu/piscine/Jour_06/ex_05
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct 10 13:39:31 2011 lyoma guillou
** Last update Wed Nov 16 14:35:48 2011 lyoma guillou
*/

#include "my.h"

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1 && s2)
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
