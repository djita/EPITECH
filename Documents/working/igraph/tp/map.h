/*
** map.h for wolf3d in /home/guillo_e//working/igraph/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 11 12:00:20 2012 lyoma guillou
** Last update Sat Jan 14 17:28:00 2012 lyoma guillou
*/

#ifndef		MAP_H_
#define		MAP_H_

#define		D		0.5
#define		P		1.0

#define		PI		3.14159265
#define		toRAD(ang)	ang * (PI / 180)

typedef struct	s_scrn
{
  void		*ptr;
  void		*win;
  int		win_x;
  int		win_y;  
}		t_scrn;

typedef	struct	s_img
{
  void		*img;
  int		*data;
  int		bpp;
  int		szln;
  int		endn;
}		t_img;

typedef	struct	s_map
{
  double	x;
  double	y;
  int		angle;
  double	vec_x;
  double	vec_y;
}		t_map;

int		my_strlen(char *str);
char		*my_strcpy(char *dst, char *src);

void            *my_memset(char *ptr, int size);

int		my_gettablen(char **tab);
int		my_getnbr(char *str);

int		is_alphanum(char c);
int		word_len(char *str, int cursor);
int		word_to_cell(char *tab, char *str, int cursor);
int		count_words(char *str);
char		**my_str_to_wordtab(char *str);

#endif
