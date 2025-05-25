#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
// lê e com o write repete para o seu standard output todas as linhas de texto lidas a partir deste mesmo pipe
int main(){
    char buffer [1024];
    size_t res;
    int fd = open("fifo", O_RDONLY);
    while((res = read(fd, buffer, 1024)) > 0){
        write(1,buffer, res); // 1-> standard output
    }

    close(fd);
    return 0;
}