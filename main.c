#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pueblo.h"


//Metodos

int main(int argc, char **argv){
    if (argc != 5){
        fprintf(stderr, "ejecutar como ./prog pisos origen destino modo\n");
        exit(EXIT_FAILURE);
    }
    int pisos = atoi(argv[1]);
    int origen = atoi(argv[2]);
    int destino = atoi(argv[3]);
    int mode = atoi(argv[4]);
    int aux = (origen+destino == 4) ? 2 : ((origen+destino == 5) ? 1: 3);

    //MAIN CODE

    pueblo *pueblos = crear_pueblos(pisos, origen);
    print_tower(pueblos);
    if (mode == 0){
        moviendo(pisos, origen, destino, aux, &pueblos, mode);
        print_tower(pueblos);
    }else{
        moviendo_por_paso(pisos, origen, destino, aux, &pueblos, mode);
    }

    return EXIT_SUCCESS;
}