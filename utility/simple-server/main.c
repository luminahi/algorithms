#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // create and set up the server socket
    if (((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("server is listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(
            server_fd, 
            (struct sockaddr*)&address, 
            (socklen_t*)&addrlen)) < 0) 
        {
            perror("accept failed");
            close(server_fd);
            exit(EXIT_FAILURE);
        }

        printf("connection established\n");

        // read data from the client
        int bytes_read = read(new_socket, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            perror("read failed");
            close(new_socket);
            close(server_fd);
            exit(EXIT_FAILURE);
        }
        printf("received message: %s\n", buffer);

        // send response to the client
        char* message = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nhello from my C server!";
        send(new_socket, message, strlen(message), 0);
        close(new_socket);
    }

    close(server_fd);

    return 0;
}