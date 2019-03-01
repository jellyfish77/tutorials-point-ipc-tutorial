#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int mypid, myppid;

    printf("Program to know PID and PPID's information\n");

    //The system call getpid() returns the process ID of the process making the call
    mypid = getpid();

    //The system call getppid() returns the Parent PID of the calling process.
    myppid = getppid();

    printf("My process ID is %d\n", mypid);
    printf("My parent process ID is %d\n", myppid);

    printf("Cross verification of pid's by executing process commands on shell\n");

    // The “C” library function system() executes a shell command
    system("ps -ef");

    return 0;
}
