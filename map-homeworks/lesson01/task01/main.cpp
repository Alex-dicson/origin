#include <iostream>
#include <thread>
using namespace std;

//функция увеличения клиентов
void increaseClients(int &q, const int &max)
{
    while(q < max)
    {
        q++;
        cout << "Increase: " << q << endl;
        this_thread::sleep_for(chrono::seconds(1));


    }
}

//функция уменьшения очереди
void decreaseClient(int &q)
{
    while(q > 0)
    {
        q--;
        cout << "Decrease: " << q << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
}


int main()
{

    int queue = 0;          //создаем очередь клиентов
    const int max_customer = 10;    // максимальное кол-во клиентов
    thread th1(increaseClients, ref(queue), ref(max_customer));
    thread th2(decreaseClient, ref(queue));
    th1.detach();
    th2.join();

    return 0;
}
