#include "types.h"
#include "user.h"

int main(void) {
    int pipefd[2];
    char buffer[20];

    // Create a pipe
    pipe(pipefd);

    int pid = fork();

    if (pid == 0) {  // Child process
        read(pipefd[0], buffer, sizeof(buffer));
        printf(1, "Child received: %s\n", buffer);
        close(pipefd[0]);
        exit();
    } else {  // Parent process
        write(pipefd[1], "Hello from parent!", 18);
        close(pipefd[1]);
        wait();
        exit();
    }
}
