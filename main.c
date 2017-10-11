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

    //MAIN CODE

    pueblo *pueblos = crear_pueblos(pisos, origen);
    print_tower(pisos, pueblos);
    mover_piso(origen,destino,&pueblos);
    print_tower(pisos, pueblos);

    return EXIT_SUCCESS;
}

void print_tower(int pisos, pueblo *town){
    int max_altura = 0;
    int highest_town = 0;

    for (int h = 0; h < 3; h++){
        //printf("altura pueblo %i: %i\t", town[h].num_pueblo, town[h].altura);
        max_altura = (town[h].altura > max_altura)? town[h].altura: max_altura;
        highest_town = (town[h].altura == max_altura) ? town[h].num_pueblo: highest_town;
        //printf("max_altura: %i, pueblo: %i\n", max_altura, highest_town);
    }

    //char *buf[100] = "";

    for(int level = max_altura; level > 0; level--){
        for (int t = 0; t < 3; t++){
            if (town[t].altura >= level){
                piso *temp = town[t].comienzo;
                for (int s = town[t].altura ; s >level; s--){
                    temp = temp->abajo;
                }
                printf("|-%i-|\t\t", (*temp).diametro);
            }else{
                printf("\t\t");
            }
        }
        printf("\n");
    }

    for (int j = 0; j < 3; j++){
        printf("pueblo %i\t",town[j].num_pueblo);
    }
    printf("\n");
}