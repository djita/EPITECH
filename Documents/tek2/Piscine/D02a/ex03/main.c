#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
 
int main(void)
{
  t_stack stack = NULL;
  int i = 5;
  int j = 4;
  int *data;

  stack_push(&stack, &i);
  stack_push(&stack, &j);

  data = (int *)stack_top(stack);

  printf("%d\n", *data);
  return (0);

}
