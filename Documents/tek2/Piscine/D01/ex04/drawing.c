/*
** drawing.c for drawing in /home/guillo_e//Documents/working/tek2/piscine/D01/ex03
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan  9 18:51:19 2013 lyoma guillou
** Last update Wed Jan  9 20:43:00 2013 lyoma guillou
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "bitmap.h"
#include "drawing.h"

void		draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color)
{
  uint32_t	**tmp;

  tmp = img;
  for (unsigned int y = 0; y < size; ++y)
    for (unsigned int x = 0; x < size; ++x)
      tmp[orig->y + y][orig->x + x] = color;
}
