#include <future>
#include <vector>
#include <iostream>

using namespace std::chrono;
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
    // totale duur 169354 microseconds
    vector<int> v1(10000000, 1);
    vector<int> v2(5000000, 2);
    vector<int> v3(5000000, 4);
    auto start = high_resolution_clock::now(); // start clock
    cout << "som=" << som(v1) + som(v2) + som(v3) << endl;
    auto stop = high_resolution_clock::now();                                           // stop clock
    auto duration = duration_cast<microseconds>(stop - start);                          // calculate duration
    cout << "Time taken by functions: " << duration.count() << " microseconds" << endl; // output duration
    return 0;
}