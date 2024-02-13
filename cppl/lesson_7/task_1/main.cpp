#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void printVec(const vector<T> &arr)
{
    for (const auto &it: arr)
    {
        cout << it << " ";
    }
}

template<class T>
void vUnique(vector<T> &arr)
{
    sort(arr.begin(), arr.end());
    auto un_vec = unique(arr.begin(), arr.end());
    arr.erase(un_vec, arr.end());
}


int main()
{
    vector<int> vec{1, 1, 2, 5, 6, 1, 2, 4,};
    cout << "[IN]: ";
    printVec(vec);
    cout << endl;
    cout << "[OUT]: ";
    vUnique(vec);
    printVec(vec);
    return 0;
}
