/*
** drawing.c for drawing in /home/guillo_e//Documents/working/tek2/piscine/D01/ex03
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan  9 18:51:19 2013 lyoma guillou
** Last update Wed Jan  9 19:38:53 2013 lyoma guillou
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

int		main()
{
  t_bmp_header	header;
  t_bmp_info_header	info;
  unsigned int	*buffer;
  unsigned int	**img;
  t_point	p = {0, 0};
  size_t	size = 64;
  int		d;

  buffer = malloc(size * size * sizeof(buffer));
  img = malloc(size * sizeof(*img));
  memset(buffer, 0, size * size * sizeof(*buffer));
  for (size_t i = 0; i < size; ++i)
    img[i] = buffer + i * size;

  make_bmp_header(&header, size);
  make_bmp_info_header(&info, size);

  draw_square(img, &p, size, 0x0000FFFF);
  p.x = 10;
  p.y = 10;
  draw_square(img, &p, 22, 0x00FF0000);

  d = open("square.bmp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  write(d, &header, sizeof(header));
  write(d, &info, sizeof(info));
  write(d, buffer, size * size * sizeof(*buffer));
  close(d);
  return EXIT_SUCCESS;
}
