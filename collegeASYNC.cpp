#include <future>
#include <vector>
#include <iostream>

using namespace std;

int som(const vector<int> &v)
{
    int s = 0;
    for (auto e : v)
        s += e;
    return s;
}

int main()
{
    vector<int> v1(10000000, 1);
    vector<int> v2(5000000, 2);
    vector<int> v3(5000000, 4);
    auto s1 = async(&som, ref(v1));
    auto s2 = async(&som, ref(v2));
    auto s3 = async(&som, ref(v3));
    cout << "\n Totaal = " << s1.get() + s2.get() + s3.get() << "\n" << endl;
    return 0;
}