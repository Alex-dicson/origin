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

    big_integer& operator=(const big_integer& other)
    {
        return *this = big_integer(other);
    }

    big_integer& operator=(big_integer&& other) noexcept
    {
        swap(val, other.val);
        return *this;
    }

    string operator+(big_integer& other)
    {
        return to_string(stoi(val) + stoi(other.val));
    }

    string operator*(int number)
    {

        return val = to_string(stoi(val) * number);;
    }
};

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    auto result2 = number1 * 3;
    cout << result << endl;
    cout << result2;
    return 0;
}
