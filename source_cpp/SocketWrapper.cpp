#include "SocketWrapper.h"

namespace sict {
    SocketWrapper::SocketWrapper(const char* nm, const char* port) : ColorMsg() {
        if (chkStr(nm) && chkStr(port)) {
            hostname = new char[std::strlen(nm)];
            strcpy(hostname, nm);
            portno = new char[std::strlen(port)];
            strcpy(portno, port);
            hasInit = true;
            _err = OK;
        } else {
            hasInit = false;
            hostname = nullptr;
            portno = nullptr;
            _err = EMPTY;
        }
        isConnected = false;
    }
    SocketWrapper::~SocketWrapper() {
        delete [] hostname;
        delete [] portno;
        hostname = nullptr;
        portno = nullptr;
    }
    bool SocketWrapper::connect() {
        if (hasInit) {
            _err = init(hostname, portno);
            if (_err > 0) {
                _err = openConnection();
                if (_err > 0) {
                    isConnected = true;
                    return true;
                } else displayErr(_err);
            } else displayErr(_err);
        } else 
            displayErr(EMPTY);
        return false;
    }
    bool SocketWrapper::sendMsg(const char* msg) {
        if (isConnected) {
            clearBuffer();
            _err = sendMessage(msg);
            if (_err > 0) return true;
            else displayErr(_err);
        } else 
            displayErr(NOT_CONN);
        return false;
    }
    char* SocketWrapper::readResponse() {
        if (isConnected) {
            clearBuffer();
            _err = receiveMessage();
            if (_err > 0) return getMessage();
            else displayErr(_err);
        } else 
            displayErr(NOT_CONN);
        return nullptr;
    }
    bool SocketWrapper::disconnect() {
        if (isConnected) {
            _err = closeConnection();
            if (_err > 0) return true;
            else displayErr(_err);
        } else 
            displayErr(NOT_CONN);
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
    void SocketWrapper::displayErr(int err) {
        switch (err)
        {
            case EMPTY:
                std::cout << ColorMsg::Red("ERROR:") << " Object has no initialization.\n";
                break;
            case HOST_NULL:
                std::cout << ColorMsg::Red("ERROR:") << " Could not get hostname.\n";
                break;
            case SOCK_ERR:
                std::cout << ColorMsg::Red("ERROR:") << " Could not create Socket File Descriptor.\n";
                break;
            case NOT_CONN:
                std::cout << ColorMsg::Red("ERROR:") << " The connection has not been initiated.\n";
                break;
            case CONN_ERR:
                std::cout << ColorMsg::Red("ERROR:") << " Failed to connect with the server.\n";
                break;
            case WRITE_ERR:
                std::cout << ColorMsg::Red("ERROR:") << " Could not send message.\n";
                break;
            case RECV_ERR:
                std::cout << ColorMsg::Red("ERROR:") << " Could not receive message.\n";
                break;
            case CLOSE_ERR:
                std::cout << ColorMsg::Red("ERROR:") << " Could not close connection.\n";
                break;
        }
    }
}