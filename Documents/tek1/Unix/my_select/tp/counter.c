/*
** counter.c for counter in /home/guillo_e//working/unix/my_select/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Jan 10 16:54:06 2012 lyoma guillou
** Last update Fri Jan 13 17:23:09 2012 lyoma guillou
*/

#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>

int		my_putchar(int c)
{
  write(1, &c, 1);
}

int		my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

int		main()
{
  char		nb;
  char		*ptr;

  nb = 1;
  tgetent(NULL, "xterm");
  while (nb <= 10)
    {
      my_putnbr(nb++);
      tputs(tgetstr("cr", NULL), 1, my_putchar);
      usleep(100000);
    }
  my_putchar('\n');
}
