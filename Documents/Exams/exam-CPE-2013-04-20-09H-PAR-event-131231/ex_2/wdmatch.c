#include <unistd.h>
#include <string.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, strlen(str));
}

void	wdmatch(char *src, char *dst)
{
  int	i;
  int	j = 0;

  for (i = 0; dst[i]; ++i)
    {
      if (dst[i] == src[j])
	++j;
    }
  if (!src[j])
    my_putstr(src);
}

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      wdmatch(av[1], av[2]);
    }
  my_putchar('\n');
  return 0;
}
