#include <iostream>
#include <thread>

int c = -1;
int buf = -2;
int n = 5;
int p = -3;
void producer()
{
    int a[5] = {10,20,30,40,50};
    bool run = true;

    while(run)
    {
        while(p < 5)
        {
            std::cout << "ID: " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            while(p != c)
            {
                std::cout << "spinning" << std::endl;
            }
            buf = a[p];
            std::cout << a[p] << " deposited in buffer" << std::endl;
            p++;
        }
        std::cout << "Production finished" << std::endl;
        run = false;
    }
}

void consumer()
{
    int b[5];
    bool run = true;
    while(run)
    {
        while(c < 5)
        {
            std::cout << "ID: " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            while(p <= c)
            {
                std::cout << "spinning" << std::endl;
            }
            b[c] = buf;
            std::cout << buf << " deposited in b[]" << std::endl;
            c++;
        }
        std::cout << "Consumption finished" << std::endl;
        run = false;
    }
}

int main()
{
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);
    producerThread.join();
    consumerThread.join();
    std::cin.get();
    return 0;
}