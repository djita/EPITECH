/*
** corewar.h for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:30:55 2012 louis duverdier
** Last update Thu Jan 26 16:45:35 2012 louis duverdier
*/

#ifndef COREWAR_H_
#  define COREWAR_H_

#  include <my.h>
#  include <op.h>
#  include <list.h>
#  include <stdlib.h>

#  define MAX_FLAGS	3

enum e_flags
{
  FLAG_DUMP_DEFINED		= 1 << 0,
  FLAG_PROG_DEFINED		= 1 << 1,
  FLAG_ADDR_DEFINED		= 1 << 2
};

typedef struct s_mem
{
  unsigned char	**regs;
  unsigned char	*pc;
  unsigned char	*memory;
  int			carry;
} t_mem;

typedef struct s_handler
{
  int			flags;
  int			data[MAX_FLAGS];
  int			current_cycle;
  int			cycle_to_die;
  t_mem			*mem;
  t_list		*progs;
} t_handler;

int		handle_flag(t_handler *, const char *, int, int);
int		handle_prog(t_handler *, const char *);

#endif
