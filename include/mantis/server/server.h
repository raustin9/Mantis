#pragma once
#include "common/types.h"

#include <qlogger/qlogger.h>
#include <string>
#include <memory>

namespace mantis {

/* Initial values for server parameters */
constexpr const char* MANTIS_SERVER_BIND_INIT = "__internal__mantis__bind__init__4444";
constexpr i32 MANTIS_SERVER_PORT_INIT = -1;
constexpr i32 MANTIS_SERVER_NUM_WORKERS_INIT = -1;

class Server {
public:
    Server();
    ~Server();
    Server(const Server&) = delete;

    // Set the values for the server to bind and listen on
    Server& listen_on(const std::string& bind, i32 port);

    // Set the number of threads we want to use to handle incoming requests
    Server& num_thread_workers(i32 num_workers);

    // Run the server
    Server& run();
private:
    qlogger::Logger* m_logger;
    std::string m_bind;       // Address to listen on
    i32 m_port;               // Port to listen on
    i32 m_num_worker_threads; // Number of worker threads to handle requests
    
};

} // mantis namespace
