/*
** build_param.c for src in /home/czegan_g/work/school/corewar/asm/src
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  mar. févr. 14 06:15:14 2012 gaby czegany
** Last update dim. mars 25 18:28:56 2012 gaby czegany
*/

# include       <asm.h>

static int      _fill_memory(uchar *area, int range)
{
  int   count;

  count = 0;
  while (count < range)
  {
    *area = 0xFF;
    ++area;
    ++count;
  }
  return (count);
}

static uchar    *_write_dir(t_handler *h, uchar *area, t_node *node)
{
  int           value;
  int           ret;

  ret = 0;
  if (node->label)
    ret = get_label(h->last_act, &value, node->label);
  else if (node->data)
    value = my_getnbr(node->data);
  write_in_area(DIR_SIZE, h->counter, COUNTER_LEN, ADD_AREA);
  if (ret == LABEL_BEFORE || value < 0)
  {
    _fill_memory(area, DIR_SIZE);
    write_in_area(ABS(value), area, DIR_SIZE, SUB_AREA);
  }
  else
    write_in_area(value, area, DIR_SIZE, ADD_AREA);
  area += DIR_SIZE;
  return (area);
}

static uchar    *_write_ind(t_handler *h, uchar *area, t_node *node)
{
  int           value;
  int           ret;

  ret = 0;
  if (node->label)
    ret = get_label(h->last_act, &value, node->label);
  else if (node->data)
    value = my_getnbr(node->data);
  write_in_area(IND_SIZE, h->counter, COUNTER_LEN, ADD_AREA);
  if (ret == LABEL_BEFORE || value < 0)
  {
    _fill_memory(area, IND_SIZE);
    write_in_area(ABS(value), area, IND_SIZE, SUB_AREA);
  }
  else
    write_in_area(value, area, IND_SIZE, ADD_AREA);
  area += IND_SIZE;
  return (area);
}

static uchar    *_write_reg(t_handler *h, uchar *area, t_node *node)
{
  int           value;

  value = my_getnbr(node->data);
  write_in_area(value, area, 1, ADD_AREA);
  write_in_area(1, h->counter, COUNTER_LEN, ADD_AREA);
  area += 1;
  return (area);
}

static const t_param	type_handler[MAX_PARAM] =
{
  { T_REG, _write_reg },
  { T_IND, _write_ind },
  { T_DIR, _write_dir }
};

uchar   *build_param(t_handler *h, t_node *node, uchar *area)
{
  int   action;
  int   i;

  i = 0;
  action = is_act(h->last_act->data);
  while (i < MAX_PARAM)
  {
    if (node->type & type_handler[i].flag)
    {
      if (type_handler[i].flag & T_DIR && action > 7 && action < 12)
        area = _write_ind(h, area, node);
      else
        area = type_handler[i].fnc(h, area, node);
      return (area);
    }
    ++i;
  }
  return (area);
}
