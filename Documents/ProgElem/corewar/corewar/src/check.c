/*
** check.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Mar 15 10:37:17 2012 louis duverdier
** Last update Sat Mar 24 16:17:49 2012 louis duverdier
*/

#include "corewar.h"

int		check_id(t_handler *h, int n, int display)
{
  t_node	*node;
  t_champ	*champ;
  char		*tmp;

  if (n <= 0)
    return (1);
  node = h->champ_list->first;
  while (node)
    {
      champ = node->data;
      if (champ->champ_id == n)
        {
          if (display)
            {
              tmp = number_to_str(n);
              my_err(3, "Error: prog number -- '", tmp, "' already used.\n");
              free(tmp);
              h->done = 1;
            }
          return (0);
        }
      node = node->next;
    }
  return (1);
}

int		check_magic(t_handler *h, int fd, const char *file)
{
  int		len;
  int		tmp;
  char		magic[MAGIC_LEN];

  len = read(fd, magic, MAGIC_LEN);
  if (len != MAGIC_LEN)
    return (0);
  tmp = COREWAR_EXEC_MAGIC;
  while (len)
    {
      if ((magic[len - 1] & 0xFF) != (tmp & 0xFF))
        {
          my_err(3, "Error: file -- '", file, "' is not a corewar binary.\n");
          h->done = 1;
          return (0);
        }
      tmp >>= 8;
      --len;
    }
  return (1);
}
