/*
** checker.c for filler_baby in /home/guillo_e//Documents/working/rush
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Feb 24 21:04:10 2012 lyoma guillou
** Last update Sun Feb 26 04:23:41 2012 lyoma guillou
*/

#include <filler.h>

static int	_is_dot(char c)
{
  if (c != '.' && c != 0)
    return (0);
  return (1);
}

static int	_is_fit(char pix, char slot)
{
  if (!_is_dot(pix) && !_is_dot(slot))
    return (0);
  return (1);
}

static int	_is_valid_line(char *src, char *ptr)
{
  unsigned int	i;

  i = 0;
  while (i < strlen(ptr))
    {
      if (!src[i] || !_is_fit(src[i], ptr[i]))
	return (0);
      ++i;
    }
  return (1);
}

static int	_is_valid_pos(char **map, char **pix, int y, int x)
{
  int		i;

  i = 0;
  while (pix[i])
    {
      if (!map[i + y] || !_is_valid_line(map[i + y] + x, pix[i]))
	return (0);
      ++i;
    }
  return (1);
}

t_pos		is_valid_pix(t_vm turn)
{
  t_pos		slot;
  char		**map;
  char		**pix;
  int		i;
  int		j;

  slot.x = 0;
  slot.y = 0;
  map = turn.map;
  pix = turn.pxc;
  i = my_tablen(map);
  j = strlen(*map);
  while (i >= 0 && !_is_valid_pos(map, pix, i, j))
    {
      --j;
      slot.x = i;
      slot.y = j;
      if (j < 0)
	{
	  j = strlen(*map);
	  --i;
	}
    }
  return (slot);
}
