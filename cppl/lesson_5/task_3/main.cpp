#include <iostream>
#include <vector>
using namespace std;

class Tables
{
private:
    int m_sum = 0;
    int m_count = 0;

public:
    Tables(){}
    ~Tables(){}
    int get_count()
    {
        return m_count;
    }
    int get_sum()
    {
        return m_sum;
    }

    void operator()(int value)
    {
        if (value % 3  == 0)
        {
            m_sum += value;
            m_count++;
        }
    }
};

int main()
{
    Tables table;
    vector<int> vec{4, 1, 3, 6, 25, 54};
    cout << "[IN]: ";
    for (int i: vec)
    {
git        cout << i << " ";
        table(i);
    }
    cout << endl;
    cout << "[OUT]: get_sum() = " << table.get_sum() << endl;
    cout << "[OUT]: get_count() = " << table.get_count() << endl;

    return 0;
}
