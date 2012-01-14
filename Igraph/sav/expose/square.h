/*
** square.h for expose in /home/guillo_e//working/test/igraph/expose
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 10 11:16:23 2011 lyoma guillou
** Last update Wed Nov 16 11:12:45 2011 lyoma guillou
*/

#ifndef SQAURE_H_
#define	SQUARE_H_

typedef struct	s_square
{
  void	*ptr;
  void	*win;
  int	pos_x;
  int	pos_y;
  int	size_x;
  int	size_y;
  int	color;
}		t_square;

void	my_square(t_square *sqr);
int	my_key(int keycode, t_square *square);

#endif
