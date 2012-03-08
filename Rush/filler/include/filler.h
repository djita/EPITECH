/*
** filler.h for filler.h in /home/guillo_e//Documents/working/rush
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Feb 24 19:48:00 2012 lyoma guillou
** Last update Sun Feb 26 15:19:56 2012 lyoma guillou
*/

#ifndef	FILLER_H_
#define FILLER_H_

#define	OUT_SIZE	512

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_vm
{
  char		**map;
  char		**pxc;
}		t_vm;

int		xwrite(int, char *, int);
void		*xmalloc(int);

void		struct_free(t_vm);

int		my_tablen(char **);

int		is_dot(char);
int		is_cell(char);
int		is_fit(char, char);
int		is_over(char, char);
int		is_valid_pos(t_vm, t_pos, t_pos);

t_pos		get_next_cell(t_vm, t_pos *);
t_pos		get_valid_pos(t_vm);
char		**get_map(void);
char		**get_piece(void);


#endif
