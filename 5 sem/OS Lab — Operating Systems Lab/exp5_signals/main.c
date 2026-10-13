#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signalhandler(int sig)
{
    if(sig == SIGINT)
    {
        printf("Caught an Interrupt Signal\n");
    }
    if(sig == SIGTERM)
    {
        printf("Caught a Terminate Signal\n");
        exit(0);
    }
    if(sig == SIGHUP){
        printf("Caught a Hangup Signal\n");
    }
    if(sig == SIGUSR1)
    {
        printf("Caught a User Signal\n");
    }
    if(sig == SIGALRM)
    {
        printf("Caught an Alarm Signal\n");
    }
}

int main()
{
    signal(SIGINT, signalhandler);
    signal(SIGTERM, signalhandler);
    signal(SIGHUP, signalhandler);
    signal(SIGALRM, signalhandler);
    signal(SIGUSR1, signalhandler);
    alarm(20);
    printf("Process Id of program running = %d\n", getpid());
    while(1)
    {
        printf("Waiting for signal\n");
        sleep(5);
    }
    return 0;
}
