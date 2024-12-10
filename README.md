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
This way, we can directly translate ASCII characters into 8 bits to send
with the two signals (32 bits for the bonus, slower but supports Unicode).
The server then writes the complete byte to stdout and the next character
is ready to be received.
