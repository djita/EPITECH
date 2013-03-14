#include "ptr_tricks.h"

t_whatever	*get_struct_ptr(int *member_ptr);

int main(void)
{
  t_whatever test;
  t_whatever *ptr;

  printf("%p\n%p\n", &test, ptr);
  ptr = get_struct_ptr(&test.member);
  printf("%p\n", ptr);
  if (ptr == &test)
    printf("Ca marche !\n");
  return (0);

}
