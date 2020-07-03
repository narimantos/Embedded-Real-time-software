#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int g = 1;
int main()
{
    pid_t pid;
    int a = 1;
    printf("Een goede dag %d %d\n", a, g);
    a++;
    g++;
    pid = fork(); // FORK() is alleen in een LINUX OS te gebruiken
    printf("Welkom %d %d\n", a, g);
    a++;
    g++;
    pid = fork();                            // er zijn al 2 processen, dus die worden verdubbeld.
    printf("bij IoT deel II %d %d\n", a, g); // krijgen dit 4 x te zien.  (2 x 2)
    return 0;                                // SOMS PRINT DE PROCES NOG NA DE RETURN omdat de slave de return 0 geeft maar de master moet nog eindigen
}