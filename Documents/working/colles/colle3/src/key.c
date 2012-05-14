/*
** key.c for  in /home/guillo_e//Documents/working/colles/colle3
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr 30 22:13:26 2012 lyoma guillou
** Last update Mon Apr 30 22:52:11 2012 lyoma guillou
*/

#include <unistd.h>
#include "map.h"

static void	my_putchar(char c)
{
  write(1, &c, 1);
}

static int	my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

static void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

static void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

int		key_handle(int keycode, t_game *turn)
{
  if (keycode == LEFT || keycode == UP || keycode == RIGHT 
      || keycode == DOWN || keycode == SPACE)
    {
      my_putnbr(keycode);
      my_putchar('\n');
      my_putstr("YOU LOST!\n");
    }
  return (0);
}
