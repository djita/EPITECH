/*
** checker.c for filler in /home/guillo_e//Documents/working/rush
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Feb 24 21:04:10 2012 lyoma guillou
** Last update Mon Feb 27 04:49:13 2012 lyoma guillou
*/

#include <filler.h>

int		is_dot(char c)
{
  if (c != '.' && c != 0)
    return (0);
  return (1);
}

int		is_cell(char c)
{
  if (c != 'O' && c != 0)
    return (0);
  return (1);
}

int		is_fit(char pix, char slot)
{
  if (!is_dot(pix) && !is_dot(slot))
    return (0);
  return (1);
}

int		is_over(char pix, char slot)
{
  if (is_dot(pix) || !is_cell(slot))
    return (0);
  return (1);
}

int		is_valid_pos(t_vm turn, t_pos pos, t_pos cell)
{
  char		**map;
  char		**pxc;
  int		i;
  int		j;

  i = 0;
  j = 0;
  map = turn.map;
  pxc = turn.pxc;
  while (pxc[i])
    {
      if ((pos.y + i != cell.y || pos.x + j != cell.x)
	  ? !is_fit(pxc[i][j], map[pos.y + i][pos.x + j])
	  : !is_over(pxc[i][j], map[pos.y + i][pos.x + j]))
	return (0);	  
      ++j;
      if (!pxc[i][j])
	{
	  j = 0;
	  ++i;
	}
    }
  return (1);
}
