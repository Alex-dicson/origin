#include <iostream>
#include <string>
using namespace std;


template <class T>
class Tables
{
private:
    T** arr;
    T rows;
    T cols;

public:
    Tables(T x, T y) : rows{x}, cols{y}
    {
        arr = new int*[x];
        for (int i = 0; i < x; ++i)
        {
            arr[i] = new int[y];
        }
    };
    ~Tables()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete [] arr[i];
        }
        delete [] arr;

    }

    int*& operator[](const int &index)
    {
        return arr[index];
    }
    string Size() const
    {
        return to_string(rows) + ' ' + to_string(cols);
    }

};

int main()
{
    Tables table(5,5);
    table[3][4] = 8;
    cout << table[3][4] << endl;
    cout << table.Size() << endl;
    return 0;
}
