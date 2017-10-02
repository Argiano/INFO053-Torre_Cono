#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pueblo.h"

//Metodos
void print_tower(int N, pueblo*town);

int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "ejecutar como ./prog N\n");
        exit(EXIT_FAILURE);
    }

    print_tower(atoi(argv [1]), NULL);


    return EXIT_SUCCESS;
}

void print_tower(int N, pueblo *town){
    for(int i = 0; i < N; i++){
        printf("|-%i-|\n", i);
    }
    printf("Pueblo 1\n");
}
