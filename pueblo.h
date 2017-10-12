#ifndef PUEBLO_H
#define PUEBLO_H

#define ANCHO_MAXIMO 24

//estructuras PISO
typedef struct piso{
    int diametro;
    struct piso *abajo;
}piso;

//Estructura pueblo
typedef struct pueblo{
    int num_pueblo;
    struct piso *comienzo;
    int altura;
}pueblo;


//---------
//FUNCIONES
//---------

void new_piso();
pueblo crear_pueblo(int altura, int numero);
piso *crear_piso(piso* start, int d);
void mover_piso(int origen, int destino, pueblo **pueblos, int modo);
piso* pop(piso** p);
void push(piso** pila, piso *aux);
int* crear_diametros(int largo);
int *ordenar_lista(int *lista, int largo);
void moviendo(int pisos, int origen, int destino, int aux,  pueblo **town, int modo);
void print_tower(pueblo *town);


//---------------------
//DECLARACION FUNCIONES
//---------------------


pueblo *crear_pueblos(int altura, int torre){
    //Array de pueblos
    pueblo *p = (pueblo*)malloc(sizeof(pueblo)*3);
    for(int i = 0; i < 3; i++){
        p[i] = (i == torre-1)? crear_pueblo(altura, torre): crear_pueblo(0,i+1);
    }
    return p;
}


pueblo crear_pueblo(int altura, int numero){
    pueblo town;
    town.num_pueblo = numero;
    town.altura = altura;
    town.comienzo = NULL;
    //printf("altura %i \n", altura);
    int *diametros = crear_diametros(altura);
    for (int i = 0; i < altura; i++){
        town.comienzo = crear_piso(town.comienzo, diametros[i]);
    }
    return town;
}

piso* crear_piso(piso* start, int d){
    piso *p = (piso*)malloc(sizeof(piso));
    p->diametro = d;
    p->abajo = start;

    return p;
}

void mover_piso(int origen, int destino, pueblo **pueblos, int modo){ 
    piso *aux = pop(&((*pueblos)[origen-1].comienzo));
    (*pueblos)[origen-1].altura--;
    push(&((*pueblos)[destino-1].comienzo), aux);
    (*pueblos)[destino-1].altura++;
    //Si el modo ingresado es distinto de cero se esperara a presionar
    //una tecla para imprimir el estado actual de la torre
    if (modo != 0){
        system("PAUSE");
        print_tower(*pueblos);
    }
}

piso* pop(piso **p){
    piso *temp = *p;
    *p = (*p)->abajo;
    return temp;
}

void push(piso** pila, piso *aux){
    (aux)->abajo = *pila;
    *pila = (aux);
}

int *crear_diametros(int largo){
    int *diametros = (int*)malloc(sizeof(int)*largo);
    for (int i = 0; i < largo; i++){
        diametros[i] = (rand()&23)+1;
    }
    return ordenar_lista(diametros, largo);
}

int *ordenar_lista(int *lista, int largo){
    for (int i = 0; i < largo; i++){
        for (int j = 0; j < largo-i-1; j++){
            if (lista[j] < lista[j+1]){
                int temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
    return  lista;
}

void moviendo(int pisos, int origen, int destino, int aux,  pueblo **town, int modo){
    if (pisos == 1){
        mover_piso(origen, destino, town, modo);
    }else{
        moviendo(pisos - 1, origen, aux, destino, town, modo);
        mover_piso(origen, destino, town, modo);
        moviendo(pisos - 1, aux, destino, origen, town, modo);
    }
}

void print_tower(pueblo *town){
    int max_altura = 0;
    int highest_town = 0;

    for (int h = 0; h < 3; h++){
        max_altura = (town[h].altura > max_altura)? town[h].altura: max_altura;
        highest_town = (town[h].altura == max_altura) ? town[h].num_pueblo: highest_town;
    }

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
int total_mov(int pisos){
    return pow(2,pisos)-1;
}
#endif