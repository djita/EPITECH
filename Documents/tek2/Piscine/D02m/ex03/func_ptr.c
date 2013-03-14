/*
** func_ptr.c for func_ptr in /home/guillo_e//Documents/working/tek2/piscine/D02m/ex03
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 10:05:23 2013 lyoma guillou
** Last update Thu Jan 10 12:16:01 2013 lyoma guillou
*/

#include <unistd.h>
#include <string.h>
#include <ctype.h>

#include "func_ptr_enum.h"
#include "func_ptr.h"

static const t_act	g_act[4]=
  {
    { PRINT_NORMAL, print_normal },
    { PRINT_REVERSE, print_reverse },
    { PRINT_UPPER, print_upper },
    { PRINT_42, print_42 }
  };

void		print_42(char *str)
{
  (void) str;
  write(1, "42\n", strlen("42\n"));
}

void		print_upper(char *str)
{
  size_t	i;
  char		c;

  for (i = 0; i < strlen(str); ++i)
    {
      c = toupper(str[i]);
      write(1, &c, 1);
    }
  write(1, "\n", 1);
}

void		print_reverse(char *str)
{
  int		i;

  for (i = strlen(str) - 1; i >= 0; --i)
    write(1, &str[i], 1);
  write(1, "\n", 1);
}

void		print_normal(char *str)
{
  write(1, str, strlen(str));
  write(1, "\n", 1);
}

void		do_action(t_action action, char *str)
{
  int		i;

  for (i = 0; i < 4; ++i)
    if (g_act[i].action == action)
      g_act[i].func(str);
}
