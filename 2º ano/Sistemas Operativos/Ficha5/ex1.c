#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    mkfifo("fifo", 0666); 
    int fifo = open("fifo", O_RDONLY); 
    if (fifo == -1) {
        perror("erro");
        return -1;
    }

    char buffer[100];
    
    while(n = read(fifo, buffer,100) > 0){
        write(fifo, buffer, strlen(buffer)); 
    }
    printf("acabou");
    close(fifo);
    return 1;
}