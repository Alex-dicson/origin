#include <iostream>
#include <string>
using namespace std;


template <class T>
class Tables
{
private:
    T** arr;
    int rows;
    int cols;

public:
    Tables(int x, int y) : rows{x}, cols{y}
    {
        arr = new T*[x];
        for (int i = 0; i < x; ++i)
        {
            arr[i] = new T[y]{1};
        }
    };
    Tables(const Tables &tab) : rows{tab.rows}, cols{tab.cols}
    {
        arr = new T*[tab.rows];
        for (int i = 0; i < tab.rows; ++i)
        {
            arr[i] = new int[tab.cols]{};
        }

    }

    ~Tables()
    {
        for (auto i = 0; i < rows; ++i)
        {
            delete [] arr[i];
        }
        delete [] arr;

    }

    void operator=(const Tables &tab)
    {
        for (auto i = 0; i < rows; ++i)
        {
            delete [] arr[i];
        }
        delete [] arr;
        arr = new T*[tab.rows];
        rows = tab.rows;
        cols = tab.cols;
        arr = new T*[tab.rows];
        for (int i = 0; i < tab.rows; ++i)
        {
            arr[i] = new int[tab.cols]{};
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                arr[i][j] = tab[i][j];
            }

        }

    }

    void operator=(const int val)
    {

    }

    T*& operator[](const int &index)
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
    Tables<int> t1(2, 3);
    Tables<double> t2(2, 3);
    Tables<int> t3(t1);
    //table[3][4] = 8;
    t2[0][0] = 2.5;
    t2[0][1] = 3.5;
    t2[0][2] = 2.3;
    t1[0][0] = 2;
    t1[0][1] = 3;
    t1[0][2] = 2;
    cout << t2[0][1] << endl;
    cout << t1[0][1] << endl;
    cout << t2.Size() << endl;
    return 0;
}
