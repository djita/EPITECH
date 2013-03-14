/*
** part3.c for part3 in /home/deleta_m//Projets/Colles/Colle_7
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Tue May 29 19:43:30 2012 marc deletang
** Last update Tue May 29 21:57:45 2012 lyoma guillou
*/

#include "txtcnt.h"

void	show_ord_count(int len)
{
  int	i;

  while (len >= 0)
    {
      i = 0;
      while (i < MAX_ASCII)
	{
	  if (g_char_tab[i] > 0)
	    {
	      if (g_char_tab[i] == len)
		{
		  my_putchar(i);
		  my_putchar(':');
		  my_putnbr(g_char_tab[i]);
		  my_putchar('\n');
		}
	    }
	  ++i;
	}
      len--;
    }
}

void	reverse_show_ord_count(int len)
{
  int	i;
  int	incr;

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
		  my_putchar(i);
		  my_putchar(':');
		  my_putnbr(g_char_tab[i]);
		  my_putchar('\n');
		}
	    }
	  ++i;
	}
      incr++;
    }
}
