#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main(void)
{
  t_queue queue = NULL;
  int i = 5;
  int j = 4;
  int *data;

  queue_push(&queue, &i);
  queue_push(&queue, &j);

  data = (int *)queue_front(queue);

  printf("%d\n", *data);

  return (0);

}
