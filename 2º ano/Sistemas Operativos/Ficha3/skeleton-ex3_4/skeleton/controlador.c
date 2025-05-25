#include <stdio.h>
#include "mysystem.h"

void controller(int N, char** commands) {
	pid_t arraypid [N];

	for(int i = 0; i < N ; i++){
		pid_t pid = fork();
		arraypid[i] = pid;

		if(pid == 0){

		}

	}
	
}

int main(int argc, char* argv[]) {

    char *commands[argc-1];
    int N = 0;
	for(int i=1; i < argc; i++){
		commands[N] = strdup(argv[i]);
		printf("command[%d] = %s\n", N, commands[N]);
        N++;
	}
    controller(N, commands);
	return 0;
}