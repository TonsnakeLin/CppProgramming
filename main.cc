#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;
using std::vector;
using std::string;

extern void test_wakeup();
extern int test_assert_case1();

int main(int argc, char **argv) {
	// test_wakeup();
	test_assert_case1();
	/*
	while(1) {
		cout << "sleeping" << endl;
		sleep(10);
	}
	*/
	cout << "finised\n";
	return 0;
}
