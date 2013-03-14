/*
** clear_screen.c for clear_screen in /home/guillo_e//working/unix/my_select/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Jan  9 15:05:09 2012 lyoma guillou
** Last update Mon Jan  9 19:16:34 2012 lyoma guillou
*/

#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>

int		my_putchar(int c)
{
  write(1, &c, 1);
}

int		main()
{
  char		*ptr;

  tgetent(NULL, "xterm");
  ptr = tgetstr("cl", NULL);
  tputs(ptr, 1, my_putchar);
}
