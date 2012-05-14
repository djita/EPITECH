/*
** cut_str.c for cut_str in /home/deleta_m//Projets/Colles/Colle_2
**
** Made by marc deletang
** Login   <deleta_m@epitech.net>
**
** Started on  Tue Apr 24 22:18:57 2012 marc deletang
** Last update Tue Apr 24 22:55:49 2012 lyoma guillou
*/

#include "my.h"

char	*cut_str(char *str)
{
  int	i;
  char	*dup;

  i = 0;
  if (str[i] == '>' && str[i + 1] != '\0')
    {
      dup = my_strndup(str, i);
      my_strcpy(str, str + i + 1);
      return (dup);
    }
  if (str[i] == '<' && i != 0)
    {
      dup = my_strndup(str, i);
      my_strcpy(str, str + i + 1);
      return (dup);
    }
  return (str);
}
