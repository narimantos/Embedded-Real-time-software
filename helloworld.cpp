#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 

using namespace std;

int main()
{


fork();
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}