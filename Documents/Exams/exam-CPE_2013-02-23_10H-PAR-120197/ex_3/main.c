#include <stdlib.h>

static int _is_num(char c)
{
  return ((c >= '0' && c <= '9'));
}

int my_strlen(char *str)
{
  int i = 0;
  while (str[i])
    ++i;
  return i;
}

void my_memset(void *ptr, int size)
{
  int *trg = ptr;
  int i = 0;

  while (i < size)
    trg[i++] = 0;
}

char *reverse_dup(char *str)
{
  int i = my_strlen(str);
  int j = 0;
  char *dup = malloc(i * sizeof(*dup));
  while (i >= 0)
    {
      --i;
      if (_is_num(str[i]))
	{
	  dup[j] = str[i];
	  ++j;
	}
    }
  return dup;
}

void do_add(char *str, char *dst, int ret)
{
  int res = ret;
  int x = 0;
  int y = 0;
  if ((str && str[0]) || (dst && dst[0]))
    {
      x = str[0] ? str[0] - '0' : 0;
      y = dst[0] ? dst[0] - '0' : 0;
      res = x + y;
      do_add((str[0] ? str + 1 : str), (dst[0] ? dst + 1 : dst), res / 10);
      my_putchar((res % 10) + '0');
    }
}

int do_sub(char *str, char *dst, int ret, int flag)
{
  int res = ret;
  int x = 0;
  int y = 0;
  static int show = 0;
  if ((str && str[0]) || (dst && dst[0]))
    {
      x = str[0] ? str[0] - '0' : 0;
      y = dst[0] ? dst[0] - '0' : 0;
      if (3 == flag)
	res = x - (y + ret);
      else
	res = y - (x + ret);
      if (res < 0)
	{
	  res += 10;
	  ret = 1;
	}
      else
	ret = 0;
      do_sub((str[0] ? str + 1 : str), (dst[0] ? dst + 1 : dst), ret, flag);
      if (0 != res)
	show = 1;
      if (0 != show)
	my_putchar((res % 10) + '0');
    }
  return show;
}

void getNeg(char *str, char *dst, int sub)
{
  int i = 0;
  while (str[i] == dst[i])
    ++i;
  if ((1 == sub && str[i] > dst[i]) || (3 == sub && str[i] < dst[i]) || 
      4 == sub)
    my_putchar('-');
}

void infin_add(char *str, char *dst)
{
  int sub = 0;
  char *fst = reverse_dup(str);
  char *lst = reverse_dup(dst);

  if (str[0] == '-')
    sub += 1;
  if (dst[0] == '-')
    sub += 3;
  getNeg((1 == sub) ? str + 1 : str, (3 == sub) ? dst + 1 : dst, sub);
  if (!sub % 2)
    do_add(fst, lst, 0);
  else
    if (0 == do_sub(fst, lst, 0, sub))
      my_putchar('0');
}

int main(int ac, char **av)
{
  if (ac == 3)
    infin_add(av[1], av[2]);
  my_putchar('\n');
  return 0;
}