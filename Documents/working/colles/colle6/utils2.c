/*
** utils2.c for carre in /home/guillo_e//afs/public/deleta_m
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May 21 20:07:47 2012 lyoma guillou
** Last update Mon May 21 20:08:22 2012 lyoma guillou
*/

#include "utils.h"

char	*my_strdup(char *str)
{
  char	*str_return;

  str_return = xmalloc(my_strlen(str) + 1);
  my_strcpy(str_return, str);
  return (str_return);
}
