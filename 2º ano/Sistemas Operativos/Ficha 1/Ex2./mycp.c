#include "mycp.h"
// cp -> copiar arquivos ou diretórios 
int mycp(){
    int source=0, destination=0;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read , bytes_written;
    while ((bytes_read = read(source, buffer, BUFFER_SIZE)) > 0) {
        write(destination, buffer, bytes_read);
    }
    printf("Left while cycle\n");
return 0;

}

int mycpv2(char* filename, char* destiny){
         int source, destination;
         source= open(filename, O_RDONLY);
         if (source==-1){
           printf("Error opening file\n");
           return -1;
}
 char *buffer = malloc(sizeof(char) * BUFFER_SIZE);

      ssize_t bytes_read , bytes_written;
     destination = open(destiny, O_WRONLY | O_CREAT | O_TRUNC, 0600);
     if(destination==-1){
        printf("Error destination file\n");
        return -1;
     }
     while ((bytes_read = read(source, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(destination, buffer, bytes_read);
        if(bytes_written!=bytes_read){
            printf("Error copying to destiny\n");
            return -1;
        }
    }
printf("Left while cycle\n");
free(buffer); 
close(source);
close(destination);
return 0;
}

