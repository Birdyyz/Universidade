#include "mycat.h"


/*int main(){
    //printf("ola mundo\n");

    write(1, "ola mundo\n", 10); //1 é o fd que escreve pra o ecrã; 10 é os bytes no buffer, neste caso "ola mundo" (9+1)

    return 0;
}*/

int mycat(){
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0){ //0 é o fd que lê; buffer é o buffer hahaha lol; buffer_size é o maximo que pode ler
        //printf("bytes_read: %ld\n", bytes_read);
        write(1, buffer, bytes_read); //neste caso lemos os bytes necessarios entao colocamos bytes_read em vez de buffer_size pq é desnecessário

    }
    printf("saí!!!!!!!!!!!!!!!!!\n"); //só sai a fazer ctrl+d no terminal
    return 0;
}

int mycatv2(char* filename){
    int fd = open(filename, O_RDONLY);
    if(fd == -1){
        printf("erro printf\n");
        perror("erro perror open file:"); //diz o tipo de erro encontrado mas apenas o ultimo erro entao colocar perror onde queremos ver se tem erros
        return -1;
    }

    char *buffer = malloc(sizeof(char)*BUFFER_SIZE);
    ssize_t bytes_read;

    while((bytes_read = read(0, buffer,BUFFER_SIZE)) > 0){ //0 é o fd que lê; buffer é o buffer hahaha lol; buffer_size é o maximo que pode ler
        //printf("bytes_read: %ld\n", bytes_read);
        write(fd, buffer, bytes_read); //neste caso lemos os bytes necessarios entao colocamos bytes_read em vez de buffer_size pq é desnecessário

    }
    printf("saí!!!!!!!!!!!!!!!!!\n"); //só sai a fazer ctrl+d no terminal
    free(buffer); 
    close(fd); //fecha o descritor que abrimos anteriormente com o open
    return 0;
}
