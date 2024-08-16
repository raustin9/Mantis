#include "platform/platform.h"
#include "common/defines.h"
#include "qlogger.h"

#ifdef Q_PLATFORM_LINUX
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <bits/stdc++.h>
#include <sys/wait.h>


namespace mantis {

namespace platform {

qlogger::Logger linux_logger = qlogger::Logger();

// Linux creation of socket
TcpSocket::TcpSocket()
    : m_socket(socket(AF_INET6, SOCK_STREAM, 0))
{
    if (m_socket < 0) {
        linux_logger.error("Unable to create TCP socket!");
    }
}

// Linux shutdown behavior for TCP socket
TcpSocket::~TcpSocket() {

}

// Bind and name the socket
int TcpSocket::bind(std::string addr, int port) {
    m_socket_address.sin6_family = AF_INET6;
    m_socket_address.sin6_port = htons(port);
    
    if(inet_pton(AF_INET6, addr.c_str(), &(m_socket_address.sin6_addr)) == 1) {
        linux_logger.error("Unable to bind to address '%s'. inet_pton failed.", addr);
        m_is_bound = false;
        return -1;
    }

    m_port = port;
    m_is_bound = true;

    return 0;
}

// Listen on the socket we have created and bound to
int TcpSocket::listen_on() {
    if (!m_is_bound) {
        linux_logger.error("Cannot listen on socket before it has been bound");
        return -1;
    }

    if (listen(m_socket, BACKLOG) < 0) {
        linux_logger.error("TcpSocket cannot listen. listen() call failed.");
        return -1;
    }

    return 0;
}

} // platform namespace

} // mantis namespace

#endif // Q_PLATFORM_LINUX
