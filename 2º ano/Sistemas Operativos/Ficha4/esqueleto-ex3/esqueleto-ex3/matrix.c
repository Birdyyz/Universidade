#include "matrix.h"


int **createMatrix() {

    // seed random numbers
    srand(time(NULL));

    // Allocate and populate matrix with random numbers.
    printf("Generating numbers from 0 to %d...", MAX_RAND);
    int **matrix = (int **) malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * COLUMNS);
        for (int j = 0; j < COLUMNS; j++) {
            matrix[i][j] = rand() % MAX_RAND;
        }
    }
    printf("Done.\n");

    return matrix;
}

void printMatrix(int **matrix) {
    for (int i = 0; i < ROWS; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < COLUMNS; j++) {
            printf("%7d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void lookupNumber(int** matrix, int value, int* vector){
    Minfo a;
    int fildes[2];  
    __pid_t pid;
    pipe(fildes);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if ((pid = fork())== 0){

                if(matrix[i][j] == value){
                    close(fildes[0]);
                    a.line_nr = i;
                    a.ocur_nr++;
                    write(fildes[1],&i, sizeof(int)); 
                    
                    close(fildes[1]);
                }
            }
            else{
                close(fildes[1]);
                vector = malloc(sizeof(int));
                while(read(fildes[0], &a, sizeof(int))>0){
                    vector[a.line_nr] = a.ocur_nr;
                    printf("linha %d \n ocorrencias %d\n ", a.line_nr, a.ocur_nr);
                }
                close(fildes[0]);
            }
    }
}
}