#ifndef PISO
#define PISO

typedef struct piso{
    int diametro;
    struct piso *arriba;
    struct piso *abajo;
}piso;

#endif