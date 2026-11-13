/**
* @file signal_handler.c
* @brief Sets a signal handler for SIGINT, the handler prints a message and then
quits
*/
/**
* Modified by: James F. Connelly
*
* Brief summary of modifications: 
* added param sig for signal_handler
* removed exit(1) from handle_signal
*/


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



/**
* @brief Signal handler for SIGINT - prints a message and exits
*/
void handle_signal(int sig) {
    printf("Received signal %d!\n", sig);
    printf("Program still running\n");
}
    


int main() {
    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}