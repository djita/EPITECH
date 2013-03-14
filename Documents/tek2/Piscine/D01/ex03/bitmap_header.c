/*
** bitmap_header.c for bitmap in /home/guillo_e//Documents/working/tek2/piscine/D01/ex02
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan  9 17:04:09 2013 lyoma guillou
** Last update Wed Jan  9 18:16:13 2013 lyoma guillou
*/

#include "bitmap.h"

void		make_bmp_header(t_bmp_header *header, size_t size)
{
  header->magic = 0x4D42;
  header->_app1 = 0;
  header->_app2 = 0;
  header->offset = sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
  header->size = header->offset + (size * size) * (BPP / 8);
}

void		make_bmp_info_header(t_bmp_info_header *header, size_t size)
{
  header->size = sizeof(t_bmp_info_header);
  header->width = size;
  header->height = size;
  header->planes = 1;
  header->bpp = BPP;
  header->compression = 0;
  header->raw_data_size = size * size * (BPP / 8);
  header->h_resolution = 0;
  header->v_resolution = 0;
  header->palette_size = 0;
  header->important_colors = 0;
}
