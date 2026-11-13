/**
* File: signal_alarm.c
* Modified by: James F. Connelly
*
* Brief summary of program:
* This program schedules an alarm for five seconds.
* When SIGALRM is received, the signal handler prints
* a message indicating the alarm was received.
*/ 


#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void handle_alarm(int sig) {
    (void)sig;

    printf("Alarm signal recieved! The alarm expired.\n");

}

int main(void){
    signal(SIGALRM, handle_alarm);

    printf("Alarm scheduled for 5 seconds...\n");

    alarm(5);

    while (1)
    {
        pause();
    }

    return 0;
}