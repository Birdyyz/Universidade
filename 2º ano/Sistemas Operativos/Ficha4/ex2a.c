#include <unistd.h>
#include <stdio.h>

int main(){
    int fildes[2];  
    __pid_t pid;
    pipe(fildes);
    int nums[] = {10, 20, 500, 10000, 1000000};
    int tam = sizeof(nums);

    if (pipe(fildes) == -1) {
        perror("Erro 1");
        return -1;
    }
    if((pid = fork()) == 0){
        close(fildes[1]);
        //sleep(5);
        int numleitura[5];
        read(fildes[0], &numleitura, sizeof(numleitura));
        printf("Pai recebeu os numeros\n");
        for (int i = 0; i < 5; i++) {
            printf("%d\n", numleitura[i]);
        }
        close(fildes[0]);

    }
    else{
        close(fildes[0]);
        write(fildes[1], &nums, tam); 
        close(fildes[1]);
        
    }
    return 0;
}

