/**
* File: send_signal.c
* Modified by: James F. Connelly
*
*
* Description:
* This program waits for SIGUSR1 from another process.
* When the signal is received, it retrieves and prints
* the integer value sent using sigqueue().
*/ 


#include <stdio.h>
#include <signal.h>
#include <unistd.h> 


void handle_signal(int sig, siginfo_t *info, void *context){
    (void)sig;
    (void)context;

    printf("Received Signal Value: %d\n", info->si_value.sival_int);
    fflush(stdout);
}


int main(void){
    struct sigaction action = {0};

    action.sa_sigaction = handle_signal;

    sigemptyset(&action.sa_mask);

    action.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &action, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }

    printf("Receiver is running.\n");
    printf("Receiver PID: %ld\n", (long)getpid());
    fflush(stdout);

    while (1)
    {
        pause();
    }

    return 0;
}