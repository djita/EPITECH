#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

typedef struct	s_train
{
  int		num;
  int		pos;
}		t_train;

pthread_mutex_t	m_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t	m_goes = PTHREAD_MUTEX_INITIALIZER;

void		show_train(t_train train)
{
  int i;

  i = 0;
  printf("Train n%d : ", train.num);
  while (i < 16)
    {
      if (i != train.pos)
	{
	  if (i >= 5 && i <= 10)
	    printf((i == 5 || i == 10) ? "|" : "-");
	  else
	    printf("=");
	}
      else
	printf("#");
      ++i;
    }
  printf("\n");
}

void		*move_train(void *arg)
{
  t_train	*train = (t_train *)arg;
  static int	t_now = 0;

  if (train->pos >= 5 && train->pos <= 10 && !t_now)
    {
      pthread_mutex_lock(&m_goes);
      t_now = train->num;
      train->pos += 1;
      pthread_mutex_unlock(&m_lock);
    }
  if (train->pos < 5 && train->pos > 10 && 0 != t_now)
    {
      pthread_mutex_unlock(&m_goes);
      t_now = 0;
      train->pos += 1;
      pthread_mutex_lock(&m_lock);
    }
  show_train(*train);
  sleep(1);
  //  pthread_exit(0);
}

int		main()
{
  t_train	n1 = {1, 0};
  t_train	n2 = {2, 0};
  t_train	n3 = {3, 0};
  pthread_t	bridge;

  while (n1.pos != 16 && n2.pos != 16 && n3.pos != 16)
    {
      pthread_mutex_lock(&m_lock);
      pthread_create(&bridge, NULL, move_train, &n1);
      pthread_create(&bridge, NULL, move_train, &n2);
      pthread_create(&bridge, NULL, move_train, &n3);
      pthread_join(bridge, NULL);
    }
}
