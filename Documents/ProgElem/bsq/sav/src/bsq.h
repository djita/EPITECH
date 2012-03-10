/*
** bsq.h for bsq in /home/guillo_e//working/prog_elem/bsq
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Dec  5 18:48:57 2011 lyoma guillou
** Last update Tue Dec  6 15:36:23 2011 lyoma guillou
*/

#ifndef		BSQ_H_
#define		BSQ_H_

#define		LIM(x, y)	((x) <= (y)) ? (x) : (y)

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_puttab(char **map);

int		my_strlen(char *str);
int		my_tablen(char **tab);
char		**my_tab_zero(char **tab, int len);
char		*my_strdup(char *str);

int		my_getnbr(char *str);

void		fill_out(char **tab, int x, int y, int size);
int		pos_chk(char **tab, int x, int y, int lim);
char		**sqr_chk(char **tab);
char		**map_tab(const int fd);

#endif
