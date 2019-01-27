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

#define MAX_BUFFER 256
    void getArgs(char*[], int);
    int init(const char*, const char*);
    int openConnection();
    int sendMessage(const char*);
    int receiveMessage();
    char* getMessage();
    int closeConnection();
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // H_CLIENT