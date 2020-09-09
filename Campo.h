#ifndef CAMPO_H_INCLUDED
#define CAMPO_H_INCLUDED
#include <iostream>
#include "Casillero.h"
#include "Jugador.h"

class Campo{

private:

    unsigned int tamanioCampo;
    ListaSE<ListaSE<Casillero*>*>* casilleros;

public:

    Campo(int tamanioCampo);
    ~Campo();
    Casillero* obtenerCasillero(Posicion pos);
    unsigned int conocerTamanio();
    ListaSE<Tropa*> verificarObjetivo(Tropa* tropa);
    ListaSE<Posicion> verificarMovimientos(Tropa* tropa);
    void moverTropa(Tropa* tropa, Posicion posObjetivo);
    Cursor<ListaSE<Casillero*>*>* conocerCursor();
    void revivirTropa(Jugador* jugador, Posicion pos);
    void spawnearTropa(Tropa* tropa, Posicion posObjetivo);
    void despawnearTrop(Tropa* tropa);
};

#endif // CAMPO_H_INCLUDED
