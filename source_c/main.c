#include "client.h"

int main(int argc, char *argv[])
{
    int flag = 0; // false

    getArgs(argv, argc);
    printf("getArgs(): OK\n");
    flag = init(argv);
    if (flag)
        printf("init(): OK\n");
    flag = openConnection();
    if (flag)
        printf("openConnection(): OK\n");
    flag = sendMessage("HELLO");
    if (flag)
        printf("sendMessage(): OK\n");
    flag = receiveMessage();
    if (flag)
        printf("receiveMessage(): OK\n");
    printf("Response: %s\n", getMessage());
    if (closeConnection()) {
        printf("Connection Closed, end of Program\n");
        return 0;
    }
    printf("ERROR\n");
    return -1;
    
}
