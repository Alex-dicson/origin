#include <iostream>
#include <string>
#include <utility>
using namespace std;

//template<class T>
class big_integer
{
private:
    string val;
public:
    big_integer(string number) : val{number}{}

    big_integer(const big_integer& other): big_integer(other.val){}

    big_integer(big_integer&& other) noexcept : val(exchange(other.val, nullptr)){}

    const big_integer operator=(big_integer& other)
    {
        if (this != &other)
        {
            return big_integer(other);
        }
        else{throw("error");}

    }

    const big_integer& operator=(big_integer&& other) noexcept
    {
        swap(val, other.val);
        return *this;
    }

    big_integer operator+(const big_integer& other)
    {

        return big_integer(sum_number(val,other.val));
    }

    big_integer operator*(int number)
    {
        string sum_val, other_sum = "0";
        string str_number = to_string(number);
        int shift_number = 1, it_arr = 0;
        for (int i = str_number.size() - 1; i > -1; --i )
        {
            int sum_tmp = 0;
            sum_val = "";
            for (int j = val.size() - 1; j > -1; --j)
            {
                int tmp = sum_tmp + ((static_cast<int>(val[j]) - 48) * (static_cast<int>(str_number[i])-48));

                if ((tmp > 9) && (j != 0))
                {
                    sum_tmp = tmp / 10;
                    int num_tmp = tmp % 10;
                    sum_val = to_string(num_tmp) + sum_val;
                }
                else {sum_val = to_string(tmp) + sum_val; sum_tmp = 0;}
            }
            if (shift_number > 1)
            {
                int s =std::stoi(sum_val) * shift_number;
                other_sum = sum_number(other_sum,to_string(s));
            } else {other_sum = sum_val;}
            shift_number= shift_number * 10;


        }

        return big_integer(other_sum);
    }

    string sum_number(const string lhs, const string rhs)
    {
        string sum;
        int sum_tmp = 0;
        for (int i = lhs.size() - 1, j = rhs.size() - 1 ; i > -1 || j > -1; --i, --j)
        {
            int tmp;
            if (lhs[i] == 0){tmp =sum_tmp + static_cast<int>(rhs[j]) - 48;}
            else if(rhs[j] == 0){tmp = sum_tmp + static_cast<int>(lhs[i]) - 48;}
            else{tmp =sum_tmp + (static_cast<int>(lhs[i]) - 48) + (static_cast<int>(rhs[j]) - 48);}

            if ((tmp > 9) && ((i != 0) || (j != 0)))
            {
                sum_tmp = 1;
                int num_tmp = tmp % 10;
                sum = to_string(num_tmp) + sum;
            }
            else {sum = to_string(tmp) + sum; sum_tmp = 0;}
        }

        return sum;

    }


    string get_val() const
    {
        return val;
    }
};

std::ostream& operator << (std::ostream &os, const big_integer &obj)
{
    return os << obj.get_val();
}

int main()
{
    auto number1 = big_integer("11457589");
    auto number2 = big_integer("78524");
    auto number3 = big_integer("1111");
    auto result = number1 + number2 + number3;
    auto result2 = number1 * 11;
    cout << number1 << endl;
    cout << number2 << endl;
    cout << result << endl;
    cout << result2;
    return 0;
}
