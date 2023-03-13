#include <iostream>
#include <thread>
#include <mutex>
#include <vector>


void work(std::mutex& m, int& result)
{
    // std::lock_guard<std::mutex> lock(m);
    m.lock();
    for(int i =0; i< 10000; i++)
    {
        result+=1;
    }
    m.unlock();
}

int main()
{

    int count = 0;
    std::mutex m;
    std::vector<std::thread> vecs;
    for(int i =0; i < 4; i++)
    {
        vecs.push_back(std::thread(work, std::ref(m), std::ref(count)));
    }
    for (int i =0; i < 4; i++)
    {
        vecs[i].join();
    }
    
    std::cout << "총 합 : " << count << std::endl;
}