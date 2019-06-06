
#include "thread.h"
#include <atomic>


int main(int argc, char *argv[]) {
    ThreadExample example;
    example.init();
    
    for (int i = 0 ; i < 1000; ++i) {
        example.add(i * 100 + 10);
    }

    example.stop();

    std::chrono::seconds sec(1);
    std::this_thread::sleep_for(sec);

    printf("sleep for exit\n");

    return 0;
}