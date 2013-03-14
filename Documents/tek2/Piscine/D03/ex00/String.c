/*
** String.c for String in /home/guillo_e//Documents/working/tek2/piscine/D03/ex00
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Jan 11 09:04:03 2013 lyoma guillou
** Last update Fri Jan 11 12:11:26 2013 lyoma guillou
*/

#include <stdlib.h>
#include <string.h>

#include "String.h"

void		StringInit(String *this, char const *s)
{
  this->str = NULL;
  if (s)
    this->str = strdup(s);
}

void		StringDestroy(String *this)
{
  if (this)
    {
      free(this->str);
      memset(this, 0, sizeof(String));
    }
}
