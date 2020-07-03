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

    // TOtale duur 121469 microseconds 
    
    vector<int> v1(10000000, 1);
    vector<int> v2(5000000, 2);
    vector<int> v3(5000000, 4);
    auto start = high_resolution_clock::now(); // start clock

    auto s1 = async(launch::async, &som, ref(v1));
    auto s2 = async(launch::deferred, &som, ref(v2));
    auto s3 = async(launch::async, &som, ref(v3));
    cout << "\n Totaal = " << s1.get() + s2.get() + s3.get() << "\n" << endl;
    auto stop = high_resolution_clock::now(); // stop clock
    auto duration = duration_cast<microseconds>(stop - start); // calculate duration
  
    cout << "Time taken by functions: " << duration.count() << " microseconds" << endl; // output duration


    return 0;
}