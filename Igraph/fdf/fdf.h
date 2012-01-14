/*
** fdf.h for fdf in /home/guillo_e//working/igraph/fdf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Nov 23 14:02:13 2011 lyoma guillou
** Last update Tue Dec 27 14:35:37 2011 lyoma guillou
*/

#ifndef FDF_H_
#define FDF_H_

#define SIZE_X	1500
#define SIZE_Y	1000

#define CTE1	0.5
#define CTE2	0.5

#define UNTX	50
#define UNTY	50
#define DENS	20

#define POS_X	SIZE_X / 2
#define POS_Y	SIZE_Y - (SIZE_Y / (DENS * 4))

#define ABS(x)	((x) < 0) ? (-(x)) : (x)

typedef struct	s_dot
{
  int		x;
  int		y;
  int		z;
  struct s_dot	*next;
}		t_dot;

typedef struct	s_grid
{
  int		x;
  int		y;
  struct s_grid	*next;
}		t_grid;

typedef struct	s_draw
{
  int		diff_x;
  int		diff_y;
  int		seg_x;
  int		seg_y;
  int		stroke;
  int		stk2;
}		t_draw;

typedef struct	s_fdf
{
  char		**av;
  void		*ptr;
  void		*win;
  t_grid	*map;
}		t_fdf;

void		my_putchar(char c);
int		my_strlen(char *str);
void		my_putstr(char *str);

int		my_getnbr(char *str);
int		get_tablen(char **tab);
int		*get_line_int(char **tab);

char            *my_strset(char *str, int size);
int		my_bufflen(char *str);
char		*my_buffreset(char *dst, char *src);
char		*get_next_line(const int fd);

int		is_numeric(char c);
int		word_len(char *str, int cursor);
int		word_to_cell(char *tab, char *str, int cursor);
int		count_words(char *str);
char		**my_str_to_wordtab(char *str);

t_dot		*init(int x, int y, int z);
t_dot		*app_to_list(t_dot *first, t_dot *cur);
t_dot		*map_recover(t_dot * list, int *line, int size, int row);
t_dot		*map_elem(char *path);

void		show_grid(void *ptr, void *win, t_grid *map);
t_grid		*projection(int x, int y, int z);
t_grid		*grid_list(t_grid *first, t_grid *elem);
t_grid		*grid_project(t_dot *data);

void		draw_line(void *ptr, void *win, t_grid *a, t_grid *b);

int		key_care(int keycode);

#endif
