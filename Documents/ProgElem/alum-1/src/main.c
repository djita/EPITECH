/*
** main.c for alum1 in /home/guillo_e//Documents/working/prog_elem/Alum-1
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb  6 08:51:03 2012 lyoma guillou
** Last update Sat Feb 11 16:09:21 2012 lyoma guillou
*/

#include <alum.h>

static int	_ia_turn()
{
  clear_scrn();
  
}

static int	_player_turn(char **alum, int lim)
{
  char		*buffer;
  int		len;

  len = 1;
  buffer = xmalloc(READ_SIZE * sizeof(*buffer));
  alum_show(alum, lim);
  my_putstr("\nCommand format: [line] [column] ([number])\n");
  len = read(0, buffer, READ_SIZE - 1);
  if (len > 1)
    alum = alum_entry(buffer, alum);
  my_memset(buffer, 0, READ_SIZE);
  return (1);
}

int		main(int ac, char **av)
{
  char		**alum;
  int		lim;

  if (ac != 0)
    {
      if (!av[1] || (lim = my_getnbr(av[1])) <= 0)
	lim = 4;
      alum = alum_tab(lim);
    }
  while (alum_check(alum))
    {
      _player_turn(alum, lim);
    }
  my_putstr("-=Game Over=-\n");
  return (0);
}