#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(char* argv[]){
    pid_t pid = fork();
    char *command [] = {"ls", "-l", NULL};
    
    if(pid == 0){
        execvp("/usr/bin/ls", command);
        perror("error:");
        _exit(-1);
    }
    int status;
    wait(&status);
    if(WIFEXITED(status)){
        printf("Child returned %d\n", WEXITSTATUS(status));
    }
    wait(0);
    printf("End\n");
    return 0;
}