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
extern int test_sig_jmp(bool jump);

int main(int argc, char **argv) {
	if (argc < 2) {
		cout << "executing params should not be less than 1" << endl;
		return -1;
	}
	char *arg1 = argv[1];
	bool SigJump = atoi(arg1) > 0 ;
	// test_wakeup();
	// test_assert_case1();
	test_sig_jmp(SigJump);
	cout << "finised\n";
	return 0;
}
