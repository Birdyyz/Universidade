#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    printf("Begin\n");
    pid_t pid = fork();
    char *command [] = {"ls", "-l", NULL};
    if(pid == 0){
        //execl("/usr/bin/ls","ls","-l",NULL);
        //execlp("ls","ls", "-l", NULL);
        //execv("ls", command);
        //execvp("/usr/bin/ls", command);
        perror("error:");
        printf("End\n");
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