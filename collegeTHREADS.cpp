#include <thread>
#include <string>
#include <iostream>
using namespace std;
void print_message(string s){
cout << s<<endl;
}
int main(){
thread t1(print_message,"hello");
thread t2(print_message,"word");
t1.join();
t2.join();
return 0;
}