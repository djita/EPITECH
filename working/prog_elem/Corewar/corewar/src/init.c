/*
** init.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 16:39:21 2012 louis duverdier
** Last update Thu Jan 26 17:48:39 2012 louis duverdier
*/

#include <corewar.h>

static void	_puterr(const char *beg, const char *d, const char *end)
{
  my_puterr(beg);
  my_puterr(d);
  my_puterr(end);
}

static void	___REPLACE__ME___(t_handler *h, const char *d)
{
  /* DO SOMETHING HERE */
  (void)h;
  (void)d;
  /* DO SOMETHING HERE */
}

static int	_check_format(t_node *node, const char *buff)
{
  int		magic;
  int		tmp;
  int		i;

  magic = COREWAR_EXEC_MAGIC;
  tmp = magic;
  i = 0;
  if (node->head->prog_size <= PROG_NAME_LENGTH + COMMENT_LENGTH + 16)
    return (0);
  while (tmp)
    {
      tmp = tmp >> 8;
      ++i;
    }
  while (magic)
    {
      if ((buff[i] & 0xFF) != (magic & 0xFF))
        return (0);
      magic = magic >> 8;
      --i;
    }
  return (1);
}

int	handle_flag(t_handler *h, const char *d, int flag, int flag_nbr)
{
  if (d)
    {
      h->flags |= flag;
      h->data[flag_nbr] = my_getnbr(d);
      return (1);
    }
  return (0);
}

int 		handle_prog(t_handler *h, const char *d)
{
  int		fd;
  char		*buff;
  t_node	*node;

  if (d)
    {
      node = node_create();
      fd = xopen(d, O_RDONLY);
      buff = xmalloc(MEM_SIZE * sizeof(*buff));
      node->head->prog_size = read(fd, buff, MEM_SIZE);
      xclose(fd);
      if (node->head->prog_size == -1 || !_check_format(node, buff))
        {
          if (node->head->prog_size == -1)
            _puterr("Error: failed to read the file '", d, "'.\n");
          else
            _puterr("Error: '", d, "' is not a corewar executable.\n");
          free(buff);
          free(node->head);
          free(node);
          return (0);
        }
      list_append(h->progs, node);
      ___REPLACE__ME___(h, buff);
      free(buff);
      return (1);
    }
  return (0);
}
