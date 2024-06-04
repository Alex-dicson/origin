#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <random>
#include <Windows.h>
#pragma execution_character_set("utf-8")

using namespace std;

//созадим класс для расчетов
class calcVector
{
    vector<int> V1, V2, V3;                                                     // вектора для массивов
    int vSize1 = 1000, vSize2 = 10000, vSize3= 100000, vSize4 = 1000000;        // виды количества массивов
    int arrSize[4] = {1000,10000,100000,1000000};
    int num_th;                                                                 // количество потоков



public:
    calcVector(int num);


private:
    void fillVector(int size);
    void calcVec(int begin, int end);


};

void calcVector::fillVector(int size)
{
    V1.resize(size);
    generate(V1.begin(),V1.end(), [](){return rand() % 100000;});
    V2.resize(size);
    generate(V2.begin(),V2.end(), [](){return rand() % 100000;});
    V3.resize(size);

}

void calcVector::calcVec(int begin, int end)
{
    for (int i = begin; i <= end; ++i)
    {
        V3[i] = V1[i] + V2[i];
    }
}

calcVector::calcVector(int num)
{
    num_th = num;
    if(num_th == 1)
    {
        for (int i = 0; i < 4; ++i)
        {
            calcVector::fillVector(arrSize[i]);
            auto start = std::chrono::high_resolution_clock::now();
            thread t1(&calcVector::calcVec, *this, 0, arrSize[i]);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double>time = end - start;
            cout << "\t" << time.count();
        }
        cout << endl;

    }
    else if(num_th == 2)
    {
        for (int i = 0; i < 4; ++i)
        {
            calcVector::fillVector(arrSize[i]);
            auto start = std::chrono::high_resolution_clock::now();
            thread t1(&calcVector::calcVec, *this, 0, arrSize[i] / num_th - 1);
            thread t2(&calcVector::calcVec, *this, arrSize[i] / num_th, arrSize[i]);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double>time = end - start;
            cout << "\t" << time.count();
        }
        cout << endl;
    }
    else if(num_th == 4)
    {
        for (int i = 0; i < 4; ++i)
        {
            calcVector::fillVector(arrSize[i]);
            auto start = std::chrono::high_resolution_clock::now();
            thread t1(&calcVector::calcVec, *this, 0, arrSize[i] / 4 - 1);
            thread t2(&calcVector::calcVec, *this, arrSize[i] / 4, (arrSize[i] / 2) -1);
            thread t3(&calcVector::calcVec, *this, arrSize[i] / 2, (arrSize[i] / 4) - 1);
            thread t4(&calcVector::calcVec, *this, (arrSize[i] / 2) + (arrSize[i] / 4), arrSize[i]-1);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double>time = end - start;
            cout << "\t" << time.count();
        }
        cout << endl;
    }
    else if(num_th == 8)
    {
        for (int i = 0; i < 4; ++i)
        {
            calcVector::fillVector(arrSize[i]);
            auto start = std::chrono::high_resolution_clock::now();
            thread t1(&calcVector::calcVec, *this, 0, arrSize[i] / 8 - 1);
            thread t2(&calcVector::calcVec, *this, arrSize[i] / 8, (arrSize[i]/ 4)-1);
            thread t3(&calcVector::calcVec, *this, arrSize[i] / 4, ((arrSize[i] / 8)+(arrSize[i] / 4)) -1);
            thread t4(&calcVector::calcVec, *this, ((arrSize[i] / 8)+(arrSize[i]/4)), (arrSize[i] / 2) -1);
            thread t5(&calcVector::calcVec, *this, arrSize[i] / 2, ((arrSize[i] / 2)+(arrSize[i] / 8)) -1);
            thread t6(&calcVector::calcVec, *this, ((arrSize[i] / 2)+(arrSize[i] / 8)), ((arrSize[i] / 2)+(arrSize[i] / 4)) -1);
            thread t7(&calcVector::calcVec, *this, ((arrSize[i] / 2)+(arrSize[i] / 4)), ((arrSize[i] / 2)+(arrSize[i] / 4) + (arrSize[i] / 8))-1);
            thread t8(&calcVector::calcVec, *this, ((arrSize[i] / 2)+(arrSize[i] / 4) + (arrSize[i] / 8)), arrSize[i]-1);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double>time = end - start;
            cout << "\t" << time.count();
        }
        cout << endl;
    }
    else if(num_th == 16)
    {
        for (int i = 0; i < 4; ++i)
        {
            calcVector::fillVector(arrSize[i]);
            auto start = std::chrono::high_resolution_clock::now();
            thread t1(&calcVector::calcVec, *this, 0, arrSize[i] / 16 - 1);
            thread t2(&calcVector::calcVec, *this, arrSize[i] / 16, (arrSize[i] / 8)-1);
            thread t3(&calcVector::calcVec, *this, arrSize[i] / 8, ((arrSize[i] / 8)+(arrSize[i] / 16)) -1);
            thread t4(&calcVector::calcVec, *this, ((arrSize[i] / 8)+(arrSize[i] / 16)), (arrSize[i] / 4) -1);
            thread t5(&calcVector::calcVec, *this, arrSize[i] / 4, ((arrSize[i] / 4)+(arrSize[i] / 16)) -1);
            thread t6(&calcVector::calcVec, *this, ((arrSize[i] / 4)+(arrSize[i] / 16)), ((arrSize[i] / 4)+(arrSize[i] / 8)) -1);
            thread t7(&calcVector::calcVec, *this, ((arrSize[i] / 4)+(arrSize[i] / 8)), ((arrSize[i] / 4)+(arrSize[i] / 8) + (arrSize[i] + 16))-1);
            thread t8(&calcVector::calcVec, *this, ((arrSize[i] / 4)+(arrSize[i] / 8) + (arrSize[i] + 16)), (arrSize[i] / 2)-1);
            thread t9(&calcVector::calcVec, *this, arrSize[i] / 2, ((arrSize[i] / 2) +(arrSize[i] / 16))-1);
            thread t10(&calcVector::calcVec, *this, ((arrSize[i] / 2) +(arrSize[i] / 16)), ((arrSize[i] / 2) +(arrSize[i] / 8))-1);
            thread t11(&calcVector::calcVec, *this, ((arrSize[i] / 2) +(arrSize[i] / 8)), ((arrSize[i] / 2)+(arrSize[i] / 8)+ (arrSize[i] + 16)) -1);
            thread t12(&calcVector::calcVec, *this, ((arrSize[i] / 2)+(arrSize[i] / 8)+ (arrSize[i] + 16)), ((arrSize[i] / 2) +(arrSize[i] / 4)) -1);
            thread t13(&calcVector::calcVec, *this, ((arrSize[i] / 2) +(arrSize[i] / 4)), ((arrSize[i] / 2)+(arrSize[i] / 4)+ (arrSize[i] + 16)) -1);
            thread t14(&calcVector::calcVec, *this, ((arrSize[i] / 2)+(arrSize[i] / 4)+ (arrSize[i] + 16)), ((arrSize[i] / 2)+(arrSize[i] / 4)+ (arrSize[i] + 8)) -1);
            thread t15(&calcVector::calcVec, *this, ((arrSize[i] / 2)+(arrSize[i] / 4)+ (arrSize[i] + 8)), ((arrSize[i] / 2)+(arrSize[i] / 4) + (arrSize[i] / 8) + (arrSize[i] / 16))-1);
            thread t16(&calcVector::calcVec, *this, ((arrSize[i] / 2)+(arrSize[i] / 4) + (arrSize[i] / 8) + (arrSize[i] / 16)), arrSize[i] -1);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double>time = end - start;
            cout << "\t" << time.count();
        }
        cout << endl;
    }
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // выведем количество аппаратных ядер
    cout << "Количество аппаратных ядер - " << thread::hardware_concurrency() << endl;
    cout << "\n\t\t1000\t\t10000\t\t100000\t\t1000000" << endl;




    return 0;
}
