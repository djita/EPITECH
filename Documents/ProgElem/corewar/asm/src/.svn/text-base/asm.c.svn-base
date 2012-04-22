/*
** asm.c for src in /home/czegan_g/work/school/corewar/asm/src
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  mar. févr. 14 06:12:31 2012 gaby czegany
** Last update dim. mars 25 19:29:40 2012 gaby czegany
*/

# include       <asm.h>

static void     _write(char *path, unsigned char *area, t_handler *handler)
{
  char          *file;
  char          *first;
  int           lenght;
  int           fd;
  int           mode;

  lenght = my_strlen(path) + 4;
  file = xmalloc(lenght * sizeof(file) + 4);
  first = file;
  while (*path && (my_strcmp(path, ".s")))
  {
    *file = *path;
    ++file;
    ++path;
  }
  *file = '\0';
  my_strcat(first, ".cor");
  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  fd = xopen_create(first, O_WRONLY | O_CREAT | O_TRUNC, mode);
  while (area != handler->last_area)
  {
    my_putchar_fd(fd, *area);
    ++area;
  }
  free(first);
}

static void     _configure(t_handler *h, uchar *area, char set)
{
  t_node        *node;

  if (set & FREED)
  {
    node = h->list->first;
    while (node)
    {
      if (node->data)
        free(node->data);
      if (node->label)
        free(node->label);
      if (node->label_ref)
        free(node->label_ref);
      node = node->next;
    }
    free(h->head);
    list_free(h->list);
    if (area)
      free(area);
    return;
  }
  h->head = xmalloc(sizeof(*(h->head)));
  my_memset(h->head->prog_name, 0, PROG_NAME_LENGTH + 1);
  my_memset(h->head->comment, 0, COMMENT_LENGTH + 1);
}

static int      _check_header(t_handler *handler)
{
  if (my_strlen(handler->head->prog_name) == PROG_NAME_LENGTH)
  {
    error("Prog_name too long.");
    return (FAILURE);
  }
  if (my_strlen(handler->head->comment) == COMMENT_LENGTH)
  {
    error("Comment too long.");
    return (FAILURE);
  }
  return (SUCCESS);
}

static int      _main_loop(char *file)
{
  t_handler     h;
  uchar         *area;

  h.list = NULL;
  area = NULL;
  _configure(&h, area, ALLOC);
  parse(&h, file);
  if (h.list && _check_header(&h) && check_list(&h))
  {
    area = build(&h);
    if (area)
      _write(file, area, &h);
    _configure(&h, area, FREED);
    return (SUCCESS);
  }
  _configure(&h, area, FREED);
  return (FAILURE);
}

int     main(int ac, char **av)
{
  int   i;
  int   ret;

  if (ac <= 1)
  {
    error("Missing ASM file.");
    usage(av[0]);
    return (EXIT_FAILURE);
  }
  i = 1;
  while (i < ac)
  {
    msg("Build...", av[i]);
    ret = _main_loop(av[i]);
    if (ret == SUCCESS)
      msg("Done.\n", av[i]);
    else
      msg("Failure.\n", av[i]);
    ++i;
  }
  exit(EXIT_SUCCESS);
}
