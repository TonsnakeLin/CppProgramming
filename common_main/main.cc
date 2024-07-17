#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>
#include <string.h>
#include <locale.h>

using std::cout;
using std::endl;
using std::vector;
using std::string;

extern void test_wakeup();
extern int test_assert_case1();
extern int test_sig_jmp(bool jump);
extern void print_macro();

void test_strxfrm() {
	cout << "test_strxfrm" << endl;
	char		buf[32];
	const int	canary = 0x7F;
	buf[7] = canary;
	(void) strxfrm(buf, "ab", 7);
	cout << "buf:" << buf << endl;
}

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
	test_strxfrm();
	print_macro();
	cout << "finised\n";
	return 0;
}
