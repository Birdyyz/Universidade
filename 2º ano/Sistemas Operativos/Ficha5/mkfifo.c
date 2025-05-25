#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>

int main(){
    int res = mkfifo("fifo",0600); //0600 -> permissao para ler e escrever
    if(res < 0){
        perror("error opening fifo");
        return -1;
    }
    return 0;
}