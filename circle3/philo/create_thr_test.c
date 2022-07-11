#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void    *ft_thread_fun(void *data)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	char *thr_name = (char *)data;
	int i = 0;
	while ( i < 3)
	{
		printf("[%s] pid:%u, tid:%x --- %d\n\n", thr_name, (unsigned int)pid, (unsigned int)tid, i);
		i++;
		sleep(1);
	}
}


int main()
{
    pthread_t   p_thread[2];
    int			thr_id;
	int			status;
	char p1[] = "THR 1";
	char p2[] = "THR 2";
	char pm[] = "THR m";

	thr_id = pthread_create(&p_thread[0], NULL, ft_thread_fun, (void *)p1);
	if (thr_id < 0)
		exit(0);
	
	thr_id = pthread_create(&p_thread[1], NULL, ft_thread_fun, (void *)p2);
	if (thr_id < 0)
		exit(0);

	pthread_join(p_thread[0], (void **)&status);
	pthread_join(p_thread[1], (void **)&status);
	return (0);
}