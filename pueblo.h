#ifndef PUEBLO_H
#define PUEBLO_H

#define ANCHO_MAXIMO 24

//Estructura PISO
//Pila con los pisos de la torre
//diametro: ancho del piso
//*abajo: puntero al piso inferior
typedef struct piso{
    int diametro;
    struct piso *abajo;
}piso;

//Estructura pueblo
// num_pueblo: ID del pueblo
// *comienzo: nodo inicial de la pila de discos(si tiene)
// altura: altura en numero de pisos de la torre del pueblo
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
void push(piso** pila, piso **aux);
int* crear_diametros(int largo);
int *ordenar_lista(int *lista, int largo);
void moviendo(int pisos, int origen, int destino, int aux,  pueblo **town, int modo);
void print_tower(pueblo *town);
void print_tower_char(pueblo *town);


//---------------------
//DECLARACION FUNCIONES
//---------------------

//Array de pueblos
//Si el numero del origen coincide con el pueblo entonces
//se creara el pueblo con la torre.
pueblo *crear_pueblos(int altura, int origen){
    pueblo *p = (pueblo*)malloc(sizeof(pueblo)*3);
    for(int i = 0; i < 3; i++){
        p[i] = (i == origen-1)? crear_pueblo(altura, origen): crear_pueblo(0,i+1);
    }
    return p;
}

//Crea un pueblo con un numero de discos y se le asigna un numero de ID
//1 para el primer pueblo
//2 para el segundo
//3 para el tercero
pueblo crear_pueblo(int altura, int numero){
    pueblo town;
    town.num_pueblo = numero;
    town.altura = altura;
    town.comienzo = NULL;
    int *diametros = crear_diametros(altura);
    for (int i = 0; i < altura; i++){
        town.comienzo = crear_piso(town.comienzo, diametros[i]);
    }
    return town;
}

//crea un nuevo piso dado el puntero del inicio de la pila y el diametro del nuevo piso
//Retorna el nuevo inicio de la pila de pisos
piso* crear_piso(piso* start, int d){
    piso *p = (piso*)malloc(sizeof(piso));
    p->diametro = d;
    p->abajo = start;
    return p;
}

//Mueve un piso de la torre desde un pueblo de origen a un pueblo destino
//Si el modo ingresado es distinto de cero se esperara a presionar
//una tecla para imprimir el estado actual de la origen
void mover_piso(int origen, int destino, pueblo **pueblos, int modo){ 
    piso *aux = pop(&((*pueblos)[origen-1].comienzo));
    (*pueblos)[origen-1].altura--;
    push(&((*pueblos)[destino-1].comienzo), &aux);
    (*pueblos)[destino-1].altura++;

    if (modo != 0){
        printf("Presione [enter] para ver el siguiente paso....");
        getchar();
        print_tower_char(*pueblos);
    }
}

piso* pop(piso **p){
    piso *temp = *p;
    *p = (*p)->abajo;
    return temp;
}

void push(piso** pila, piso **aux){
    (*aux)->abajo = *pila;
    *pila = (*aux);
}

//Crea un arreglo de enteros con diferentes tamaños
//Retorna el arreglo ordenado
int *crear_diametros(int largo){
    int *diametros = (int*)malloc(sizeof(int)*largo);
    for (int i = 0; i < largo; i++){
        diametros[i] = (rand()&23)+1;
    }
    return ordenar_lista(diametros, largo);
}

//Ordena un arreglo de mayor a menor
//Retorna el arreglo ordenado
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

//Metodo recursivo que mueve una torre de un pueblo a otro dado el numero de pisos
//el pueblo de origen, destino y un pueblo auxiliar, el arreblo de pueblos y el modo
void moviendo(int pisos, int origen, int destino, int aux,  pueblo **town, int modo){
    if (pisos == 1){
        mover_piso(origen, destino, town, modo);
    }else{
        moviendo(pisos - 1, origen, aux, destino, town, modo);
        mover_piso(origen, destino, town, modo);
        moviendo(pisos - 1, aux, destino, origen, town, modo);
    }
}

//Imprime en pantalla el arreglo de pueblos con la o las torres
//Los pisos de la torre son impresos con el diametro al centro
void print_tower(pueblo *town){
    int max_altura = 0;
    int highest_town = 0;

    for (int h = 0; h < 3; h++){
        max_altura = (town[h].altura > max_altura)? town[h].altura: max_altura;
    }

    char buf[100] = "";

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

//Imprime el arreglo de pueblos y sus torres
//Los pisos de las torres son impresos con el caracter '*' diametro-veces
void print_tower_char(pueblo *town){
    int max_altura = 0;

    for (int h = 0; h < 3; h++){
        max_altura = (town[h].altura > max_altura)? town[h].altura: max_altura;
    }

    for(int level = max_altura; level > 0; level--){    
        for (int t = 0; t < 3; t++){
            char buf[512] = "";
            if (town[t].altura >= level){
                piso *temp = town[t].comienzo;
                for (int s = town[t].altura ; s >level; s--){
                    temp = temp->abajo;
                }
                
                for (int a = 0; a < 24; a++){
                    int spaces = 24 - (*temp).diametro;
                    if(a <= spaces/2 || a > ((*temp).diametro)+spaces/2){
                        strcat(buf," ");
                    }else{
                        strcat(buf,"*");
                    }
                }
                
            }else{
                for (int a = 0; a < 24; a++){
                    strcat(buf," ");
                }
            }
            printf("%s\t",buf);
        }
        printf("\n");
    }

    for (int j = 0; j < 3; j++){
        printf("\tpueblo %i\t\t",town[j].num_pueblo);
    }
    printf("\n");
}

//Calcula el numero de movimientos necesarios para mover una torre
//de un pueblo a otro dado el numero de pisos inicial
int total_mov(int pisos){
    return pow(2,pisos)-1;
}

#endif