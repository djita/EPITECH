/*
** paramsum.c for paramsum in /exam//rendu
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Oct 15 18:21:27 2010 exam_user
** Last update Fri Oct 15 19:32:00 2010 exam_user
*/

int	my_putchar(char c)
{
  write (1, &c, 1);
}

int	paramsum()
{
  int	tab; 
  int	i;

  i = 0;
  if(paramsum[0] == '\o')
    {
      my_putchar('0');
      return();
    }
  while(paramsum[i])
    {
      tab[i] = paramsum[i];
      i = i + 1;
    }
  printf("%i\n");
}

int	main()
{
  paramsum();
}
