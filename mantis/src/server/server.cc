#include "server/server.h"

namespace mantis {

namespace http {

/* @description Constructor for a server */
TcpServer::TcpServer()
    : m_logger(new qlogger::Logger())
    , m_bind(MANTIS_SERVER_BIND_INIT)
    , m_port(MANTIS_SERVER_PORT_INIT)
    , m_num_worker_threads(MANTIS_SERVER_NUM_WORKERS_INIT)
{

}

/* @description Destructor for server */
TcpServer::~TcpServer() {
    // TODO: shutdown behavior for the server

    m_logger->info("Shutting down...");
    // delete m_logger;
}

/* @description Tell the server what address to bind to and on what port
 * @param num_workers The desired number of worker threads
 */
TcpServer& TcpServer::num_thread_workers(i32 num_workers) {
    m_num_worker_threads = num_workers;
    m_logger->info("Setting number of worker threads to |%d|", num_workers);

    // TODO: check for valid number of threads to use
    return *this;
}

/* @description Tell the server what address to bind to and on what port
 * @param bind The address to bind to
 * @param port The port we want to listen on
 */
TcpServer& TcpServer::listen_on(const std::string& bind, i32 port) {
    m_bind = bind;
    m_port = port;
    m_logger->debug("Setting bind to %s", bind.c_str());
    m_logger->debug("Setting port to %d", port);

    return *this;
}

/* @description Run the server */
TcpServer& TcpServer::run() {
    m_logger->info("Listening on %s:%d", m_bind.c_str(), m_port);
    return *this;
}

} // http namespace
} // mantis namespace
