/*
** String.c for String in /home/guillo_e//Documents/working/tek2/piscine/D03/ex00
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Jan 11 09:04:03 2013 lyoma guillou
** Last update Fri Jan 11 12:11:21 2013 lyoma guillou
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

static void	append_s(String *this, String const *ap)
{
  char		*tmp;
  int		len = strlen(this->str) + strlen(ap->str) + 1;

  if (this && ap)
    {
      tmp = malloc(len * sizeof(*tmp));
      memset(tmp, 0, len);
      tmp = strcat(strcat(tmp, this->str), ap->str);
      free(this->str);
      this->str = strdup(tmp);
      free(tmp);
    }
}

static void	append_c(String *this, char const *ap)
{
  char		*tmp;
  int		len = strlen(this->str) + strlen(ap) + 1;

  if (this && ap)
    {
      tmp = malloc(len * sizeof(*tmp));
      memset(tmp, 0, len);
      tmp = strcat(strcat(tmp, this->str), ap);
      free(this->str);
      this->str = strdup(tmp);
      free(tmp);
    }
}

static char	at(String *this, size_t pos)
{
  char		*tmp;
  size_t	i;

  if (this->str)
    {
      tmp = this->str;
      for (i = 0; i < pos && tmp[i]; ++i);
      if (i == pos && tmp[i])
	return tmp[i];
    }
  return -1;
}

static void	clear(String *this)
{
  if (this)
    {
      free(this->str);
      this->str = NULL;
    }  
}

static int	size(String *this)
{
  char		*tmp;
  int		i;

  if (this->str)
    {
      tmp = this->str;
      for (i = 0; tmp[i]; ++i);
      return i;
    }
  return -1;
}

void		StringInit(String *this, char const *s)
{
  this->str = NULL;
  if (s)
    this->str = strdup(s);
  this->assign_s = assign_s;
  this->assign_c = assign_c;
  this->append_s = append_s;
  this->append_c = append_c;
  this->at = at;
  this->clear = clear;
  this->size = size;
}

void		StringDestroy(String *this)
{
  if (this)
    {
      free(this->str);
      memset(this, 0, sizeof(String));
    }
}

