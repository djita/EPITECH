/*
** menger.c for menger in /home/guillo_e//Documents/working/tek2/piscine/D01/ex01/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan  9 09:46:39 2013 lyoma guillou
** Last update Wed Jan  9 16:01:52 2013 lyoma guillou
*/

#include <sys/types.h>
#include <stdio.h>

typedef struct	s_size
{
  unsigned int	x;
  unsigned int	y;
}		t_size;

static int	_is_num(char c)
{
  return ((c >= '0' && c <= '9'));
}

unsigned int	my_pow(unsigned int nb, unsigned int pow)
{
  unsigned int	x;

  x = 1;
  if (pow > 0)
    x = nb * my_pow(nb, pow - 1);
  return (x);
}

unsigned int	my_getnbr(char *str)
{
  int		i;
  unsigned int	x;

  i = 0;
  x = 0;
  while (str[i] && _is_num(str[i]))
    {
      x = x * 10;
      x = x + str[i] - '0';
      ++i;
    }
  return (x);
}

void		menger(unsigned int size, unsigned int lvl, t_size *pos)
{
  t_size	tmp;
  t_size	set;

  set.x = pos->x + size / 3;
  set.y = pos->y + size / 3;
  printf("%.3i %.3i %.3i\n", size / 3, set.x, set.y);
  if (lvl - 1)
    {
      for (unsigned int x = 0; x < size; x += size / 3)
	{
	  for (unsigned int y = 0; y < size; y += size / 3)
	    {
	      if (x == size / 3 && y == size / 3)
		continue;
	      tmp.x = x + pos->x;
	      tmp.y = y + pos->y;
	      menger(size / 3, lvl - 1, &tmp);
	    }
	}
    }
}

void		set_menger(unsigned int size, unsigned int lvl)
{
  t_size	init;

  init.x = 0;
  init.y = 0;
  menger(size, lvl, &init);
}
