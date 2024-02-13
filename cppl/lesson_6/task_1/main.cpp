#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
    string s_in = "Hello world!!";
    cout << "[IN]: " << s_in << endl;

    //создадим контейнер без дубликатов, за ключ возьмем буквы, т.к. он удалит дубликаты которые создадутся в процессе цикла
    map<char, int> s_map;

    // переберем символы и запишем в map
    for (auto it: s_in)
    {
        typedef pair<int, char> s_pair;
        int count = 0;
        for (auto itr: s_in)
        {
            if (it == itr)
            {
                count++;
            }

        }
        s_map.insert(s_pair(it, count));
    }

    //создадим вектор, что бы копировать туда контейнер map
    typedef pair<char, int> pair_vector;
    vector<pair_vector> vec;

    //копируем в вектор
    for (const auto &it: s_map)
    {
        vec.push_back(pair_vector(it.first,it.second));
    }

    //сортировка вектора, но не по ключу, а по значению ключа
    sort(vec.begin(),vec.end(),[](const pair_vector &l, const pair_vector &r)
                                                {
                                                    if (l.second != r.second)
                                                    {
                                                        return l.second > r.second;
                                                    }
                                                    return l.first > r.first;
                                                });

    //выводим результат
    cout << "[OUT]: " << endl;
    for (auto const &pair_vector: vec)
    {
        cout << pair_vector.first << " : " << pair_vector.second << endl;
    }
    return 0;
}
