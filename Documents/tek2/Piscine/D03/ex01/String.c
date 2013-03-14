/*
** String.c for String in /home/guillo_e//Documents/working/tek2/piscine/D03/ex00
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Jan 11 09:04:03 2013 lyoma guillou
** Last update Fri Jan 11 12:11:22 2013 lyoma guillou
*/

#include <stdlib.h>
#include <string.h>

#include "String.h"

static void	assign_s(String *this, String const *str)
{
  char		*tmp;

  if (this && str)
    {
      tmp = this->str;
      this->str = strdup(str->str);
      if (tmp)
	free(tmp);
    }
}

static void	assign_c(String *this, char const *s)
{
  char		*tmp;

  if (this && s)
    {
      tmp = this->str;
      this->str = strdup(s);
      if (tmp)
	free(tmp);
    }
}

void		StringInit(String *this, char const *s)
{
  this->str = NULL;
  if (s)
    this->str = strdup(s);
  this->assign_s = assign_s;
  this->assign_c = assign_c;
}

void		StringDestroy(String *this)
{
  if (this)
    {
      free(this->str);
      memset(this, 0, sizeof(String));
    }
}
