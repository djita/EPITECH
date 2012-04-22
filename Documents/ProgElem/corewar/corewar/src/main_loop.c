/*
** main_loop.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Tue Feb 21 17:06:57 2012 louis duverdier
** Last update Sat Mar 24 16:03:37 2012 louis duverdier
*/

#include "corewar.h"

static void	_display_winner(t_handler *h)
{
  t_node	*node;
  t_champ	*champ;

  node = h->champ_list->first;
  while (node)
    {
      champ = node->data;
      if (champ->alive)
        {
          my_putstr("Le joueur ");
          my_putnbr(champ->champ_id);
          my_putstr(" (");
          my_putstr(champ->name);
          my_putstr(") a gagne.\n");
          return;
        }
      else
        node = node->next;
    }
}

static void	_handle_death_state(t_handler *h, t_champ *champ)
{
  if (h->current_cycle - champ->last_live > h->cycle_to_die)
    {
      champ->alive = 0;
      --(h->alive_nbr);
      if (h->alive_nbr == 1)
        {
          _display_winner(h);
          h->done = 1;
        }
    }
}

static void	_prepare_or_process(t_handler *h, t_process *p, int prep)
{
  int		i;
  char		code;

  if (prep)
    {
      i = -1;
      code = h->mem[p->pc % MEM_SIZE];
      while (h->act_ptr[++i].fnc)
        {
          if (h->act_ptr[i].code == code && code)
            {
              printf("Champion %d does act '%s' (cycle: %d).\n", p->champ->champ_id, op_tab[i].mnemonique, h->current_cycle);
              p->act = h->act_ptr[i].fnc;
              p->next_action += op_tab[i].nbr_cycles;
              p->exec_cycle = p->next_action - 1;
              return;
            }
        }
      ++p->next_action;
      ++p->pc;
    }
  else if (p->act)
    {
      (p->act)(h, p);
      p->act = NULL;
    }
}

static void	_process_all(t_handler *h)
{
  t_node	*node;
  t_node	*pr_node;
  t_champ	*champ;
  t_process	*process;

  node = h->champ_list->first;
  while (node)
    {
      champ = node->data;
      if (champ->alive)
        {
          pr_node = champ->process_list->first;
          while (pr_node)
            {
              process = pr_node->data;
              if (process->next_action == h->current_cycle)
                _prepare_or_process(h, process, 1);
              else if (process->exec_cycle == h->current_cycle)
                _prepare_or_process(h, process, 0);
              pr_node = pr_node->next;
            }
          _handle_death_state(h, champ);
        }
      node = node->next;
    }
}

void	main_loop(t_handler *h)
{
  h->done = 0;
  while (!h->done && h->alive_nbr > 1 && h->cycle_to_die > 0)
    {
      _process_all(h);
      if (h->cycle_to_dump == h->current_cycle)
        {
          dump_memory(h);
          h->done = 1;
        }
      ++h->current_cycle;
      if (h->current_cycle % NBR_LIVE == 0)
        h->cycle_to_die -= CYCLE_DELTA;
    }
  if (!h->done)
    _display_winner(h);
}
