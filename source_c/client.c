#include "client.h"

int sockfd, portno;
struct sockaddr_in serv_addr;
char buffer[MAX_BUFFER];

// initialize socket and server hostname and port
int init(const char* hostname, const char* port) {
    // convert to int and save argument port #
    portno = atoi(port);
    // create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // check is socket was successfuly created
    if (sockfd < 0) 
        return SOCK_ERR;
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // set address IPv4 or IPv6
    // convert char hostname to binary form
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0)
        return HOST_NULL; 
    serv_addr.sin_port = htons(portno); // swap the endianness of an int
    return OK; // ok
}
/*
******************************************************
**************OPEN CONNECTION WITH SERVER*************
******************************************************
*/
int openConnection() {
    // connect using socket, address (full struct) and the size of the address
    return connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 ? CONN_ERR : OK;
}
/*
******************************************************
*****************SEND AND RECEIVE DATA****************
******************************************************
*/
int sendMessage(const char* msg) {
    // copy msg to buffer
    memmove(buffer, msg, MAX_BUFFER);
    // writes the message to the socket and sends it
    // write fn takes the socket file descriptor, the char array and size of it
    return send(sockfd, buffer, strlen(buffer), 0) < 0 ? WRITE_ERR : OK;
}

int receiveMessage() {
    // reads the socket for any response
    return recv(sockfd, buffer, MAX_BUFFER, 0) < 0 ? RECV_ERR : OK;
}

void clearBuffer() {
    memset(buffer, 0, MAX_BUFFER);
}

char* getMessage() {
    return buffer;
}

int closeConnection() {
    // close connection
    return close(sockfd) < 0 ? CLOSE_ERR : OK;
}