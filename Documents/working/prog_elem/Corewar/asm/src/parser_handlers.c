/*
** parser_handlers.c for asm in /home/duverd_l/Documents/Projets/corewar/asm
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Tue Jan 24 16:19:17 2012 louis duverdier
** Last update Tue Jan 24 18:21:11 2012 louis duverdier
*/

#include <asm.h>

static void	_handle_error(const char *name)
{
  my_puterr("Warning: invalid define '");
  my_puterr(name);
  my_puterr("'. Skipped.\n");
}

static void	_recurse_code(t_list *list, const char *str)
{
  int		off;

  off = 1;
  if (!my_is_space(*str))
    {
      while (str[++off] && contains(LETTER_CHARS, str[off]));
      list_append(list, node_create(T_DAT, NULL, NULL, my_strndup(str, off)));
      _recurse_code(list, str + off);
    }
  else if (*str)
    _recurse_code(list, str + 1);
}

static void	_handle_code(t_list *list, const char *str)
{
  list_append(list, node_create(T_COD, NULL, NULL, NULL));
  _recurse_code(list, str);
}

static void	_fill_define(char *tab, const char *str, int max)
{
  int		i;

  i = 0;
  while (i < max && str[i] && str[i] != '"')
    {
      tab[i] = str[i];
      ++i;
    }
  tab[i] = 0;
}

void		handle_define(t_handler *h, const char *str, int *off)
{
  int		is_name;
  char		*name;

  *off = 0;
  while (str[++(*off)] && contains(LETTER_CHARS, str[*off]));
  name = my_strndup(str + 1, *off - 1);
  is_name = !my_strcmp(name, "name") ? 1 : 0;
  if (str[*off] && str[*off + 1] == '"'
      && (is_name || !my_strcmp(name, "comment")))
    {
      if (is_name)
        _fill_define(h->head->prog_name, str + *off + 2, PROG_NAME_LENGTH);
      else
        _fill_define(h->head->comment, str + *off + 2, COMMENT_LENGTH);
    }
  else if (!my_strcmp(name, "code"))
    _handle_code(h->list, str + *off);
  else if (!my_strcmp(name, "extend"))
    h->head->magic = 1;
  else
    _handle_error(name);
  *off = my_strlen(str);
  free(name);
}
