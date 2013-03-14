/*
** parse.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Wed Mar 14 09:14:51 2012 louis duverdier
** Last update Sat Mar 24 16:17:40 2012 louis duverdier
*/

#include "corewar.h"

static int	_get_id(t_handler *h)
{
  int		i;

  i = 1;
  while (i > 0)
    {
      if (check_id(h, i, 0))
        return (i);
      ++i;
    }
  return (-1);
}

static int	_handle_file(t_handler *h,
                             const char *file,
                             int *opt_n,
                             int *opt_a)
{
  int		fd;
  t_champ	*champ;
  t_process	*process;

  if ((fd = open(file, O_RDONLY)) == -1)
    {
      my_puterr("Error: cannot open the file in read mode.\n");
      return (0);
    }
  if (!check_magic(h, fd, file))
    return (0);
  champ = create_champ(*opt_n, *opt_a);
  process = create_process(champ);
  list_append(champ->process_list, node_create_from(process));
  list_append(h->champ_list, node_create_from(champ));
  extract_data(fd, champ);
  if (close(fd) == -1)
    my_puterr("Warning: cannot close the given fd. Skipped.\n");
  return (1);
}

static void	_load_mem(t_handler *h, int curr, t_champ *c, t_process *p)
{
  if (!p)
    return;
  if (c->mem_pos < 0)
    c->mem_pos = MEM_SIZE / h->alive_nbr * curr;
  else
    c->mem_pos = c->mem_pos % MEM_SIZE;
  p->pc = c->mem_pos % MEM_SIZE;
  insert(h, c->mem, c->mem_pos, c->mem_len);
}

void		init_mem(t_handler *h)
{
  int		curr;
  t_node	*node;
  t_champ	*champ;
  t_process	*process;

  curr = 1;
  node = h->champ_list->first;
  while (node)
    {
      champ = node->data;
      if (champ->process_list->first)
        process = champ->process_list->first->data;
      if (champ->champ_id <= 0)
        {
          champ->champ_id = _get_id(h);
          process->reg[0] = champ->champ_id;
        }
      _load_mem(h, curr, champ, process);
      ++curr;
      node = node->next;
    }
}

int	parse_file(t_handler *h, const char *file, int *opt_n, int *opt_a)
{
  int	valid;

  valid = check_id(h, *opt_n, 1) && _handle_file(h, file, opt_n, opt_a);
  h->alive_nbr += valid ? 1 : 0;
  *opt_n = -1;
  *opt_a = -1;
  return (valid);
}
