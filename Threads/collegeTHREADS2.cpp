#include <thread>
#include <string>
#include <iostream>
using namespace std;
class Message
{
public:
    Message(string s) : s1(s) {}
    void operator()() const
    {
        cout << s1 << endl;
    }

private:
    string s1;
};
int main()
{
    Message m1("hello");
    Message m2("world");
    thread t1(m1);
    thread t2(m2);
    t1.join();
    t2.join();
    return 0;
}