#include "server/server.h"
#include <mantis/mantis.h>

int
main(void) {
    mantis::Server()
        .listen_on("0.0.0.0", 8080)
        .run();

    return 0;
}
