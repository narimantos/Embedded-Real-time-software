#include <unistd.h>
#include <iostream>
using namespace std;


/** 
 * VRAAG: 
 * 
 Stel dit programma wordt gestart met procesnummer 650;
 Wat wordt er afgedrukt?.
 * 
 * **/

int main()
{
    int p, p1;
    int b = 0;
    
    cout << "procesnummer : " << getpid() << endl;

    b++;
    p = fork();
    cout << "ik ben " << getpid() << " en p heeft de waarde " << p << endl;
    if (p == 0)
    {
        b++;
        p1 = fork();
        if (p1 == 0)
        {
            b += 3;
        }
        else
        {
            b += 7;
        }
    }
    cout << "ik ben " << getpid() << " en b heeft de waarde " << b << endl;
    return 0;
}