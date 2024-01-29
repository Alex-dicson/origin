#include <iostream>
using namespace std;

class smart_array
{
private:
    int* arr_;
    size_t size_;
    int last_index;
public:
    smart_array(size_t size) : arr_(new int[size]), size_(size)
    {
        last_index = 0;
    }

    ~smart_array()
    {
        delete[] arr_;
    }

    void add_element(int val)
    {
        if(size_ > last_index)
        {
            arr_[last_index] = val;
            last_index++;
        }
        else
        {
            throw exception("Достигнут конец массива, добавление не возможно");
        }
        
    }
    int get_element(int index)
    {
        if(size_ >= index)
        {
            return arr_[index];
        }
        else
        {
            throw exception("Запрашиваемый идндекс за пределами массива");
        }
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    try
    {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}


