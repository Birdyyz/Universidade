#include "person.h"

int new_person(char* name, int age){
    Person p;
    strcpy(p.name, name);
    p.age = age;
    //abrir o ficheiro
    int fd = open(FILENAME, O_APPEND| O_CREAT | O_WRONLY,0600);
    // lseek(fd, 0 ,SEEK_END); inves de usar O_APPEND, ambos validos
    //se n der para abrir
    if(fd = -1){
        perror("Error opening file");
        return -1;
    }
    int r = write(fd,&p,sizeof(Person)); //sizeof(p) vai dar ao msm
    if (r ==-1){
        perror("Problems writing syntax");
        return -1;
    }
    //mover o ponteiro x bytes (do sizeof) para tras da posicao atual
    int position = lseek(fd,-sizeof(Person),SEEK_CUR);
    if (position ==- 1){
        perror("Error in position");
        return -1;
    }
    close(fd);
    // para retornar o numero do registo
    return position/sizeof(Person); //ou posiiton/sizeof(p);
}


//Listar as N primeiras pessoas no ficheiro de dados binario.
int list_n_persons(int N){
    Person p;
    char output[100];
    int charssaved=0;
    int fd = open(FILENAME, O_APPEND| O_CREAT | O_WRONLY,0600);
    //se n der para abrir
    if(fd=-1){
        perror("Error opening file");
        return -1;
    }
    //loop para ver as N primeiras pessoas e lista-las
    int i = 0;
    while(i<N && read(fd, &p, sizeof(Person)) > 0) {
        charssaved = sprintf(output, "Register %d, name: %s, age: %d\n", i, p.name, p.age);
        write(1, output, charssaved);
        i++;
    }
    return i;
}
int person_change_age(char *name, int age) {

    /* Create a struct person */
	Person p;

    /* Auxiliar variables for writing to stdout */
    char output[100];
    int output_size=0;

    /* Open file for reading and writing */
    int fd = open(FILENAME, O_WRONLY, 0600);
    if (fd == -1) perror("open error");

    int i = 0;
    while (read(fd, &p, sizeof(Person)) > 0) {

        //output_size = sprintf(output, "Read register %d, name: %s, idade: %d\n", i, p.name, p.age); // imprime os anteriores
        //write(1, output, output_size);

        /* if the name of read person equals the given name */
        if (strcmp(p.name, name) == 0)
        {
            /* update age */
            p.age = age;

            /* return to the begining of the last read person */
            int res = lseek(fd, -sizeof(Person), SEEK_CUR);
            if (res < 0) {
                perror("lseek error");
                return -1;
            }

            /* overwrite the written person with the updated data */
            res = write(fd, &p, sizeof(Person));
            if (res < 0) {
                perror("write error");
                return -1;
            }

            output_size = sprintf(output, "Wrote register %d, name: %s, idade: %d\n", i, p.name, p.age); //imprime o atual
            write(1, output, output_size);

            /* close file descriptor */
            close(fd);

            return 1;
        }

        i++;
    }

    close(fd);
    return 0;

}
/*
int change_age(int position, int age){
    Person p;
    int fd=open(-....)
    lseek(fd,position*sizeof(p),SEEK_SET)
    read(fd,&p,...)
    p.age=agelseek(fd,-seekof(p),SEEK_CUR)
    write(fd,&p,...)
}
*/
//atualizar a idade de uma determinada pessoa no ficheiro de dados
int person_change_age_v2(long position, int age) {
    Person p;
    int fd = open(FILENAME, O_APPEND| O_CREAT | O_WRONLY,0600);
    //se n der para abrir
    if(fd = -1){
        perror("Error opening file");
        return -1;
    }

    //procurar a posicao q temos
    int r = lseek(fd, position*sizeof(Person), SEEK_CUR);
    if (r == -1) {
        perror("searching error");
        return -1;
    }

    //ler o q esta la armazenado
    r = read(fd, &p, sizeof(Person));
    if (r < 0) {
        perror("reading error");
        return -1;
    }
    p.age=age;
    //atualizar a idade
    r= write(fd, &p, sizeof(Person));
    if (r==-1){
        perror("Error writing");
        return -1;
    }
    close(fd);
    return 1;
}