//
// Created by V5 on 2022/6/3.
//

#include <chrono>
#include <iostream>
#include <mutex>
#include <stdlib.h>
#include <thread>

struct DataA
{
    int a = 0;
};
struct DataB
{
    double data[5] = {0};
};

DataA data_a;
DataB data_b;
double sum_b_all = 0;

// lock mechanism for data synchronization
std::mutex data_a_mtx, data_b_mtx, data_sum_mtx;

void thread1()
{
    while (1)
    {
        data_a_mtx.lock();
        data_a.a = rand() % 100 + 1;
        // 当前线程休眠1毫秒
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::cout << " Thread a produce data: " << data_a.a << std::endl;
        data_a_mtx.unlock();
    }
}

void thread2()
{
    while (1)
    {
        data_b_mtx.lock();
        for (int i = 0; i < 5; i++)
        {
            data_b.data[i] = rand() / double(RAND_MAX);
        }
        // 当前线程休眠1毫秒
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::cout << " Thread b produce data: ";
        for (int i = 0; i < 5; i++)
        {
            std::cout << data_b.data[i];
        }
        std::cout << std::endl;
        data_b_mtx.unlock();
    }
}

void thread3()
{
    while (1)
    {
        data_a_mtx.lock();
        data_b_mtx.lock();
        data_sum_mtx.lock();

        double sum_b = 0;
        for (int i = 0; i < 5; i++)
        {
            sum_b += data_b.data[i];
        }

        if (data_a.a % 2 == 0)
        {
            sum_b *= -1;
        }
        sum_b_all += sum_b;
        // 当前线程休眠1毫秒
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::cout << " Thread c calculate sum done " << sum_b << std::endl;

        data_sum_mtx.unlock();
        data_b_mtx.unlock();
        data_a_mtx.unlock();
    }
}

void thread4()
{
    while (1)
    {
        // 当前线程休眠1000毫秒
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << " Thread d print sum: " << sum_b_all << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread t3(thread3);
    std::thread t4(thread4);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
