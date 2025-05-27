#include "types.h"
#include "user.h"

int main(void) {
    int pipefd[2];
    char buffer[100];

    // Create a pipe
    if (pipe(pipefd) < 0) {
        printf(1, "Pipe creation failed\n");
        exit();
    }

    int pid = fork();
    if (pid < 0) {
        printf(1, "Fork failed\n");
        exit();
    }

    if (pid == 0) {  // Child process
        close(pipefd[1]);  // Close the write end

        // Read from the pipe
        read(pipefd[0], buffer, sizeof(buffer));
        printf(1, "Child received: %s\n", buffer);

        close(pipefd[0]);  // Close the read end
        exit();
    } else {  // Parent process
        close(pipefd[0]);  // Close the read end

        // Write to the pipe
        char *message = "Hello from parent!";
        write(pipefd[1], message, strlen(message) + 1);

        close(pipefd[1]);  // Close the write end
        wait();  // Wait for the child process to finish
        exit();
    }
}
