/*
** get_funcs.c for filler_baby in /home/guillo_e//Documents/working/rush/filler_baby/algo
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Feb 25 16:32:15 2012 lyoma guillou
** Last update Sun Feb 26 02:51:35 2012 lyoma guillou
*/

#include <filler.h>

char	**get_map()
{
  char	**map;
  char	*trash;
  int	nb_x;
  int	nb_y;
  int	line;

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

char	**get_piece()
{
  char	**piece;
  int	nb_x;
  int	nb_y;
  int	line;

  scanf("\n");
  scanf("Piece %d %d:", &nb_x, &nb_y);
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
