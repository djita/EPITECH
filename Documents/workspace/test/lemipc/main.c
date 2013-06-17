#include <sys/types.h>
#include <sys/ipc.h>

#include <stdio.h>

int	main()
{
  key_t	key = 0;

  key = ftok(NULL, 0);
  if (key >= 0)
    fprintf(stdout, "my key= %d\n", key);
  else
    fpritnf(stderr, "ftok failed?\n");
  return;
}
