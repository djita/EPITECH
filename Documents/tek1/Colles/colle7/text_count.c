/*
** text_count.c for text_count in /home/guillo_e//Documents/working/colles/colle7
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue May 29 19:16:20 2012 lyoma guillou
** Last update Tue May 29 22:27:30 2012 marc deletang
*/

#include "txtcnt.h"

static int	_is_matched(char c)
{
  static char	tab[MAX_ASCII];

  if (!tab[(int) c])
    {
      tab[(int) c] = 1;
      return (0);
    }
  return (1);
}

static void	_show_count()
{
  int		i;

  i = 0;
  while (i < MAX_ASCII)
    {
      if (g_char_tab[i] > 0)
	{
	  my_putchar(i);
	  my_putchar(':');
	  my_putnbr(g_char_tab[i]);
	  my_putchar('\n');
	}
      ++i;
    }
}

static void	_get_all_chars(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      ++g_char_tab[(int) str[i]];
      ++i;
    }
}

static void	_get_match_chars(char *str, char *pat)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (pat[j])
    {
      i = 0;
      if (!_is_matched(pat[j]))
	while (str[i])
	  {
	    if (str[i] == pat[j])
	      ++g_char_tab[(int) pat[j]];
	    ++i;
	  }
      ++j;
    }
}

void		text_count(int ac, char **av, t_e_opt flag)
{
  int		i;

  i = 0;
  my_bzero(g_char_tab, MAX_ASCII);
  if (my_tablen(av) == ac)
    {
      if (my_tablen(av) == 1)
	_get_all_chars(av[i]);
      else
	_get_match_chars(av[i], av[i + 1]);
      if (flag & SORT)
	(flag & REV) ? reverse_show_ord_count(my_strlen(av[i]))
	  : show_ord_count(my_strlen(av[i]));
      else if (flag & ORD)
	(flag & REV) ? reverse_count_and_sort(my_strlen(av[i]), flag)
	  : count_and_sort(my_strlen(av[i]), flag);
      else
	_show_count();
    }
}
