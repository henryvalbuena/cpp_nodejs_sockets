#include "SocketWrapper.h"

namespace sict {
    SocketWrapper::SocketWrapper(const char* nm, const char* port) {
        if (chkStr(nm) && chkStr(port)) {
            hostname = new char[std::strlen(nm)];
            strcpy(hostname, nm);
            portno = new char[std::strlen(port)];
            strcpy(portno, port);
            hasInit = false;
        } else {
            hasInit = true;
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
    bool SocketWrapper::connect() {
        _err = init(hostname, portno);
        if (_err > 0) {
            _err = openConnection();
            if (_err > 0) return true;
            else displayErr(_err);
        } 
        else displayErr(_err);
        return false;
    }
    bool SocketWrapper::sendMsg(const char* msg) {
        clearBuffer();
        _err = sendMessage(msg);
        if (_err > 0) return true;
        else displayErr(_err);
        return false;
    }
    char* SocketWrapper::readResponse() {
        clearBuffer();
        _err = receiveMessage();
        if (_err > 0) return getMessage();
        else displayErr(_err);
        return nullptr;
    }
    bool SocketWrapper::disconnect() {
        _err = closeConnection();
        if (_err > 0) return true;
        else displayErr(_err);
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
    void SocketWrapper::displayErr(int err) const {
        switch (err)
        {
            case HOST_NULL:
                std::cout << "ERROR: Could get hostname.\n";
                break;
            case SOCK_ERR:
                std::cout << "ERROR: Could not create Socket File Descriptor.\n";
                break;
            case CONN_ERR:
                std::cout << "ERROR: Failed to connect with the server.\n";
                break;
            case WRITE_ERR:
                std::cout << "ERROR: Could not send message.\n";
                break;
            case RECV_ERR:
                std::cout << "ERROR: Could not receive message.\n";
                break;
            case CLOSE_ERR:
                std::cout << "ERROR: Could not close connection.\n";
                break;
        }
    }
}