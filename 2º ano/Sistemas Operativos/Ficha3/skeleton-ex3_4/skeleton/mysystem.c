#include "mysystem.h"


// recebe um comando por argumento
// returna -1 se o fork falhar
// caso contrario retorna o valor do comando executado
int mysystem (const char* command) {
	char* copy = strdup(command);
	char* array[10];
	char* token;
	int i = 0;
	while((token = strsep(&copy, " ")) != NULL){
		if(*token != '\0'){
			array[i] = token;
			i++;
		}
	}
	array [i] = NULL;
	pid_t pid = fork();
    
    if(pid == 0){
        execvp(array[0], array);
        perror("error:");
        _exit(-1);
    }
    int status;
    wait(&status);
    if(WIFEXITED(status)){
        printf("Child returned %d\n", WEXITSTATUS(status));
    }
    wait(0);
    printf("End\n");
    return 0;
}