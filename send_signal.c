/**
* File: send_signal.c
* Modified by: James F. Connelly
*
*
* Description:
* This program generates a random integer and sends it
* to another process using sigqueue()
* 
* 
*/  



#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>


int main(int argc, char *argv[]) {
    
    if (argc != 2){
        printf("Usage: %s PID\n", argv[0]);
        return 1;
    }

    pid_t receiver_pid = (pid_t)atoi(argv[1]);

    if (receiver_pid <= 0){
        printf("Invalid process ID.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    int random_number = (rand() % 1000) + 1;

    union sigval value;
    value.sival_int = random_number;

    printf("Sending integer: %d\n", random_number);
    printf("Sending SIGUSR1 to PID: %ld\n", (long)receiver_pid);

    if (sigqueue(receiver_pid, SIGUSR1, value) == -1){
        perror("sigqueue");
        return 1;
    }

    printf("Signal sent successfully!\n");

    return 0;
}