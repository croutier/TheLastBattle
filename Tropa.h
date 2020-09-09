#ifndef TROPA_H_INCLUDED
#define TROPA_H_INCLUDED
#include <iostream>
#include "Sources/ListaSE.h"


struct Posicion {
    Posicion(int coordX = 0, int coordY = 0) : X(coordX), Y(coordY) {};
    int X;
    int Y;


    bool operator== (Posicion otraPos){
        return X == otraPos.X && Y == otraPos.Y;
    }

    bool enRango(int tamanio){
        return X >= 0 && X < tamanio && Y >= 0 && Y < tamanio;
    }
};



class Tropa{

protected:

    int tamanio;
    int equipo;
    int vida;
    int danio;
    int vision;
    int mov;
    std::string nombre;
    Posicion pos;

public:

    virtual bool atacar(Tropa* objetivo) = 0;
    virtual ListaSE<Posicion> movPocibles() = 0;

    virtual void mover(Posicion nuevaPos){
        this->pos = nuevaPos;
    }
    virtual void revivir() = 0;

    bool recibirAtaque(int danio){
        this->vida -= danio;
        if(vida<=0){
            return true;
        }
        return false;
    }
    std::string obtenerNombre(){
        return this->nombre;
    }
    Posicion obtenerPosicion(){
        return this->pos;
    }
    int conocerVida(){
    return this->vida;
    }
    int conocerEquipo(){
        return this->equipo;
    }
    int obtenerVision(){
        return this->vision;
    }
};

#endif // TROPA_H_INCLUDED
