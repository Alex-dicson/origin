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
    if(num_th = 1)
    {
        for (int i = 0; i < 4; ++i)
        {
            calcVector::fillVector(arrSize[i]);
            auto start = std::chrono::high_resolution_clock::now();
            thread t1(&calcVector::calcVec(), 0, arrSize[i]);
        }

    }
    else if(num_th = 2)
    {

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
