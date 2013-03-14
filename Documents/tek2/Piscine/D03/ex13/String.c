/*
** String.c for String in /home/guillo_e//Documents/working/tek2/piscine/D03/ex00
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Jan 11 09:04:03 2013 lyoma guillou
** Last update Fri Jan 11 17:06:12 2013 lyoma guillou
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

static int	compare_s(String *this, const String *str)
{
  return (strcmp(this->str, str->str));
}

static int	compare_c(String *this, char const *str)
{
  return (strcmp(this->str, str));
}

static size_t	copy(String *this, char *s, size_t n, size_t pos)
{
  size_t	i = 0;
  char		*tmp;

  if (this->str && s)
    {
      tmp = this->str;
      for (i = 0; i < n && tmp[pos + i] && s[i]; ++i)
	s[i] = tmp[pos + i];
    }
  return (i);
}

static char const	*c_str(String *this)
{
  if (this)
    return this->str;
  return NULL;
}

static int	empty(String *this)
{
  return (this && this->str && this->str[0]) ? -1 : 1;
}

static int	find_s(String *this, const String *str, size_t pos)
{
  char		*tmp;
  int		i;

  if (this && str && this->str && str->str && str->str[0]
      && strlen(str->str) <= strlen(this->str) && pos < strlen(this->str))
    {
      tmp = str->str;
      for (i = 0; pos + i < strlen(this->str); ++i)
	if (!strncmp(this->str + pos + i, tmp, strlen(tmp)))
	  return pos + i;
    }
  return -1;
}

static int	find_c(String *this, char const *str, size_t pos)
{
  int		i;

  if (this && str && str[0]
      && this->str && strlen(str) <= strlen(this->str) && pos < strlen(this->str))
    for (i = 0; pos + i < strlen(this->str); ++i)
      if (!strncmp(this->str + pos + i, str, strlen(str)))
	return pos + i;
  return -1;
}

static void	insert_s(String *this, size_t pos, String const *str)
{
  char		*tmp;

  if (this && str)
    {
      tmp = malloc((strlen(this->str) + strlen(str->str) + 1) * sizeof(*tmp));
      tmp = strncpy(tmp, this->str, pos);
      strcpy(tmp + pos, str->str);
      strcat(tmp, this->str + pos);
      this->clear(this);
      this->str = tmp;
    }
}

static void	insert_c(String *this, size_t pos, char const *str)
{
  char		*tmp;

  if (this && str)
    {
      tmp = malloc((strlen(this->str) + strlen(str) + 1) * sizeof(*tmp));
      tmp = strncpy(tmp, this->str, pos);
      strcpy(tmp + pos, str);
      strcat(tmp, this->str + pos);
      this->clear(this);
      this->str = tmp;
    }
}

static int	to_int(String *this)
{
  if (this && this->str)
    return atoi(this->str);
  return 0;
}

static String	*split_s(String *this, char separator)
{
  String	*tab;
  char		*tmp;
  int		i = 0;
  int		j = 0;
  int		ct = 0;

  if (this && this->str)
    {
      tmp = strdup(this->str);
      for (i = 0; tmp[i]; ++i)
	if (separator == tmp[i])
	  ++ct;
      ct = 0;
      tab = malloc((ct + 1) * sizeof(*tab));
      for (i = 0; tmp[i]; ++i)
	{
	  if (tmp[i] != separator && ct == 0)
	    {
	      tmp = strcpy(tmp, tmp + i);
	      i = 0;
	      ct = 1;
	    }
	  if (tmp[i] == separator && ct == 1)
	    {
	      tmp[i] = '\0';
	      StringInit(&tab[j], tmp);
	      ++j;
	      tmp = strcpy(tmp, tmp + i + 1);
	      i = 0;
	      ct = 0;
	    }
	}
      StringInit(&tab[j++], tmp);
      StringInit(&tab[j], NULL);
      return tab;
    }
  return NULL;
}

/* static char	**split_c(String *this, char separator) */
/* { */
  
/* } */

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
  this->compare_s = compare_s;
  this->compare_c = compare_c;
  this->copy = copy;
  this->c_str = c_str;
  this->empty = empty;
  this->find_s = find_s;
  this->find_c = find_c;
  this->insert_s = insert_s;
  this->insert_c = insert_c;
  this->to_int = to_int;
  this->split_s = split_s;
}

void		StringDestroy(String *this)
{
  if (this)
    {
      free(this->str);
      memset(this, 0, sizeof(String));
    }
}

