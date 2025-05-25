#include <unistd.h>
#include <stdio.h>

int main(){
    int fildes[2];  
    __pid_t pid;
    pipe(fildes);
    int nums[] = {10, 20, 500, 10000, 1000000};

    if (pipe(fildes) == -1) {
        perror("Erro 1");
        return -1;
    }

    if((pid = fork()) == 0){
        close(fildes[0]);
        for(int i = 0; i < 1000000; i++){
        write(fildes[1], &nums[i], sizeof(nums[i]));
        printf("numero %d\n",nums[i]);   
        }
        close(fildes[1]);
    }
    else{

        close(fildes[1]);
        //sleep(5);
        int numleitura; // como recebemos um a um ja nao usamos o array
        printf("Pai recebeu os numeros\n");
        while(read(fildes[0], &numleitura, sizeof(numleitura))>0){
            printf("%d\n", numleitura);
        }
        printf("fim do ciclo while\n");
        close(fildes[0]);
    }
    return 0;
}
