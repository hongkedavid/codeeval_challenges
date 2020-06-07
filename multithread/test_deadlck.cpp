#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex io_mutex;

void thread_func()
{
    std::unique_lock<std::mutex> lk(io_mutex);
    std::cout<<"Hello from thread_func"<<std::endl;
}

int main()
{
    std::thread t(thread_func);
    std::unique_lock<std::mutex> lk(io_mutex);
    std::cout<<"Hello from main thread"<<std::endl;
    t.join();
    return 0;
}
