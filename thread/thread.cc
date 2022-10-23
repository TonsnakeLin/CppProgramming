#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <vector>
using std::vector;

bool workq;
vector<long> g_time_queue;
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

char* get_current_time() {
	time_t t;
	time(&t);
	return ctime(&t);
}

long get_current_time2() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}


void* process_msg(void*)
{
	long t2 = 0;	
    for (int i=0; i < 100; i++) {
        pthread_mutex_lock(&qlock);
        workq = true;
	
        pthread_cond_wait(&qready, &qlock);
	
		printf("process_msg timestamp: %ld \n", t2=get_current_time2());
		g_time_queue.push_back(t2);

        pthread_mutex_unlock(&qlock);
    }
}


void enqueue_msg(void)
{
	long t1 = 0;
    pthread_mutex_lock(&qlock);
	workq = false;
    pthread_cond_signal(&qready);
	t1 = get_current_time2();	
	g_time_queue.push_back(t1);	
	pthread_mutex_unlock(&qlock);
	printf("enqueue_msg timestamp: %ld \n", t1);
}



