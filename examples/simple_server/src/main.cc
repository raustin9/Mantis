#include "server/server.h"
#include <mantis/mantis.h>

int
main(void) {
    mantis::http::TcpServer()
        .listen_on("0.0.0.0", 8080)
        .run();

    return 0;
}
