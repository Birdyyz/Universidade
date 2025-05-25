#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define FILENAME "file_pessoas"

typedef struct person{
    char name[200];
    int age;
}Person;

int new_person(char* name, int age);

int list_n_persons(int n);

int update_age(char* name, int new_age);

int update_agev2(long pos,int new_age);