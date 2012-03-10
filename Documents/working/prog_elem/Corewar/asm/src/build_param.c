/*
** build_param.c for src in /home/czegan_g/project/current/corewar/asm/src
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  mar. févr. 14 06:15:14 2012 gaby czegany
** Last update mer. févr. 15 21:38:59 2012 gaby czegany
*/

#include <asm.h>

static unsigned char	*_act(unsigned char *area, t_node *node, t_handler *h)
{
  int		key;
  int		i;

  MY_UNUSED(h);
  if (node->data)
    key = is_act(node->data);
  if (key == -1)
    return (area);
  *area = op_tab[key].code;
  if (op_tab[key].nbr_args < 2)
    return (++area);
  i = 0;
  ++area;
  node = node->next;
  while (node && i < MAX_ARGS_NUMBER)
  {
    if (i < op_tab[key].nbr_args)
    {
      node = node->next;
      *area = (*area | get_param(node->type)) << 2;
    }
    else
      *area = *area << 2;
    ++i;
  }
  return (++area);
}

static unsigned char    *(*ftype[TOTAL_TYPE])(unsigned char *, t_node *, t_handler *) =
{
  _act,
  /*_register,*/
  /*_direct,*/
  /*_indirect*/
};

/*unsigned char*/
/**build_param(unsigned char *area, t_node *node, t_handler *h, int acc)*/
/*{*/
  /*int           i;*/

  /*if (node && acc < MEM_SIZE)*/
  /*{*/
    /*i = 0;*/
    /*while (i < TOTAL_TYPE)*/
    /*{*/
      /*area = (*ftype[i])(area, node, h);*/
      /*++i;*/
    /*}*/
    /*++acc;*/
    /*node = node->next;*/
    /*build_param(area, node, h, acc);*/
  /*}*/
  /*return (area);*/
/*}*/
