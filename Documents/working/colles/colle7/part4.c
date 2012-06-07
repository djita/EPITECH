/*
** part4.c for part4 in /home/deleta_m//Projets/Colles/Colle_7
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Tue May 29 20:11:56 2012 marc deletang
** Last update Tue May 29 22:43:28 2012 marc deletang
*/

#include "txtcnt.h"

static int	_get_max_char(int nb)
{
  int		i;
  int		max;

  max = 0;
  i = 0;
  while (i < MAX_ASCII)
    {
      if (g_char_tab[i] == nb)
	max = i;
      i++;
    }
  return (max);
}

static void	_print_stat(int count, int len, int occ)
{
  float		on;
  float		per;
  float		app;
  int		res;

  on = (float) count;
  per = (float) len;
  app = (float) occ;
  res = (int) ((on / per) * app * 10);
  my_putstr(" (");
  my_putnbr(count);
  my_putstr(") (");
  my_putnbr(res);
  my_putstr("%)");
}

static void	_print_values(int nb, t_e_opt flag)
{
  int		i;
  int		count;
  int		max;
  int		occ;

  i = 0;
  count = 0;
  max = _get_max_char(nb);
  while (i < MAX_ASCII)
    {
      if (g_char_tab[i] == nb)
	{
	  my_putchar(i);
	  occ = g_char_tab[i];
	  g_char_tab[i] = 0;
	  count++;
	  if (i != max)
	    my_putchar(',');
	}
      i++;
    }
  if (flag & FULL)
    _print_stat(count, nb, occ);
  my_putchar('\n');
}

void		count_and_sort(int len, t_e_opt flag)
{
  int		i;

  while (len >= 0)
    {
      i = 0;
      while (i < MAX_ASCII)
	{
	  if (g_char_tab[i] > 0)
	    {
	      if (g_char_tab[i] == len)
		{
		  my_putnbr(g_char_tab[i]);
		  my_putchar(':');
		  _print_values(len, flag);
		}
	    }
	  ++i;
	}
      len--;
    }
}

void		reverse_count_and_sort(int len, t_e_opt flag)
{
  int		i;
  int		incr;

  incr = 0;
  while (incr <= len)
    {
      i = 0;
      while (i < MAX_ASCII)
	{
	  if (g_char_tab[i] > 0)
	    {
	      if (g_char_tab[i] == incr)
		{
		  my_putnbr(g_char_tab[i]);
		  my_putchar(':');
		  _print_values(incr, flag);
		}
	    }
	  ++i;
	}
      incr++;
    }
}
