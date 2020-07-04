#include <vector>
#include <thread>
#include <algorithm>
#include <iostream>
#include <unistd.h>
using namespace std;
int wed1 = 0;
int wed2 = 0;
vector<int> v;


/**
 * Vragen
    A: Wat zijn de/ is het nadeel van de onderstaande oplossing.
    B: Los het race probleem op door gebruik te maken van een C++11 mutex. 
**/

void uitv()
{
    for (int i = 0; i < 1000000; i++)
    {
        wed1 = 1;
        while (wed2 == 1)
        {
        }

        v.push_back(i);
        wed1 = 0;
    }
}
void uitv2()
{
    for (int i = 0; i < 1000000; i++)
    {
        wed2 = 1;
        while (wed1 == 1)
        {
        }

        v.push_back(i);
        wed2 = 0;
    }
}
int main()
{
    thread t1(uitv);
    thread t2(uitv2);
    t1.join();
    t2.join();
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i += 2)
    {
        if (v[i] != v[i + 1])
            cout << "foutje";
    }
    return 0;
}