#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int state;
    pid_t ret;

    pid = fork();
    if(pid == 0)
    {
        sleep(1);
        ret = waitpid(-1, &state, 0);
        printf("child : %d\n", ret);
        perror("child");
        printf("this is child\n");
    }
    else
    {
        ret = waitpid(pid, &state, 0);
        printf("parents : %d\n", ret);
        perror("parents");
        printf("child pid : %d\n", ret);
        printf("this is parent");
    }
    return(0);
}