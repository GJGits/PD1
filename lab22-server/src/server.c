#include "../../global-headers/sockwrap.h"
#include "../../global-headers/errlib.h"
#include <time.h> 
#include <string.h>

char *prog_name; // per evitare errori di compilazione

int main(int argc, char const *argv[])
{
    uint16_t port;
    int sockfd;
    struct sockaddr_in client_addr;

    parsePort(argv[1], &port);
    sockfd = Socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    bindToAny(sockfd, port);

    memset(&client_addr, 0, sizeof(client_addr));
    printf("Server: ");
    printf(ANSI_COLOR_GREEN "STARTED" ANSI_COLOR_RESET "\n");

    // todo: convertire a loop infinito una volta testato
    for (int i = 0; i < 10; i++) {
        
        ssize_t bytes_recv = 0;
        int addr_len = 0;
        uint32_t buffer;
        bytes_recv = recvfrom(sockfd, &buffer, sizeof(buffer), 
            MSG_WAITALL, (struct sockaddr *) &client_addr, &addr_len);

        // procedo solo se ricevo esattamente 4 bytes
        if (bytes_recv == 4) {
            uint32_t resp_buffer[2];
            resp_buffer[0] = buffer;
            resp_buffer[1] = htonl(time(NULL));
            sendto(sockfd, resp_buffer, sizeof(resp_buffer), 
                MSG_CONFIRM, (const struct sockaddr *) &client_addr, addr_len);
        }
    }

    return 0;
}
