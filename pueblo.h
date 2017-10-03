#ifndef PUEBLO_H
#define PUEBLO_H

//estructurt PISO
typedef struct piso{
    int diametro;
    struct piso *abajo;
}piso;

typedef struct pueblo{
    struct piso *comienzo;
    int altura;
}pueblo;

//---------
//FUNCIONES
//---------

void new_piso();
pueblo* crear_pueblo();



//---------------------
//DECLARACION FUNCIONES
//---------------------

pueblo * crear_pueblo(){
    pueblo *town = (pueblo*)malloc(sizeof(pueblo));
    return town;
}

void crear_piso(int medida){
    piso *p = (*piso)malloc(sizeof(piso));
    p->diametro = medida;
    p->abajo = NULL;
}

#endif
