/*
** get_char.c for get_char in /home/guillo_e//working/unix/my_select/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Jan  9 13:23:00 2012 lyoma guillou
** Last update Mon Jan  9 14:25:25 2012 lyoma guillou
*/

#include <termios.h>
#include <unistd.h>

void			my_putchar(char c)
{
  write(1, &c, 1);
}

void			my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

int			main()
{
  struct termios	term_p;
  char			buffer[2];
  int			i;

  tcgetattr(0, &term_p);
  term_p.c_lflag &= ~ICANON;
  tcsetattr(0, TCSANOW, &term_p);
  while (i < 2)
    buffer[i++] = 0;
  while ((i = read(0, buffer, 1)) > 0)
    {
      my_putchar('\n');
      my_putnbr((int) buffer[0]);
      my_putchar('\n');
    }
}
