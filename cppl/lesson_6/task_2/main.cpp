#include <iostream>
#include <set>

using namespace std;

int main()
{
    size_t arr_size;
    cout << "[IN]: " << endl;
    cin >> arr_size;
    set<int, greater<int>> s_set;
    for (int i = 0; i < arr_size; ++i)
    {
        int val;
        cin >> val;
        s_set.insert(val);
    }
    cout << "[OUT]:" << endl;
    for (const auto &its: s_set)
    {
        cout << its << endl;
    }

    return 0;
}
