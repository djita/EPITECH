/*
** carre.h for carre.h in /home/guillo_e//Documents/working/colles/colle6
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May 21 19:22:46 2012 lyoma guillou
** Last update Mon May 21 22:56:25 2012 lyoma guillou
*/

#ifndef CARRE_H_
# define CARRE_H_

# define WHITE 0x00FFFFFF
# define WIN_SIZE 500
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define SPACE 32
# define ESC 65307
# define PC1(color) color <= 0 ? 0x00FF0000 : color
# define PC2(color) color <= 0 ? 0x0033CC00 : color

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_data
{
  void		*ptr;
  void		*win;
  t_pos		size;
}		t_data;

typedef struct	s_elem
{
  int		color;
  t_pos		pos;
  int		exist;
  int		size;
  char		disp;
}		t_elem;

typedef struct	s_players
{
  char		*name_p1;
  char		*name_p2;
  int		color_p1;
  int		color_p2;
  int		turn;
}		t_players;

typedef struct	s_game
{
  t_data	*mlx;
  t_elem	**mem;
  t_players	*pls;
  t_pos		*sqr;
  t_pos		pos;
  int		flag;
}		t_game;

void		draw_vtcl(t_data *mlx, t_pos dpt, t_pos dst, int color);
void		draw_hrzt(t_data *mlx, t_pos dpt, t_pos dst, int color);

void		init_argv(t_players **players, t_pos *size, char **av);

t_elem		**create_tab(t_pos *size);

void		game_init(t_data *mlx, t_pos *size);

void		move(t_game *game);

#endif /* !CARRE_H_ */
