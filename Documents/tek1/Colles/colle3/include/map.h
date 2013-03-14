/*
** map.h for carre in /home/guillo_e//Documents/working/colles/colle3
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr 30 19:38:21 2012 lyoma guillou
** Last update Mon Apr 30 22:43:02 2012 lyoma guillou
*/

#ifndef MAP_H_
# define MAP_H_

# define	WHITE	0x00FFFFFF

# define	LEFT	65361
# define	UP	65362
# define	RIGHT	65363
# define	DOWN	65364
# define	SPACE	32

typedef struct	s_map
{
  int		h;
  int		w;
  void		*mlx;
  void		*win;
  int		win_x;
  int		win_y;
}		t_map;

typedef struct	s_dot
{
  int		x;
  int		y;
}		t_dot;

typedef struct	s_game
{
  int		keycode;
  int		p1;
  int		p2;
  t_dot		dep;
  t_dot		arv;
}		t_game;

int		is_num(char);
int		my_getnbr(char *);
int		my_strcmp(char *, char *);

void		aff_horizontal(t_map, t_dot, t_dot, int);
void		aff_vertical(t_map, t_dot, t_dot, int);

int		key_handle(int, t_game *);

#endif
