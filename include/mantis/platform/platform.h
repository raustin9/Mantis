/*
 * Mantis
 * platform/platform.h
 *
 * Holds the interface that Mantis uses to interact with platform-specific
 * tasks like networking in a platform-agnostic manner
 */

#pragma once
#include "common/defines.h"
#include <string>

// LINUX INCLUDES
#ifdef Q_PLATFORM_LINUX
#include <netinet/in.h>

#elif Q_PLATFORM_WINDOWS

#endif 


namespace mantis {

namespace platform {

constexpr int BACKLOG = 20; // backlog of connections to put into queue before rejecting

// Platform dependent sockets
class TcpSocket {
public:
    TcpSocket();
    ~TcpSocket();

    int bind(std::string addr, int port);
    int listen_on();
    
    inline bool is_bound() { return m_is_bound; }
private:
    bool m_is_bound = false;

#ifdef Q_PLATFORM_LINUX
    int m_socket; // The socket file descriptor
    int m_port;   // The port for the socket to listen on
    struct sockaddr_in6 m_socket_address;
    unsigned int m_socket_addr_len;
#elif Q_PLATFORM_WINDOWS
    SOCKET m_socket; // The socket file descriptor
#endif // Q_PLATFORM_LINUX

};

}

}
