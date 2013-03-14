/*
** game_of_life.h for game_of_life in /u/all/guillo_e/public/deleta_m
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May 14 19:23:14 2012 marc deletang
** Last update Mon May 14 22:55:45 2012 lyoma guillou
*/

#ifndef GAME_OF_LIFE_H_
# define GAME_OF_LIFE_

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_putxmap(char **tab, int y, int x);

int		xread(int fd, char *buff, int size);
void		*xmalloc(int);
void		*my_memset(void *ptr, int c, int len);
void		my_bzero(void *ptr, int len);

int		my_getnbr(char *str);

int	        is_alive(char **tab, int y, int x);
char		**check_cells(char **tab);

int		generate_rand(int size);

char		**cell_in_tab(char **tab, int x, int y, int cell);

char		**create_game(int, int);
void		game_of_life(int, int, int);

#endif /* !GAME_OF_LIFE_ */
