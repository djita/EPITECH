/*
** build.c for src in /home/czegan_g/project/current/corewar/asm/src
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  mar. févr. 14 06:15:06 2012 gaby czegany
** Last update mar. févr. 21 14:52:37 2012 gaby czegany
*/

#include <asm.h>

static unsigned char    *_append_magic(unsigned char *area)
{
  int                   magic;
  int                   value;
  int                   count;
  int                   offset;

  magic = COREWAR_EXEC_MAGIC;
  value = magic;
  count = 0;
  while (value)
  {
    value = value / 256;
    ++count;
  }
  count = count % 2 == 0 ? count : count + 1;
  offset = count;
  value = magic;
  while (count)
  {
    value = magic % 256;
    magic = magic / 256;
    area[count - 1] = (unsigned char) value;
    --count;
  }
  area += offset;
  return (area);
}

static unsigned char    *_build_header(unsigned char *area, t_handler *handler)
{
  int   i = 0;
  if (MEM_SIZE > PROG_NAME_LENGTH && MEM_SIZE > COMMENT_CHAR)
  {
    area = _append_magic(area);
    my_memcpy(area, handler->head->prog_name, PROG_NAME_LENGTH);
    area += PROG_NAME_LENGTH;
    handler->cursor = area; /* Cursor @ last action number */
    while (i < 1000)
    {
    add_size(1111, handler->cursor);
    add_size(1111, handler->cursor);
    add_size(1111, handler->cursor);
    add_size(1111, handler->cursor);
    add_size(11111, handler->cursor);
    add_size(11111, handler->cursor);
    add_size(11111, handler->cursor);
    add_size(11111, handler->cursor);
    ++i;
    }
    area += ACTION_LENGTH;
    my_memcpy(area, handler->head->comment, COMMENT_LENGTH);
    area += COMMENT_LENGTH + 4;
    return (area);
  }
  my_puterr("Error: Overflow memory. Exit");
  return (FAILURE);
}

static void     _remove_sep(t_list *list, t_node *node)
{
  if (node)
  {
    node = node->next;
    if (node && node->prev->type & T_SEP)
      list_remove(list, node->prev);
    _remove_sep(list, node);
  }
}

unsigned char   *build(t_handler *handler)
{
  unsigned char *area;
  unsigned char *first_area;

  /* Fill area */
  area = xmalloc(MEM_SIZE + 1);
  first_area = area;
  my_memset(area, 0, MEM_SIZE + 1);

  _remove_sep(handler->list, handler->list->first);

  area = _build_header(area, handler);
  /*if (area)*/
    /*area = build_param(area,handler->list->first, handler, 0);*/
  handler->last_area = area;
  return (first_area);
}
