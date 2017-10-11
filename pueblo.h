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
void mover_piso(int origen, int destino, pueblo **pueblos);
piso* pop(piso** p);
void push(piso** pila, piso *aux);
int* crear_diametros(int largo);
int *ordenar_lista(int *lista, int largo);


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

void mover_piso(int origen, int destino, pueblo **pueblos){
    piso *aux = pop(&((*pueblos)[origen-1].comienzo));
    (*pueblos)[origen-1].altura--;
    push(&((*pueblos)[destino-1].comienzo), aux);
    (*pueblos)[destino-1].altura++;
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

#endif