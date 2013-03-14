/*
** main.c for menger in /home/guillo_e//Documents/working/tek2/piscine/D01/ex01/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan  9 09:35:41 2013 lyoma guillou
** Last update Wed Jan  9 20:59:39 2013 lyoma guillou
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>

#include "bitmap.h"
#include "drawing.h"

unsigned int	my_pow(unsigned int nb, unsigned int pow);
unsigned int	my_getnbr(char *str);
void		set_menger(unsigned int size, unsigned int lvl);

unsigned int	**img;

int		main(int ac, char *av[])
{
  unsigned int	x = 0;
  unsigned int	pow = 0;
  t_bmp_header	header;
  t_bmp_info_header	info;
  t_point	p = {0, 0};
  unsigned int	*buffer;
  int		d;

  if (ac == 4)
    {
      x = my_getnbr(av[2]);
      pow = my_getnbr(av[3]);
    }
  if (pow > 0 && x > 0)
    {
      buffer = malloc(x * x * sizeof(*buffer));
      img = malloc(x * sizeof(*img));
      memset(buffer, 0, x * x * sizeof(*buffer));
      for (size_t i = 0; i < x; ++i)
	img[i] = buffer + i * x;

      make_bmp_header(&header, x);
      make_bmp_info_header(&info, x);
      
      draw_square(img, &p, x, 0x00000000);

      if (pow > 0 && my_pow(3, pow) <= x)
	set_menger(x, pow);

      d = open(av[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
      write(d, &header, sizeof(header));
      write(d, &info, sizeof(info));
      write(d, buffer, x * x * sizeof(*buffer));
      close(d);
      return 1;
    }
  printf("menger_face file_name size level\n");
  return (-1);
}
