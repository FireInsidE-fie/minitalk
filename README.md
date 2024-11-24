# minitalk, or how to hack together interprocess data transfers

for this project, we basically had to find a way to send data from one UNIX
process to the other (client and server executables) using only two system
signals : SIGUSR1 and its counterpart SIGUSR2.

## soooo how does it work?
The client will first need to know the server's process id, or pid, which the
server prints to stdout when starting up. So we first start the server and copy
the pid to provide as first argument when calling the client executable.

For this tiny "protocol", the two signals are used as direct 0 and 1 values,
allowing for binary transmissions. SIGUSR2 represents a 1, SIGUSR1 a 0.

Then the magic happens : The client starts by sending SIGUSR2 (1) to the server
once for every byte the character that's going to be sent next takes up (this
allows for multibyte characters). A full byte of 8 signals is thus transferred 
and the client now knows what size of character to expect. Then the full
character's binary representation is transmitted, and the cycle can start again.