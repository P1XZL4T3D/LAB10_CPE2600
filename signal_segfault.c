/**
* @file signal_segfault.c
* @brief Program that dereferences a null pointer causing a segmentation fault
*/

/**
* Modified by: James F. Connelly
*
* Brief summary of modifications: 
* Added handle_signal function
* Added a signal to be sent and handled in main
*/

#include <stdio.h>
#include <signal.h>

void handle_segfault(int sig) {
    (void) sig;

    printf("Segmentation fault recieved!\n");
}


int main () {

    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);
    
    // Return to exit the program
    return 0;
}