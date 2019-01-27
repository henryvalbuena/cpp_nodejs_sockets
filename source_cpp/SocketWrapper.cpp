#include "SocketWrapper.h"

namespace sict {
    SocketWrapper::SocketWrapper(const char* nm, const char* port) {
        if (chkStr(nm) && chkStr(port)) {
            hostname = new char[std::strlen(nm)];
            strcpy(hostname, nm);
            portno = new char[std::strlen(port)];
            strcpy(portno, port);
            isEmpty = false;
        } else {
            isEmpty = true;
            hostname = nullptr;
            portno = nullptr;
        }
    }
    SocketWrapper::~SocketWrapper() {
        delete [] hostname;
        delete [] portno;
        hostname = nullptr;
        portno = nullptr;
    }
    bool SocketWrapper::connect() const {
        if (init(hostname, portno) > 0) {
            if (openConnection() > 0)
                return true;
        }
        return false;
    }
    bool SocketWrapper::sendMsg(const char* msg) const {
        if (sendMessage(msg) > 0)
            return true;
        return false;
    }
    char* SocketWrapper::readResponse() const {
        if (receiveMessage() > 0) {
            return getMessage();
        }
        return nullptr;
    }
    bool SocketWrapper::disconnect() const {
        if (closeConnection() > 0)
            return true;
        return false;
    }
    const char* SocketWrapper::gethostname() const {
        return hostname;
    }
    const char* SocketWrapper::getPortNo() const {
        return portno;
    }
    bool SocketWrapper::chkStr(const char* str) const {
        if (str == nullptr || str[0] == '\0')
            return false;
        return true;
    }
}