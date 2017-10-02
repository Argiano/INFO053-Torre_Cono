#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "floor.h"

//Metodos
void print_tower(int N);

int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "ejecutar como ./prog N\n");
        exit(EXIT_FAILURE);
    }

    print_tower(atoi(argv [1]));
    return EXIT_SUCCESS;
}

void print_tower(int N){
    for(int i = 0; i < N; i++){
        printf("|-%i-|\t|-%i-|\n", i, NULL);
    }
}
