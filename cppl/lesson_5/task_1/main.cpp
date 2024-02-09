#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
T squaring(T val)
{
    return val * val;
}

template <>
string squaring (string val)
{
    return val;
}

template<class T>
vector<T> squaring(const vector<T>& vec)
{
    vector<T> temp = vec;
    for (auto i = 0; i < vec.size(); i++)
    {
        temp[i] *= temp[i];
    }
    return temp;
}

void print_vector(vector<int> vec)
{
    for (auto i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ", ";
    }
}

int main()
{
    int a = 5;
    cout << "[IN]: " << a << endl;
    cout << "[OUT]: " << squaring(a) << endl;
    cout << "[IN]: 8" << endl;
    cout << "[OUT]: " << squaring<int>(8) << endl;

    vector<int> vec{-1, 4, 8};
    cout << "[IN]: ";
    print_vector(vec);
    cout << endl;
    cout << "[OUT]: ";
    vector<int> vec2 = squaring(vec);
    print_vector(vec2);
    return 0;
}
