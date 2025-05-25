CC = gcc
CFLAGS = -Wall -g

pessoas: pessoas.o person.o

person.o: person.c person.h

pessoas.o: pessoas.c person.h

NUM_REGISTOS = 100

run_script:
	@echo "Rodando o script de inserção..."
	@echo ./pscript.sh $(NUM_REGISTOS)
clean:
	rm -f *.o pessoas file_pessoas

