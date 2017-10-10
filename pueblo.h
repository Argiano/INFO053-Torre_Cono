#ifndef PUEBLO_H
#define PUEBLO_H

//estructuras PISO
typedef struct piso{
    int diametro;
    struct piso *abajo;
}piso;

typedef struct pueblo{
    int num_pueblo;
    struct piso *comienzo;
    struct pueblo *next;
    struct pueblo *prev;
    int altura;
}pueblo;

typedef struct civ{
    struct pueblo pueblos[3];
}civ;

//---------
//FUNCIONES
//---------

void new_piso();
pueblo crear_pueblo(int altura, int numero);
piso *crear_piso(int d);
void mover_piso(int origen, int destino);
civ *crear_civ(int pisos, int origen);



//---------------------
//DECLARACION FUNCIONES
//---------------------

civ *crear_civ(int pisos, int origen){
    civ *c = (civ*)malloc(sizeof(civ));
    return c;
}

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
    int diametro = (rand()&23)+1;
    int comp = diametro;
    town.num_pueblo = numero;
    printf("altura %i \n", altura);
    for (int i = 0; i < altura; i++){
        while (diametro > comp){
            diametro = (rand()&23)+1;
        }
        comp = diametro;
        town.comienzo = crear_piso(diametro);
        diametro = (rand()&23)+1;
        printf("%i\n",town.comienzo->diametro);
    }
    return town;
}

piso* crear_piso(int d){
    piso *p = (piso*)malloc(sizeof(piso));
    p->diametro = d;
    p->abajo = NULL;
    return p;
}
void mover_piso(int origen, int destino){

}
#endif
