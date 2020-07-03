#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>

using namespace std;

std::deque<int> q;
std::mutex mu;
std::condition_variable cond;


void producer()
{
  int count = 11;

    while (count > 0)
    {
        std::unique_lock<mutex> locker(mu);
        q.push_front(count);
        locker.unlock();
        cond.notify_all(); // Notify
        std::this_thread::sleep_for(chrono::seconds(1));
        printf("Produced Number:  %d \n", count);
        count--;
    }

}

void consumer()
{
    int data = 0;
  
    while (data != 1)
    {
        std::unique_lock<mutex> locker(mu);
        cond.wait(locker, [](){ return !q.empty();});
        data = q.back();
        q.pop_back();
        locker.unlock();
        printf("Consumed Number:  %d \n", data);
    }
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
   // std::thread t3(consumer);
    t1.join();
    t2.join();
  //  t3.join();
    return 0; 
}
