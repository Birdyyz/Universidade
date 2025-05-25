#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("antes do fork\n");
    pid_t pid = fork();//chama fork todas as linhas abaixo desta vão executar 2x (o parent e o child)
    if(pid==0) {
        printf("Hello C\n");
        printf("my PID %d\n", getpid());
        printf("PID of my parent %d\n", getppid());
        _exit(0);//assim as funções fora do if só vão imprimir 1x do parent
    } else {
        printf("HEllo P\n");
        wait(NULL);//só executa depois de o child retornar
        //printf("my PID %d\n", getpid());
        //printf("PID of my parent %d\n", getppid());
    }
    //o resultado é igual estando dentro do if ou fora
    printf("my PID %d\n", getpid());
    printf("PID of my parent %d\n", getppid());
    return 0;
}