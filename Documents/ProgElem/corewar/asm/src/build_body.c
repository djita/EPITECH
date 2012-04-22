/*
** build_body.c for src in /home/czegan_g/work/school/corewar/asm/src
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  mar. févr. 21 17:23:26 2012 gaby czegany
** Last update Sun Mar 25 23:00:45 2012 lyoma guillou
*/

# include       <asm.h>

static int      _previous(t_node *node, int *value, char *label)
{
  int           position;
  int           state;
  int           ret;
  t_node        *tmp;

  tmp = node->prev;
  state = FAILURE;
  position = 0;
  while (state != STOP && tmp && tmp)
  {
    if (tmp->type & T_ACT && state == SUCCESS)
    {
      ret = position;
      state = STOP;
    }
    if (tmp->label_ref
        && !my_strcmp(label, tmp->label_ref))
      state = SUCCESS;
    position += get_length(tmp);
    tmp = tmp->prev;
  }
  if (state == FAILURE)
    return (ERROR);
  *value = ret;
  return (LABEL_BEFORE);
}

int             get_label(t_node *node, int *value, char *label)
{
  int           position;
  int           ret;
  int           state;
  t_node        *tmp;

  tmp = node;
  state = FAILURE;
  position = 0;
  while (state != STOP && tmp)
  {
    if (tmp->type & T_ACT)
      ret = position;
    if (tmp->label_ref
        && !my_strcmp(label, tmp->label_ref))
      state = STOP;
    position += get_length(tmp);
    tmp = tmp->next;
  }
  if (state == FAILURE)
    return (_previous(node, value, label));
  *value = ret;
  return (LABEL_AFTER);
}

static uchar    *_action(t_handler *h, uchar *area, t_node *node)
{
  int           action;
  int           description;

  if ((action = is_act(node->data)) == -1)
    return (area);
  *area = op_tab[action].code;
  write_in_area(1, h->counter, COUNTER_LEN, ADD_AREA);
  node = node->next;
  ++area;
  description = op_tab[action].nbr_args;
  if (description > 1 || action == 15)
  {
    action = 0;
    while (action < 3)
    {
      *area = action < description
        ? (*area | get_param(node->type)) << 2 : *area << 2;
      node = action < description ? node->next : node;
      ++action;
    }
    write_in_area(1, h->counter, COUNTER_LEN, ADD_AREA);
    ++area;
  }
  return (area);
}

static uchar    *_code(t_handler *h, uchar *area, t_node *node)
{
  int           value;

  value = my_getnbr_hexa(node->data);
  write_in_area(value, area, 1, ADD_AREA);
  write_in_area(2, h->counter, COUNTER_LEN, ADD_AREA);
  ++area;
  return (area);
}

uchar   *build_body(uchar *area, t_node *node, t_handler *h)
{
  if (node)
  {
    if (node->type & T_ACT)
    {
      area = _action(h, area, node);
      h->last_act = node;
    }
    else if (node->type & T_DAT)
      area = _code(h, area, node);
    else
      area = build_param(h, node, area);
    node = node->next;
    return (build_body(area, node, h));
  }
  return (area);
}
