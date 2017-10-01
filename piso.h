#ifndef PISO
#define PISO

typedef struct{
    int diametro;
    struct piso *arriba;
    struct piso *abajo;
}piso;

#endif