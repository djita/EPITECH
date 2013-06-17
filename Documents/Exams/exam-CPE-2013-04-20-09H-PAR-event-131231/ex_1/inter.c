#define _BSD_SOURCE

#include <string.h>
#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

static int	_is_shown(char c)
{
  static int	tab[256];
  int		index = c;
  
  if (!tab[index])
    {
      tab[index] = 1;
      return 0;
    }
  return 1;
}

void		inter(char *src, char *dst)
{
  int		i;
  int		j;

  for (i = 0; src[i]; ++i)
    for (j = 0; dst[j]; ++j)
      if (src[i] == dst[j] && !_is_shown(src[i]))
	my_putchar(src[i]);
}

int		main(int ac, char *av[])
{
  if (ac == 3)
    {
      inter(av[1], av[2]);
    }
  my_putchar('\n');
  return 0;
}
