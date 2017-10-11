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
    int aux = (origen+destino == 4)? 2 : ((origen+destino == 5)? 1: 3);
    printf("aux: %i\n", aux);

    //MAIN CODE

    pueblo *pueblos = crear_pueblos(pisos, origen);
    print_tower(pisos, pueblos);
    mover_piso(origen,destino,&pueblos);
    print_tower(pisos, pueblos);

    return EXIT_SUCCESS;
}

void print_tower(int pisos, pueblo *town){
    int max_altura;
    int highest_town;
    for (int i = 0; i < 3; i++){
        printf("altura pueblo %i: %i\t", town[i].num_pueblo, town[i].altura);
        piso *r = town[i].comienzo;
        while (r != NULL){
            printf("|-%i-|", r->diametro);
            r = r->abajo;
        }
        printf("\n");
    }
    for (int j = 0; j < 3; j++){
        printf("pueblo %i\t",town[j].num_pueblo);
    }
    printf("\n");
}