#ifndef SICT_SOCKETWRAPPER
#define SICT_SOCKETWRAPPER

#include <iostream>
#include <cstring>
#include "../source_c/client.h"

namespace sict {

    class SocketWrapper {
        char* hostname = nullptr;
        char* portno = nullptr;
        bool isEmpty = true;
        bool chkStr(const char*) const;
    public:
        SocketWrapper() {};
        // initialize with hostname and portno
        SocketWrapper(const char* hostname_, const char* portno_);
        ~SocketWrapper();
        // Start connection, send hostname and port no as
        // parameters, return true if successful
        bool connect() const;
        // Send a string to the server
        // returns true if successful
        bool sendMsg(const char* message_) const;
        // returns a reference from the response sent by
        // the server
        char* readResponse() const;
        // close connection with the server
        // returns true if successful
        bool disconnect() const;
        const char* gethostname() const;
        const char* getPortNo() const;
    };
}
#endif //SICT_SOCKETWRAPPER