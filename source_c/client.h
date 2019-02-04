#ifndef H_CLIENT
#define H_CLIENT
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER 256
// ERROR MACROS
#define OK 1
// Hostname invalid
#define HOST_NULL -1
// Error creating the socket descriptor
#define SOCK_ERR -2
// Connection error
#define CONN_ERR -3
// Error trying to send the message to the server
#define WRITE_ERR -4
// Error trying to read the message from the server
#define RECV_ERR -5
// Error trying to close the TCP connection
#define CLOSE_ERR -6

    // Initialize socket descriptor with server address and port number
    // Returns HOST_NULL if invalid hostname or _SOCK_ERR if fails to create socket
    int init(const char* hostname_, const char* portno_);
    // Start connection with the server
    // Returns CONN_ERR if fails
    int openConnection();
    // Send cstring message to the server BUFFER size 255 characters
    // Returns WRITE_ERR if fails
    int sendMessage(const char* message_);
    // Reads socket descriptor for incoming messages
    // Returns RECV_ERR if fails
    int receiveMessage();
    // Returns cstring message sent by the server
    char* getMessage();
    // Delete buffer's content
    void clearBuffer();
    // Close TCP connection
    // Returns CLOSE_ERR if fails
    int closeConnection();
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // H_CLIENT