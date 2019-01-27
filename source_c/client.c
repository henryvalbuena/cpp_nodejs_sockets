#include "client.h"

int sockfd, portno, n;
struct sockaddr_in serv_addr;
struct hostent  *server;
char buffer[MAX_BUFFER];
/*
    ******************************************************
    ************SOCKET and Variable definition************
    ******************************************************
*/
// initialize socket and server hostname and port
int init(const char* hostname, const char* port) {
    // convert to int and save argument port #
    portno = atoi(port);
    // create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // check is socket was successfuly created
    if (sockfd < 0) 
        return -1;
    // get hostname save it into the server obj
    server = gethostbyname(hostname);
    if (server == NULL) { // check if server created successfuly
        return -1;
    }
    // fill with zero-n value the address
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // set address IPv4 or IPv6
    // copy string between addresses
    memmove((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr,
    server->h_length);
    serv_addr.sin_port = htons(portno); // swap the endianness of a int
    return 1; // ok
}

/*
******************************************************
**************OPEN CONNECTION WITH SERVER*************
******************************************************
*/
int openConnection() {
    // coonnect using socket, addres (full struct) and the size of the address
    // if it's -1 it failed, if it's 0 succeeded
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        return -1;
    // to be able to connect, we don't need to know our own port no
    // the system will do it for us
    return 1; // ok
}

/*
******************************************************
*****************SEND AND RECEIVE DATA****************
******************************************************
*/
int sendMessage(const char* msg) {
    // fill with zeroes the char array
    // set the char array to zero
    memset(buffer, 0, 256);
    // copy stdin into the char array
    memmove(buffer, msg, MAX_BUFFER);
    // writes the message to the socket and sends it
    // write fn takes the socket, the char array and size of it
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) 
            // error("ERROR writing to socket");
            return -1;
    // clean the buffer again
    memset(buffer, 0, 256);
    return 1; // ok
}

int receiveMessage() {
    // reads the socket for any response
    n = read(sockfd,buffer,255);
    if (n < 0) 
            // error("ERROR reading from socket");
            return -1;
    return 1;
}

char* getMessage() {
    return buffer;
}

int closeConnection() {
    // shutdown connection
    shutdown(sockfd, SHUT_RDWR);
    return 1;
}