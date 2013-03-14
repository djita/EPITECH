#include <stdio.h>
#include "generic_list.h"

void int_displayer(void *data)
{
  int value;

  value = *((int *)data);
  printf("%d\n", value);
}

int int_comparator(void *first, void *second)
{
  int val1;
  int val2;

  val1 = *((int *)first);
  val2 = *((int *)second);
  return (val1 - val2);
}

int main(void)
{
  t_list list_head = NULL;
  unsigned int size;
  int i = 5;
  int j = 42;
  int k = 3;

  list_add_elem_at_back(&list_head, &i);
  list_add_elem_at_back(&list_head, &j);
  list_add_elem_at_back(&list_head, &k);

  size = list_get_size(list_head);
  printf("Il y a %u elements dans la liste\n", size);
  list_dump(list_head, &int_displayer);

  list_del_elem_at_back(&list_head);

  size = list_get_size(list_head);
  printf("Il y a %u elements dans la liste\n", size);
  list_dump(list_head, &int_displayer);

  return (0);
}
