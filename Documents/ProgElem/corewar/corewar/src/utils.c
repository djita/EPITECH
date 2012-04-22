/*
** utils.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Tue Mar 13 12:48:25 2012 louis duverdier
** Last update Sat Mar 24 16:54:12 2012 louis duverdier
*/

#include "corewar.h"

static int	_data_char(t_handler *h, int from)
{
  unsigned char	data;

  data = h->mem[from % MEM_SIZE] & 0xFF;
  return ((char)data);
}

static int		_data_short(t_handler *h, unsigned int from, int len)
{
  int			i;
  unsigned short int	data;

  i = 0;
  data = 0;
  while (i < len)
    {
      data = data * 256 + (h->mem[(from + i) % MEM_SIZE] & 0xFF);
      ++i;
    }
  return ((short int)data);

}

static int	_data_int(t_handler *h, unsigned int from, int len)
{
  int		i;
  unsigned int	data;

  i = 0;
  data = 0;
  while (i < len)
    {
      data = data * 256 + (h->mem[(from + i) % MEM_SIZE] & 0xFF);
      ++i;
    }
  return (data);
}

int	data_int(t_handler *h, unsigned int from, int len)
{
  if (len == sizeof(char))
    return _data_char(h, from);
  if (len == sizeof(short int))
    return _data_short(h, from, len);
  return _data_int(h, from, len);
}

void	insert(t_handler *h, const char *data, unsigned int from, int len)
{
  int	i;

  i = 0;
  while (len > 0 && i < len)
    {
      h->mem[(from + i) % MEM_SIZE] = data[i];
      ++i;
    }
}
