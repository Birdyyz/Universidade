#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("antes do fork\n");

    for(int i=1; i<=10 ; i++){
        pid_t pid = fork();//chama fork todas as linhas abaixo desta vão executar 2x (o parent e o child)
    if(pid==0) {
        printf("Hello C\n");
        printf("my PID %d\n", getpid());
        printf("PID of my parent %d\n", getppid());
        //sleep(5);
        _exit(i);//assim as funções fora do if só vão imprimir 1x do parent
    
    } else {
        int status;
        printf("hello p %d n ", getpid());
        pid_t pidc = wait(&status);
        if(WIFEXITED(status)){ //se retornar tp 0 -1 quer dizer q algo interrompeu o processo do child
            printf("child %d exited  with value %d\n", pidc, WEXITSTATUS(status));
        }
        else{
            printf("child process was interrupted\n");
        }

    }}
    return 0;
}