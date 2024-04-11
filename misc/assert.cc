#include <string.h>
#include <iostream>
#include <cassert>
using std::cout;
using std::endl;
int test_assert_case1() {
    // cout << "test_assert_case1\n";
    assert(0);
    char *p = NULL;
    *p = 's';
    return 0;
}