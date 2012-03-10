/*
** main.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar/src
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Tue Feb 21 14:05:12 2012 louis duverdier
** Last update Tue Feb 21 16:47:20 2012 louis duverdier
*/

#include <corewar.h>

static void	_simulate_gaelle_part(t_handler *h, int argc, char **argv)
{
  int		tmp;
  t_champ	*champ;
  t_process	*process;

  MY_UNUSED(argc);
  MY_UNUSED(argv);

  h->mem = xmalloc((MEM_SIZE + 1) * sizeof(*h->mem));
  my_memset(h->mem, 0, MEM_SIZE + 1);
  h->mem[0] = 1;
  h->mem[1] = 0;
  h->mem[2] = 0;
  h->mem[3] = 0;
  h->mem[4] = 1;

  champ = xmalloc(sizeof(*champ));
  champ->alive = 1;
  champ->champ_id = 1;
  champ->comment = "Yo.";
  champ->name = "Test";
  champ->last_live = 0;
  champ->process_list = list_create();

  process = xmalloc(sizeof(*process));
  process->carry = 0;
  process->champ = champ;
  process->next_action = 0;
  process->pc = 1;

  tmp = 0;
  while (tmp <= REG_NUMBER)
    {
      process->reg[tmp] = 0;
      ++tmp;
    }

  h->champ_list = list_create();
  list_append(h->champ_list, node_create_from(process));
}

int		main(int argc, char **argv)
{
  t_handler	h;

  _simulate_gaelle_part(&h, argc, argv);
  /*main_loop(&h);*/
  return (EXIT_SUCCESS);
}
