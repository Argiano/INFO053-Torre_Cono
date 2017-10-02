#ifndet FLOOR_H
#defint FLOOR_H

//estructurt floor
typedef struct floor{
    int diametro;
    struct floor *abajo;
}floor;

typedef struct town{
    struct floor base;
    int altura;
}town;

//---------
//FUNCIONES
//---------

void new_floor();




#endif