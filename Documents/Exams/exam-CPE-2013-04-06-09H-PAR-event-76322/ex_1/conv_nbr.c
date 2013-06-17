#include <stdio.h>
#include <strings.h>
#include <string.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_memset(void *tab, int c, int size)
{
  char	*tmp = tab;
  int	i = 0;

  for (i = 0; i <= size; ++i)
    tmp[i] = c;
}

int	_is_valid_base(char *str)
{
  char	tab[256];
  int	i = 0;
  int	val = 0;

  my_memset(tab, 0, 256);
  for (i = 0; str[i]; ++i)
    {
      val = str[i];
      if (!tab[val])
	tab[val] = 1;
      else
	return 0;
    }
  return ((i >= 2));
}

int	get_val(char c, char *base)
{
  int	i = 0;

  for (i = 0; base[i]; ++i)
    if (c == base[i])
      return i;
  return 0;
}

int	my_pow(int x, int n)
{
  if (n > 0)
    return (x * my_pow(x, n - 1));
  return 1;
}

int	my_getnbr_base(char *str, char *base)
{
  int	x;
  if (str[0])
    {
      x = my_getnbr_base(str + 1, base);
      x += get_val(str[0], base) * my_pow(strlen(base), strlen(str) - 1);
      return ((str[0] == '-') ? -x : x);
    }
  return 0;
}

void	my_int_to_base(int nb, char *base)
{
  int	len = strlen(base);
  if (nb < 0)
    my_putchar('-');
  if (nb >= len || nb <= (-len))
    my_int_to_base((nb < 0) ? (nb / -len) : (nb / len), base);
  my_putchar(base[(nb < 0) ? -1 * nb % -len : nb % len]);
}

int	main(int ac, char **av)
{
  if (ac == 4)
    if (_is_valid_base(av[2]) && _is_valid_base(av[3]))
      my_int_to_base(my_getnbr_base(av[1], av[2]), av[3]);
  my_putchar('\n');
}
