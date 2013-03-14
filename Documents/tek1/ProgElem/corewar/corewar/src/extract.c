/*
** extract.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Wed Mar 14 14:07:07 2012 louis duverdier
** Last update Wed Mar 14 16:05:32 2012 louis duverdier
*/

#include "corewar.h"

static int	_read_data(int fd, char **dest, int len)
{
  int		i;

  *dest = xmalloc((len + 1) * sizeof(**dest));
  if ((i = read(fd, *dest, len)) <= 0)
    (*dest)[0] = 0;
  else
    (*dest)[i] = 0;
  return (i);
}

static void	_handle_padding(int fd, int len)
{
  char		*padding;

  padding = xmalloc(len * sizeof(*padding));
  if (read(fd, padding, len) <= 0)
    {
    }
  free(padding);
}

void	extract_data(int fd, t_champ *champ)
{
  int	len;

  _read_data(fd, &champ->name, PROG_NAME_LENGTH);
  _handle_padding(fd, NAME_PADDING);
  _read_data(fd, &champ->comment, COMMENT_LENGTH);
  _handle_padding(fd, COMMENT_PADDING);
  if ((len = _read_data(fd, &champ->mem, MEM_SIZE)) < 0)
    champ->mem_len = 0;
  else
    champ->mem_len = len;
}
