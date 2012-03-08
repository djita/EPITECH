/*
** asm.c for src in /home/czegan_g/mnt/usb/corewar/asm/src
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  mar. févr. 14 06:12:31 2012 gaby czegany
** Last update Tue Feb 21 15:55:26 2012 lyoma guillou
*/

#include <asm.h>
#include <stdio.h>

/*static void     _write(char *path, unsigned char *area, t_handler *handler)*/
/*{*/
  /*char          *file;*/
  /*char          *first;*/
  /*int           lenght;*/
  /*int           fd;*/
  /*int           mode;*/

  /*lenght = my_strlen(path) + 4;*/
  /*file = xmalloc(lenght * sizeof(file) + 4);*/
  /*first = file;*/
  /*while (*path && *path != '.')*/
  /*{*/
    /**file = *path;*/
    /*++file;*/
    /*++path;*/
  /*}*/
  /**file = '\0';*/
  /*my_strcat(first, ".cor");*/
  /*mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;*/
  /*fd = xopen_create(first, O_WRONLY | O_CREAT | O_TRUNC, mode);*/
  /*while (area != handler->last_area)*/
  /*{*/
    /*my_putchar_fd(fd, *area);*/
    /*++area;*/
  /*}*/
  /*free(first);*/
/*}*/

static void     _set(t_handler *h)
{
  h->head = xmalloc(sizeof(*(h->head)));
  my_memset(h->head->prog_name, 0, PROG_NAME_LENGTH + 1);
  my_memset(h->head->comment, 0, COMMENT_LENGTH + 1);
}

/*static void    _freed(t_handler *handler, unsigned char *area)*/
/*{*/
  /*t_node        *node;*/

  /*node = handler->list->first;*/
  /*while (node)*/
  /*{*/
    /*if (node->data)*/
      /*free(node->data);*/
    /*if (node->label)*/
      /*free(node->label);*/
    /*if (node->label_ref)*/
      /*free(node->label_ref);*/
    /*node = node->next;*/
  /*}*/
  /*free(handler->head);*/
  /*list_free(handler->list);*/
  /*free(area);*/
/*}*/

/*int             main(int argc, char **argv)*/
/*{*/
  /*t_handler     h;*/
  /*unsigned char *area;*/

  /*h.list = NULL;*/
  /*if (argc > 1)*/
  /*{*/
    /*_set(&h);*/
    /*parse(&h, argv[1]);*/
    /*printf("comment : %s\nprog_name: %s\n", h.head->comment, h.head->prog_name);*/
    /*if (h.list && check_list(&h))*/
    /*{*/
      /*area = build(&h);*/
      /*if (area)*/
        /*_write(argv[1], area, &h);*/
      /*_freed(&h, area);*/
      /*[> Pensez à free <]*/
      /*return (EXIT_SUCCESS);*/
    /*}*/
  /*}*/
  /*else*/
  /*{*/
    /*my_puterr(argv[0]);*/
    /*my_puterr(": Error: ASM file needed.\n");*/
  /*}*/
  /*return (EXIT_FAILURE);*/
/*}*/

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

int		main(int argc, char **argv)
{
  t_handler	h;
  t_node	*node;
  int		i;

  i = 0;
  h.list = NULL;
  _set(&h);
  if (argc > 1)
    parse(&h, argv[1]);
  check_list(&h);
  if (h.list)
    {
      printf("\n");
      node = h.list->first;
      while (node)
        {
	  if (node->type & T_ACT)
	    printf("\n%d\n", ++i);
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
