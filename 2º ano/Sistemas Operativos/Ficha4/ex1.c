#include <unistd.h>
#include <stdio.h>

int main(){
    int fildes[2];  
    __pid_t pid;
    pipe(fildes);
    int numero = 10;
    if (pipe(fildes) == -1) {
        perror("Erro 1");
        return -1;
    }
    if((pid = fork()) == 0){
        close(fildes[1]);
        int numleitura;
        read(fildes[0], &numleitura, sizeof(numleitura)); //  filho receber um inteiro a partir do respetivodescritor de leitura
        printf("Filho recebeu o numero %d\n", numleitura);
        close(fildes[0]);
        
    }
    else{
        close(fildes[0]);
        sleep(5);
        write(fildes[1], &numero, sizeof(numero));
        printf("Pai escreveu o numero %d\n", numero);
        close(fildes[1]);
        
    }
    return 0;
}

