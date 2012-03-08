/*
** get_funcs.c for filler_baby in /home/guillo_e//Documents/working/rush/filler_baby/algo
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Feb 25 16:32:15 2012 lyoma guillou
** Last update Mon Feb 27 07:39:50 2012 lyoma guillou
*/

#include <filler.h>

t_pos		get_next_cell(t_vm turn, t_pos *part)
{
  static int	line = 1;
  static int	sav = 0;
  t_pos		len;
  t_pos		cell;
  char		**map;
  char		**pxc;

  map = turn.map;
  pxc = turn.pxc;
  len.x = strlen(map[cell.y]);
  len.y = my_tablen(map);
  if (sav > part->x || part->x >= len.x - 1)
    ++line;
  cell.x = (part->x <= 0 || part->x >= len.x - 1) ? 0 : part->x;
  cell.y = (part->x <= 0 || part->x >= len.x - 1) ? ++part->y + line : part->y + line;
  sav = part->x;
  while (map[cell.y] && !is_cell(map[cell.y][++cell.x]))
    if (cell.x >= (int) (strlen(map[cell.y]) - 1) || !map[cell.y][cell.x])
      {
	cell.x = 0;
	++cell.y;
      }
  part->x = cell.x;
  part->y = cell.y;
  return (cell);
}

t_pos		get_valid_pos(t_vm turn)
{
  t_pos		pos;
  t_pos		cell;
  t_pos		len;
  t_pos		max;

  pos.x = 0;
  pos.y = 0;
  len.x = strlen(turn.pxc[pos.y]);
  len.y = my_tablen(turn.pxc);
  max.x = strlen(turn.map[0]);
  max.y = my_tablen(turn.map);
  cell = get_next_cell(turn, &pos);
  while (pos.x != max.x && pos.y != max.y && !is_valid_pos(turn, pos, cell))
    {
      --pos.x;
      if ((cell.x - pos.x) == len.x)
	{
	  --pos.y;
	  pos.x += len.x;
	}
      if ((cell.y - pos.y) == len.y || pos.y < 0)
	{
	  len.x = strlen(turn.pxc[0]);
	  len.y = my_tablen(turn.pxc);
	  cell = get_next_cell(turn, &pos);
	}
    }
  return (pos);
}

char		**get_map()
{
  char		**map;
  char		*trash;
  int		nb_x;
  int		nb_y;
  int		line;

  trash = xmalloc(OUT_SIZE);
  bzero(trash, OUT_SIZE);
  while (strcmp(trash, "Board"))
    scanf("%s", trash);
  free(trash);
  scanf(" %d %d:", &nb_x, &nb_y);
  line = nb_x;
  map = xmalloc(sizeof(*map) * (nb_x + 1));
  scanf(" %*[^\n]");
  while (nb_x > 0)
    {
      map[line - nb_x] = xmalloc(sizeof(**map) * (nb_y + 1));
      scanf("%*s %[^\n]", map[line - nb_x]);
      map[line - nb_x][nb_y] = '\0';
      nb_x--;
    }
  map[line] = '\0';
  return (map);
}

char		**get_piece()
{
  char		**piece;
  char		*trash;
  int		nb_x;
  int		nb_y;
  int		line;

  trash = xmalloc(OUT_SIZE);
  bzero(trash, OUT_SIZE);
  while (strcmp(trash, "Piece"))
    scanf("%s", trash);
  scanf(" %d %d:", &nb_x, &nb_y);
  line = nb_x;
  piece = xmalloc(sizeof(*piece) * (nb_x + 1));
  while (nb_x > 0)
    {
      piece[line - nb_x] = xmalloc(sizeof(*piece) * (nb_y + 1));
      scanf(" %[^\n]", piece[line - nb_x]);
      piece[line - nb_x][nb_y] = '\0';
      nb_x--;
    }
  piece[line] = '\0';
  return (piece);
}
