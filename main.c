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

    //Validacion entradas
    if (pisos <1){
        fprintf(stderr, "numero de pisos debe ser mayor que cero\n");
        exit(EXIT_FAILURE);
    }
    if (mode != 1 && mode != 0){
        fprintf(stderr, "modo incorrecto. Debe ingresar 0/1\n");
        exit(EXIT_FAILURE);
    }
    if (origen == destino || origen <1 || destino < 1 || origen > 3 || destino > 3){
        fprintf(stderr, "origen/destino incorrectos. deben ser enteros (1, 2, 3) y distintos entre si\n");
        exit(EXIT_FAILURE);

    }
    int aux = (origen+destino == 4) ? 2 : ((origen+destino == 5) ? 1: 3);

    //MAIN CODE

    pueblo *pueblos = crear_pueblos(pisos, origen);
    printf("----------ESTADO INICIAL----------\n");
    print_tower_char(pueblos);

    moviendo(pisos, origen, destino, aux, &pueblos, mode);
    
    printf("Total de movimientos: %i\n", total_mov(pisos));
    printf("-----------ESTADO FINAL----------\n");
    print_tower_char(pueblos);
    
    return EXIT_SUCCESS;
}