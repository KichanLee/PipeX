#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int fd[2];
    char buffer[40];

    pid_t pid;
    int state;

    state = pipe(fd);
    // fd[0] -> read, fd[1] -> write
    if(state == -1)
    {
        // pipe fail -> -1 return
        puts("pipe() error!");
        exit(1);
    }
    pid = fork();
    // parents -> child process 복사
    if(pid == -1)
    {
        // fork fail -> error
        puts("fork() error!");
        exit(1);
    }
    else if(pid == 0)
    {
        // 
        write(fd[1], "연결성공!\n", 25);
    }
    else
    {
        read(fd[0], buffer, 30);
        puts(buffer);
    }
    return 0;
}
