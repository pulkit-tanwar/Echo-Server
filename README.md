# Echo Server Program in C language.

### An "echo server" is a server that does nothing more than sending back whatever is sent to it. Hence the name : echo 

The "echo server" can be set up to listen on any desired (tcp) port to simulate whatever application you want to run (eg web server = port 80, Microsoft SQL Server = port 1433, etc). From the client machine, you can then telnet to this port. When a telnet connection has been established, everything you type will be echoed back to your screen, indicating that the telnet client and the echo server can talk to each other : you've established connectivity at the application level.


## Compiling and Running on Linux Shell :

### Compile Command:
> gcc -g Echo-Server.c -o sockets


### Execute Command:
> ./sockets 12345

Here 12345 is the Port Number.

### Client can connect by using following command:
> telnet localhost 12345 


__________________________________________

TCP ECHO SERVER USING SOCKETS<br/>
Developed By:<br/>
[Prashant Shrivastava](http://www.linkedin.com/in/prashantdce19) <br/>
[Pulkit Tanwar](http://www.pulkitme.com)<br/>
Rishabh Agarwal<br/>
