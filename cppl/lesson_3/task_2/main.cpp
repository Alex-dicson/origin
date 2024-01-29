#include <iostream>
using namespace std;

class smart_array
{
private:
    int* arr_;
    size_t size_;
    size_t last_index;
public:
    smart_array(size_t size) : arr_(new int[size]), size_(size)
    {
        last_index = 0;
    }

    smart_array(const smart_array& rhs)
    {
        delete[] arr_;
        last_index = rhs.last_index;
        size_ = rhs.size_;
        if(rhs.arr_)
        {
            arr_ = new int[size_];
            for(size_t i = 0; i < size_; i++)
            {
                arr_[i] = rhs.arr_[i];
            }
        }
        else
        {
            arr_ = nullptr;
        }
    }

    ~smart_array()
    {
        delete[] arr_;
        arr_ = nullptr;
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
            throw exception("ƒостигнут конец массива, добавление не возможно");
        }

    }
    int get_element(size_t index)
    {
        if(size_ >= index)
        {
            return arr_[index];
        }
        else
        {
            throw exception("«апрашиваемый идндекс за пределами массива");
        }
    }

    smart_array& operator=(const smart_array& rhs)
    {
        if(this != &rhs)
        {
            delete[] arr_;
            last_index = rhs.last_index;
            size_ = rhs.size_;
            arr_ = new int[size_];
            for(size_t i = 0; i < size_; i++)
            {
                arr_[i] = rhs.arr_[i];
            }
        }
        return *this;
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;
}


