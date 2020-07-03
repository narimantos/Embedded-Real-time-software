#include <future>
#include <vector>
#include <iostream>
#include <thread>
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
    // Time taken by functions: 85724 microseconds
    int x, y;
    vector<int> v1(10000000, 1);
    
    auto start = high_resolution_clock::now(); // start clock

    thread t1{[&]() { x = som(v1); }};
    thread t2{[&]() { y = som(v1); }};
    t1.join();
    t2.join();
    future<int> s1 = async(&som, ref(v1));
    future<int> s2 = async(&som, ref(v1));
    cout << "som=" << x + y << endl;

    auto stop = high_resolution_clock::now();                  // stop clock
    auto duration = duration_cast<microseconds>(stop - start); // calculate duration
    cout << "Time taken by functions: " << duration.count() << " microseconds" << endl; // output duration

    return 0;
}