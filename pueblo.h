#ifndef PUEBLO_H
#define PUEBLO_H

//estructurt PISO
typedef struct piso{
    int diametro;
    struct piso *abajo;
}piso;

typedef struct pueblo{
    struct piso *base;
    int altura;
}pueblo;

//---------
//FUNCIONES
//---------

void new_piso();




#endif