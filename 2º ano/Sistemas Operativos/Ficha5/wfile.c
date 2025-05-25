#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    char buffer [1024];
    size_t res;
    int fd = open("fifo", O_WRONLY);
    while((res = read(0, buffer, 1024)) > 0){ // 0 -> standard input
        write(fd,buffer,res);
    }

    close(fd);

    return 0;
}