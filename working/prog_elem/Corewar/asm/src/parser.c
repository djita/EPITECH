/*
** parser.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Thu Jan 19 14:37:33 2012 louis duverdier
** Last update Thu Jan 26 17:54:49 2012 lyoma guillou
*/

#include <asm.h>
#include <get_next_line.h>

static void		_handle_other(const char *str, int *off, t_node **node)
{
  int			tmp;
  char			*d;

  while (str[++(*off)] && contains(ALL_CHARS, str[*off]));
  if (str[0] == LABEL_CHAR)
    {
      d = my_strndup(str + 1, *off -1);
      *node = node_create(T_IND, d, NULL, NULL);
    }
  else if (str[0] == 'r')
    {
      if (str[*off] != LABEL_CHAR)
        *node = node_create(T_REG, NULL, NULL, my_strndup(str + 1, *off - 1));
      else
        *node = node_create(T_LAB, NULL, NULL, my_strndup(str, (*off)++));
    }
  else
    {
      d = my_strndup(str, *off);
      *off += (tmp = str[*off] == LABEL_CHAR) ? 1 : 0;
      *node = node_create(tmp ? T_LAB : is_act(d) != -1 ? T_ACT : T_IND,
        NULL, NULL, d);
    }
}

static t_node	*_create_node(const char *str, int *off)
{
  t_node		*node;
  int			tmp;

  *off = 0;
  if (*str == SEPARATOR_CHAR)
    {
      *off = 1;
      node = node_create(T_SEP, NULL, NULL, NULL);
    }
  else if (*str == DIRECT_CHAR)
    {
      *off = (tmp = str[1] == LABEL_CHAR) ? 1 : 0;
      while (str[++(*off)] && contains(ALL_CHARS, str[*off]));
      node = node_create(T_DIR, tmp ? my_strndup(str + 2, *off - 2) : NULL,
        NULL, tmp ? NULL : my_strndup(str + 1, *off - 1));
    }
  else
    _handle_other(str, off, &node);
  return (node);
}

static void		_parse_line(t_handler *h, const char *str)
{
  int			i;

  i = 0;
  if (!my_is_space(*str) && *str != COMMENT_CHAR)
    {
      if (*str == '.')
        handle_define(h, str, &i);
      else
        list_append(h->list, _create_node(str, &i));
      _parse_line(h, str + i);
    }
  else if (*str && *str != COMMENT_CHAR)
    _parse_line(h, str + 1);
}

void	_init_handler(t_handler *h)
{
  h->head = xmalloc(sizeof(*(h->head)));
  h->head->comment[0] = 0;
  h->head->prog_name[0] = 0;
  h->head->magic = 0;
  h->list = list_create();
}

void	parse(t_handler *h, const char *path)
{
  int	fd;
  char	*buffer;

  _init_handler(h);
  fd = xopen(path, O_RDONLY);
  while ((buffer = get_next_line(fd)))
    {
      _parse_line(h, buffer);
      free(buffer);
    }
  set_labels(h->list);
  xclose(fd);
}

#include <stdio.h>

const char	*get_type(int type)
{
  if (type & T_ACT)
    return ("T_ACT");
  if (type & T_DIR)
    return ("T_DIR");
  if (type & T_IND)
    return ("T_IND");
  if (type & T_SEP)
    return ("T_SEP");
  if (type & T_REG)
    return ("T_REG");
  if (type & T_COD)
    return ("T_COD");
  if (type & T_DAT)
    return ("T_DAT");
  return ("Unknown");
}

int			main(int argc, char **argv)
{
  t_handler	h;
  t_node	*node;

  h.list = NULL;
  if (argc > 1)
    parse(&h, argv[1]);
  check_list(&h);
  if (h.list)
    {
      printf("\n");
      node = h.list->first;
      while (node)
        {
          printf("Type: %s%s, Label: %s, Label_ref: %s, Data: %s\n",
                 get_type(node->type),
                 node->type & T_LAB ? " | T_LAB" : "",
                 node->label ? node->label : "NULL",
                 node->label_ref ? node->label_ref : "NULL",
                 node->data ? node->data : "NULL");
          if (node->data)
            free(node->data);
          if (node->label)
            free(node->label);
          if (node->label_ref)
            free(node->label_ref);
          node = node->next;
        }
      list_free(h.list);
      printf("\nName: %s\nComment: %s\nMode %sextended.\n\n",
             h.head->prog_name, h.head->comment, h.head->magic ? "" : "non ");
      free(h.head);
    }
  return (EXIT_SUCCESS);
}
