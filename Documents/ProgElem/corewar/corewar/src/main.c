/*
** main.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar/src
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Tue Feb 21 14:05:12 2012 louis duverdier
** Last update Sat Mar 24 16:19:02 2012 louis duverdier
*/

#include "corewar.h"

static void	_usage()
{
  my_putstr("Usage: corewar [-dump nbr_cycle] [[-n prog_number] "
            "[-a load_address ] prog_name] ...\n");
}

static void	_parse_cmd(t_handler *h, int argc, char **argv)
{
  int		i;
  int		valid;
  int		opt_n;
  int		opt_a;

  i = 1;
  valid = 1;
  opt_n = -1;
  opt_a = -1;
  while (valid && i < argc)
    {
      if (!my_strcmp(argv[i], "-dump") && i + 1 < argc)
        h->cycle_to_dump = my_getnbr(argv[++i]);
      else if (!my_strcmp(argv[i], "-n") && i + 1 < argc)
        opt_n = my_getnbr(argv[++i]);
      else if (!my_strcmp(argv[i], "-a") && i + 1 < argc)
        opt_a = my_getnbr_hex(argv[++i]);
      else if (argv[i][0] != '-')
        valid = parse_file(h, argv[i], &opt_n, &opt_a);
      else
        valid = 0;
      ++i;
    }
  if (!valid)
    my_err(3, "Error: invalid data -- '", argv[i - 1], "'.\n");
}

static void	_init_handler(t_handler *h)
{
  h->mem = xmalloc((MEM_SIZE + 1) * sizeof(*h->mem));
  my_memset(h->mem, 0, MEM_SIZE + 1);
  h->champ_list = list_create();
  h->cycle_to_dump = -1;
  h->cycle_to_die = CYCLE_TO_DIE;
  h->current_cycle = 0;
  h->alive_nbr = 0;
  h->done = 0;
}

int		main(int argc, char **argv)
{
  t_handler	h;

  if (argc < 2)
    {
      _usage();
      return (EXIT_FAILURE);
    }
  _init_handler(&h);
  _parse_cmd(&h, argc, argv);
  if (!h.done && h.alive_nbr > 0)
    {
      init_mem(&h);
      init_ptr(&h);
      main_loop(&h);
    }
  else
    _usage();
  return (EXIT_SUCCESS);
}
