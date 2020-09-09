#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED

#include "Unidades/Vacio.h"
class Casillero{

private:
    Tropa* ocupante;
    Posicion pos;

public:
    Casillero(Posicion pos){
        this->ocupante= new Vacio;
        this->pos = pos;
    }
    bool estaOcupada(){
        if (ocupante->obtenerNombre()== "Vacio"){
        }
        return (ocupante->obtenerNombre()!= "Vacio");
    }

    Posicion conocerPos(){
        return this->pos;
    }

    Tropa* conocerOcupante(){

        return this->ocupante;
    }
    void asignarOcupante(Tropa* ocupante){
        if (this->ocupante->obtenerNombre()== "Vacio"){
            ocupante->mover(this->pos);
        }
        this->ocupante=ocupante;
    }

};

#endif // CASILLERO_H_INCLUDED
