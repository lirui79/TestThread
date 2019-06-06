
#include "thread.h"


ThreadExample::ThreadExample() : mThread(NULL),mExit(0)  {
}

ThreadExample::~ThreadExample() {
}

int ThreadExample::init() {
    mThread = new std::thread(ThreadExample::ThreadRun, this);
    return 0;
}

int ThreadExample::add(int idx) {
    std::lock_guard<std::mutex> locker(mLock);
    mLID.push_back(idx);
    mWait.notify_one();
    return 0;
}

int ThreadExample::stop() {
    std::lock_guard<std::mutex> locker(mLock);
    mExit = 1;
    mWait.notify_one();
    return mExit;
}

int ThreadExample::exit() {
    std::lock_guard<std::mutex> locker(mLock);
    return mExit;
}

int ThreadExample::ThreadRun(void *arg) {
    return ((ThreadExample*)arg)->ThreadLoop();
}

int ThreadExample::ThreadLoop() {
    while(true) {
        if (exit()) {
            break;
        }

        std::list<int> ids ;
        {
            std::unique_lock<std::mutex> lock(mLock);
            if (mLID.empty()) {
                mWait.wait(lock);
                continue;
            }
            ids = mLID;
            mLID.clear();
        }

        for (std::list<int>::iterator it = ids.begin() ; it != ids.end() ; ++it) {
            printf("%d  \n", *it);
        }

    }

    printf("exit\n");
    return 0;
}
