#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Failed to fork");
        return 1;
    }

    if (pid == 0) {
        /* This block will be executed by the child process */
        char *args[] = {"/bin/ls", "-l", NULL};
        
        if (execve(args[0], args, envp) == -1) {
            perror("Failed to execve");
            return 1;
        }
    } else {
        /* This block will be executed by the parent process */
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            perror("Failed to waitpid");
            return 1;
        }
    }
    return 0;
}
