/*
** drawing.h for drawing in /home/guillo_e//Documents/working/tek2/piscine/D01/ex03
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan  9 18:48:11 2013 lyoma guillou
** Last update Wed Jan  9 20:42:59 2013 lyoma guillou
*/

#ifndef __DRAWING_H__
#define __DRAWING_H__

#include <stdint.h>

typedef struct	s_point
{
  unsigned int	x;
  unsigned int	y;
}		t_point;

void		draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color);

#endif
