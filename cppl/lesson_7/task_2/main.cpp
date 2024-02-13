#include <iostream>
#include <vector>
#include <set>
#include <list>
using namespace std;

template<class T>
void print_container(const T &container)
{
    for (const auto &it : container)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    set<double> test_set = { 1.5, 2.3, 3.1, 4.7 };
    print_container(test_set);
    list<string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);
    vector<string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);
    return 0;
}
