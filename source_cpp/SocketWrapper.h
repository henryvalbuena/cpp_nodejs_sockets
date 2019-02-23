#ifndef SICT_SOCKETWRAPPER
#define SICT_SOCKETWRAPPER

#include <iostream>
#include <cstring>
#include "../source_c/client.h"
#include "ColorMsg.h"

namespace sict {

    class SocketWrapper {
        // Holds the error type
        int _err;
        // Server address
        char* hostname;
        // Server Port Number
        char* portno;
        // If true the object has been created else is not
        bool hasInit;
        // Tracks connection status
        bool isConnected;
        // cstring validator
        bool chkStr(const char*) const;
        // Error message handling
        void displayErr(int _err);
        // Instance of Color Code module
        ColorMsg color;
    public:
        SocketWrapper() : hostname(nullptr), portno(nullptr), hasInit(true), isConnected(false),
        _err(0), color() {};
        // Initialize with hostname and portno
        SocketWrapper(const char* hostname_, const char* portno_);
        ~SocketWrapper();
        // Start connection, send hostname and port no as
        // parameters, return true if successful
        bool connect();
        // Send a string to the server
        // returns true if successful
        bool sendMsg(const char* message_);
        // Returns a reference from the response sent by the server
        char* readResponse();
        // Close connection with the server
        // returns true if successful
        bool disconnect();
        // Return cstring hostname
        const char* gethostname() const;
        // Return cstring port no
        const char* getPortNo() const;
    };
}
#endif //SICT_SOCKETWRAPPER