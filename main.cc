#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

extern void* process_msg(void*);
extern void enqueue_msg(void);
extern vector<long> g_time_queue;


int main(int argc, char **argv) {
	pthread_t tidp;

	if (pthread_create(&tidp, NULL, process_msg, NULL) == -1) {
		printf("create error!\n");
		return 1;
	}

	sleep(1);
	for (int i=0; i < 100; i++) {
		enqueue_msg();
		sleep(1);
	}

	if (pthread_join(tidp, NULL)) {
		printf("thread is not exit...\n");
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
	std::sort(wake_up_time.begin(), wake_up_time.end());
	printf("avg: %f \n", sum/count);

	// string long_wake_up_string;
	int over_40 =0, over_50 = 0, over_60 = 0;
	int total = wake_up_time.size();
	int p80 = int(total * 0.8);
	int p95 = int(total * 0.95);
	for (int i=0; i < wake_up_time.size(); i++) {
		/*
		if (i > 0) {
			long_wake_up_string.append(", ");
		}
		
		long_wake_up_string.append(std::to_string(wake_up_time[i]));
		*/

		if (wake_up_time[i] > 40 && wake_up_time[i] <= 50) {
			over_40++;
		} else if (wake_up_time[i] > 50 && wake_up_time[i] <= 60) {
			over_50++;
		} else if (wake_up_time[i] > 60) {
			over_60++;
		}
	}
	printf("40~50us count: %d, 50~60us count: %d, over 60us: %d \n", over_40, over_50, over_60);
	printf("P80: %dus, P95: %dus, max: %dus\n", wake_up_time[p80], wake_up_time[p95], wake_up_time[total - 1]);

	return 0;
}
