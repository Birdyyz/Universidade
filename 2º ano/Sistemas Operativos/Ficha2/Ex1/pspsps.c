#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
    pid_t pid = getpid(); //o seu pid
    pid_t pidp= getppid(); //o pid do pai
    printf("O seu pid é %d\n E o do pai é %d\n", pid ,pidp);
    return 0;
}
    /*
    if((pid==fork())==0){
        sprintf("Pid igual a fork igual a 0")
    }
    else{
        sprintf()
    }
    */
