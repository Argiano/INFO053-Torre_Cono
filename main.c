#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pueblo.h"

//Metodos
void print_tower(int N, pueblo*town);

int main(int argc, char **argv){
    if (argc != 5){
        fprintf(stderr, "ejecutar como ./prog pisos origen destino modo\n");
        exit(EXIT_FAILURE);
    }
    int pisos = atoi(argv[1]);
    int origen = atoi(argv[2]);
    int destino = atoi(argv[3]);
    int mode = atoi(argv[4]);

    //MAIN CODE
    print_tower(pisos, NULL);

    return EXIT_SUCCESS;
}

void print_tower(int N, pueblo *town){
    for(int i = 0; i < N; i++){
        printf("|-%i-|\n", i);
    }
    printf("Pueblo 1\n");
}