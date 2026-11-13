# CPE-2600 - Systems Programming
## Lab 10: Signals
---

## Project Description

The purpose of this lab is to explore POSIX signals as an
inter-process communication technique.

This lab demonstrates how to:
- Register and handle signals.
- Send signals between processes.
- Use SIGALRM and SIGSEGV.
- Register signal handlers using sigaction().
- Retrieve information about received signals.
- Send integer data between processes using sigqueue().

## Files and Programs

| File | Description |
|---|---|
| signal_handler.c | Registers and handles SIGINT. |
| signal_alarm.c | Uses alarm() to generate SIGALRM after 5 seconds. |
| signal_segfault.c | Demonstrates handling a segmentation fault using SIGSEGV. |
| signal_sigaction.c | Uses sigaction() to receive SIGUSR1 and display the sender PID. |
| recv_signal.c | Receives SIGUSR1 and retrieves an integer using sigqueue(). |
| send_signal.c | Generates a random integer and sends it using sigqueue(). |
| makefile | Compiles all Lab 10 programs. |

## Requirements

- Linux environment or WSL.
- GCC compiler.
- Make utility.

## Compilation

To compile all programs, run:
make