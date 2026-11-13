/**
* File: signal_sigaction.c
* Modified by: James F. Connelly
*
* Description:
* This program registers a handler for SIGUSR1.
* When SIGUSR1 is received, the handler prints
* the process ID of the sender.
*
* Command to send SIGUSR1:
* kill -SIGUSR1 PID
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>



void handle_signal(int sig, siginfo_t *info, void *context){
    (void)sig;
    (void)context;

    printf("SIGUSR1 recieved!\n");
    printf("Sender PID: %ld\n", (long)info->si_pid);
} 



int main(void){
    struct sigaction action;

    action.sa_sigaction = handle_signal;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &action, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }

    printf("Waiting for SIGUSR1...\n");
    printf("My PID is: %ld\n", (long)getpid());

    while (1)
    {
        pause();
    }

    return 0;


}