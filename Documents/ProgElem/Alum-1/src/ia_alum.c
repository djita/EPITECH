/*
** ia_alum.c for alum1 in /home/guillo_e//Documents/working/prog_elem/Alum-1
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Feb 11 14:48:46 2012 lyoma guillou
** Last update Sat Feb 11 15:33:57 2012 lyoma guillou
*/

#include <alum.h>
#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>

int		clear_scrn()
{
  void		*ptr;

  tgetent(NULL, "xterm");
  ptr = tgetstr("cl", NULL);
  tputs(ptr, 1, my_putchar);
  return (0);
}

