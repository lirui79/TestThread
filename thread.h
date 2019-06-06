
#include <sys/prctl.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <list>

class ThreadExample {
public:
   ThreadExample();

   virtual ~ThreadExample();

   virtual int init();

   virtual int stop();

   virtual int add(int idx);

protected:
   static  int ThreadRun(void *arg);
   virtual int ThreadLoop();

   virtual int exit();

protected:
   std::thread            *mThread;
   int                     mExit;
   std::mutex              mLock;
   std::condition_variable mWait;

   std::list<int>          mLID;
};