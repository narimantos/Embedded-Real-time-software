#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 

int g=1;
int main( ) {
pid_t pid;
int a=1;
printf("Een goede dag %d %d\n",a,g);
a++; g++;
pid = fork();
printf("Welkom %d %d\n",a,g);
a++; g++;
pid = fork();
printf("bij IoT deel 2 %d %d\n",a,g);
return 0;
}