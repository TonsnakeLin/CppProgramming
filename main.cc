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

int main(int argc, char **argv) {
	test_wakeup();
	return 0;
}
