/*
** main.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:13:11 2012 louis duverdier
** Last update Thu Jan 26 17:12:38 2012 louis duverdier
*/

#include <corewar.h>

static void	_print_usage()
{
  my_puterr("Usage: corewar [-dump nbr_cycle] "
    "[[-n prog_number] [-a load_address ] prog_name]\n");
}

static void	_init_handler(t_handler *h, t_mem *m)
{
  int		i;

  i = 0;
  while (i < MAX_FLAGS)
    h->data[i++] = 0;
  h->flags = 0;
  h->progs = list_create();
  h->current_cycle = 0;
  h->cycle_to_die = CYCLE_TO_DIE;
  h->mem = m;
  m->carry = 0;
  m->memory = my_memset(xmalloc(MEM_SIZE * sizeof(*(m->memory))), 0, MEM_SIZE);
  m->pc = my_memset(xmalloc(REG_SIZE * sizeof(*(m->pc))), 0, REG_SIZE);
  m->regs = xmalloc((REG_NUMBER + 1) * sizeof(*(m->regs)));
  i = 0;
  while (i < REG_NUMBER)
    {
      m->regs[i] = xmalloc(REG_SIZE * sizeof(*(m->regs[i])));
      my_memset(m->regs[i], 0, REG_SIZE);
      ++i;
    }
  m->regs[i] = NULL;
}

static void	_free_handler(t_handler *h)
{
  int		i;

  i = 0;
  while (h->mem->regs[i])
    free(h->mem->regs[i++]);
  free(h->mem->regs);
  free(h->mem->memory);
  free(h->mem->pc);
  list_free(h->progs);
}

static int	_parse_args(t_handler *h, int argc, char **argv)
{
  int	i;
  char	*d;

  i = 0;
  while (i < argc)
    {
      d = i + 1 < argc ? argv[i + 1] : NULL;
      if (!my_strcmp(argv[i], "-dump")
          && !handle_flag(h, d, FLAG_DUMP_DEFINED, 0))
        return (0);
      else if (!my_strcmp(argv[i], "-n")
          && !handle_flag(h, d, FLAG_PROG_DEFINED, 1))
        return (0);
      else if (!my_strcmp(argv[i], "-a")
          && !handle_flag(h, d, FLAG_ADDR_DEFINED, 2))
        return (0);
      else if (!handle_prog(h, argv[i]))
        return (0);
      ++i;
    }
  return (1);
}

int			main(int argc, char **argv)
{
  t_mem		m;
  t_handler	h;

  if (argc < 1)
    {
      _print_usage();
      return (EXIT_FAILURE);
    }
  _init_handler(&h, &m);
  if (!_parse_args(&h, argc - 1, argv + 1))
    {
      _print_usage();
      _free_handler(&h);
      return (EXIT_FAILURE);
    }
  _free_handler(&h);
  return (EXIT_SUCCESS);
}
