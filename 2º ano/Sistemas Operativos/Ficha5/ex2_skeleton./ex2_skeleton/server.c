#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "defs.h"
#include "vector.h"

//FIFO criado pelo servidor
//Cliente pode receber um sigpipe (concorrência!)

int main (int argc, char * argv[]){

	init_vector();
	print_vector();
	int ocurr = 0;
	int res = mkfifo("SERVER",0600);
	if(res < 0){
		perror("error opening server");
		return -1;
	}
	size_t res;
	int fd = open("SERVER", O_RDONLY);
	if (fd < 0){
		perror("error opening file");
		return -1;
	}
	if(... == res){
		msg.occurrences++;
	}

	close(fd);
	return msg.occurrences;
}
