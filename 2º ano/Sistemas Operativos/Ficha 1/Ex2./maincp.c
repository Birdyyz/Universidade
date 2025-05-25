#include "mycp.h"
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {  // Verifica se foram passados dois argumentos (arquivo origem e destino)
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        return -1;
    }

    clock_t start_time = clock();  // Começa a medir o tempo

    // Chama a função que copia o arquivo
    if (mycpv2(argv[1], argv[2]) == -1) {
        printf("Error during file copy.\n");
        return -1;
    }

    clock_t end_time = clock();  // Fim da medição de tempo

    // Calcula o tempo total em segundos
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to copy the file: %.2f seconds\n", time_taken);

    return 0;
}
