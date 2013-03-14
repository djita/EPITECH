/*
** rev_video.c for rev_video in /home/guillo_e//working/unix/my_select/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Jan  9 19:12:47 2012 lyoma guillou
** Last update Tue Jan 10 16:56:50 2012 lyoma guillou
*/

#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>

int		my_putchar(int c)
{
  write(1, &c, 1);
}

int		main(int ac, char **av)
{
  char		*ptr;

  tgetent(NULL, "xterm");
  ptr = tgetstr("mr", NULL);
  tputs(ptr, 1, my_putchar);
  tputs(av[1], 1, my_putchar);
  ptr = tgetstr("me", NULL);
  tputs(ptr, 1, my_putchar);
  my_putchar('\n');
}
