#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

ssize_t recv_exact(int sock, void *buf, size_t len) {
    size_t total = 0;
    ssize_t n;
    char *ptr = buf;

    while (total < len) {
        n = recv(sock, ptr + total, len - total, 0);
        if (n == 0) {
            // Connection closed
            return total;
        }
        if (n < 0) {
            if (errno == EINTR) {
                continue; // retry if interrupted
            }
            return -1; // error
        }
        total += n;
    }
    return total; // exactly len bytes received
}

// Usage
char buffer[4096];
ssize_t got = recv_exact(sock, buffer, sizeof(buffer));
if (got != sizeof(buffer)) {
    // handle error or closed connection
}
