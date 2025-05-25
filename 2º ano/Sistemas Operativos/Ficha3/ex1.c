#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    char *command [] = {"ls", "-l", NULL};
    printf("Begin\n");
    execl("/usr/bin/ls","ls","-l",NULL);
    //execlp("ls","ls", "-l", NULL);
    //execv("ls", command);
    //execvp("/usr/bin/ls", command);
    printf("End\n");
    return 0;
}