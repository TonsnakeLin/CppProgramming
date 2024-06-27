#include<setjmp.h>
#include<unistd.h>
#include<iostream>
using std::cout;
using std::endl;

sigjmp_buf jmp_env;

static void jump_out() {
    cout << "jump_out" << endl;
    siglongjmp(jmp_env, 1);
}

int test_sig_jmp(bool jump) {
    cout << "test_sig_jump start ..." << endl;
    if (sigsetjmp(jmp_env, 1)) {
        cout << "trigger jump ..." << endl;
        return 1;
    }

    sleep(1);

    if (jump) {
        jump_out();
    }

    cout << "test_sig_jump finished ..." << endl;

    return 0;
}