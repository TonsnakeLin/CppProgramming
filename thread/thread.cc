#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <vector>

#include <iostream>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;
using std::vector;
using std::string;

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
		t2=get_current_time2();
		// printf("process_msg timestamp: %ld \n", t2);
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
	// printf("enqueue_msg timestamp: %ld \n", t1);
}

int test_unit() {
	pthread_t tidp;

	if (pthread_create(&tidp, NULL, process_msg, NULL) == -1) {
		printf("create error!\n");
		return 1;
	}

	sleep(1);
	for (int i=0; i < 100; i++) {
		enqueue_msg();
		// sleep(1);
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	if (pthread_join(tidp, NULL)) {
		printf("thread does not exist ...\n");
	}

	double sum = 0;
	int count = g_time_queue.size();
	vector<int> wake_up_time;
	for(int i = 0; i < g_time_queue.size(); i+=2) {
		long t1 = g_time_queue[i];
		long t2 = g_time_queue[i+1];
		long delta = 0;
	    if (t2 > t1) {
			delta = t2 - t1;			
	    } else {
			delta = t1 - t2;	    	
	    }
		wake_up_time.push_back(delta);
		sum += delta;
	}
	// printf("count:%d\n", count);
	std::sort(wake_up_time.begin(), wake_up_time.end());
	// printf("avg: %f \n", 2*sum/count);

	// string long_wake_up_string;
	int over_40 =0, over_50 = 0, over_60 = 0;
	int total = wake_up_time.size();
	int p50 = int(total * 0.5);
	int p80 = int(total * 0.8);
	int p99 = int(total * 0.99);

	printf("avg: %f median: %dus, P99: %dus, max: %dus\n", 2*sum/count, wake_up_time[p50], wake_up_time[p99], wake_up_time[total - 1]);
    return 0;
}

void test_wakeup() {
	for (int i=0; i<10; i++) {
		test_unit();
	}
}



