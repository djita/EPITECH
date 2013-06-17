#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t	m_prod = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t	m_cons = PTHREAD_MUTEX_INITIALIZER;

int		size = 0;

void		*producer(void *arg)
{
  while (42)
    {
      pthread_mutex_lock(&m_prod);
      ++size;
      pthread_mutex_unlock(&m_cons);
    }
  pthread_exit(0);
}

void		*consumer(void *arg)
{
  int		i;
  int		v;

  for (i = 0; i < 100; ++i)
    {
      pthread_mutex_lock(&m_cons);
      v = size;
      pthread_mutex_unlock(&m_prod);
      printf("#%02d : %d\n", i, v);
    }
  pthread_exit(0);
}

int		main()
{
  pthread_t	th_producer;
  pthread_t	th_consumer;

  pthread_mutex_lock(&m_cons);
  pthread_create(&th_producer, NULL, producer, NULL);
  pthread_create(&th_consumer, NULL, consumer, NULL);

  pthread_join(th_consumer, NULL);
  return (0);
}
