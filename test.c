#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *const *argv, char **envp)
{
    char *arr[] = {"ls", "-al", NULL};
    int returnv = execve("/bin/ls", arr, envp);
    printf("value = %d\n", returnv);
    
}