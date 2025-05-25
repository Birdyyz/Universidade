#include <stdio.h>
#include <string.h>
#include "person.h"


/*atoi-> transforma int em string*/
int main(int argc, char* argv[]){

	char id[25]="";

    if (argc < 3)
    {
        printf("Usage:\n");
        printf("Add new person: ./pessoas -i [name] [age]\n");
        printf("List N persons: ./pessoas -l [N]\n");
        printf("Change person age: ./pessoas -u [name] [age]\n");
        printf("Change person age (v2): ./pessoas -o [position] [age]\n");
        return 1;
    }
//adiciona uma pessoa
    if(strcmp(argv[1],"-i")==0){
        int r = new_person(argv[2], atoi(argv[3]));
        snprintf(id, 20,  "registo %d\n", r);
		write(STDOUT_FILENO, id, sizeof(id));
    }
//lista as N pessoas
    if(strcmp(argv[1],"-l")==0){
        int r = list_n_persons(atoi(argv[2]));
        snprintf(id, 25,  "Registos lidos: %d\n", r);
        write(STDOUT_FILENO, id, sizeof(id));
    }
    if(strcmp(argv[1],"-u")==0){
        person_change_age(argv[2], atoi(argv[3]));

    }
//atualiza a idade
    if(strcmp(argv[1],"-o")==0){
        person_change_age_v2(atoi(argv[2]), atoi(argv[3])); 

    }

    return 0;
}