/*
** build.c for src in /home/czegan_g/work/school/corewar/asm/src
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  mar. févr. 14 06:15:06 2012 gaby czegany
** Last update Sun Mar 25 22:54:09 2012 lyoma guillou
*/

# include       <asm.h>

int	write_in_area(int value, uchar *ptr, int range, char state)
{
  int	i;
  int   max_value;
  int   min_value;

  min_value = state == ADD_AREA ? 0x00 : 0xFF;
  max_value = state == ADD_AREA ? 0xFF : 0x00;
  while (value > 0)
  {
    i = range - 1;
    while (i >= 0 && ptr[i] == max_value)
      ptr[i--] = min_value;
    if (i == -1)
    {
      warning("Param value overflow.");
      return (FAILURE);
    }
    if (state == ADD_AREA)
      ptr[i] += 1;
    else
      ptr[i] -= 1;
    --value;
  }
  return (SUCCESS);
}

static uchar    *_append_magic(uchar *area)
{
  int           magic;
  int           value;
  int           count;
  int           offset;

  magic = COREWAR_EXEC_MAGIC;
  value = magic;
  count = 0;
  while (value != 0)
  {
    value = value / 256;
    ++count;
  }
  count = count % 2 == 0 ? count : count + 1;
  offset = count;
  value = magic;
  while (count != 0)
  {
    value = magic % 256;
    magic = magic / 256;
    area[count - 1] = (uchar) value;
    --count;
  }
  area += offset;
  return (area);
}

static uchar    *_build_header(uchar *area, t_handler *handler)
{
  area = _append_magic(area);
  my_memcpy(area, handler->head->prog_name, PROG_NAME_LENGTH);
  area += PROG_NAME_LENGTH;
  handler->counter = area;
  area += ACTION_LENGTH;
  my_memcpy(area, handler->head->comment, COMMENT_LENGTH);
  area += COMMENT_LENGTH + 4;
  return (area);
}

static void     _remove_sep(t_list *list, t_node *node)
{
  if (node != 0)
  {
    node = node->next;
    if (node && node->prev->type & T_SEP)
      list_remove(list, node->prev);
    _remove_sep(list, node);
  }
}

uchar   *build(t_handler *handler)
{
  uchar *area;
  uchar *first_area;

  area = xmalloc(MEM_SIZE + 1);
  first_area = area;
  my_memset(area, 0, MEM_SIZE + 1);
  _remove_sep(handler->list, handler->list->first);
  area = _build_header(area, handler);
  handler->last_area = build_body(area, handler->list->first, handler);
  return (first_area);
}
