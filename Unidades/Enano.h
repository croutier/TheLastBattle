#ifndef ENANO_H_INCLUDED
#define ENANO_H_INCLUDED

#include "../Tropa.h"

class Enano : public Tropa{

public:

     Enano(int equipo, int tamanioCampo){
        this->tamanio= tamanioCampo;
        this->equipo = equipo;
        this->vida = 100;
        this->danio = 20;
        this->vision = 1;
        this->nombre = "Enano";
    }
    virtual void revivir(){

        this->vida = 100;

    }

    virtual bool atacar(Tropa*  objetivo){

            std::cout<< this->nombre << " ataco a " << objetivo->obtenerNombre() << " por un daño total de " << danio << " y recupero 20 de salud" <<std::endl;
            this->vida += 20;
            return objetivo->recibirAtaque(this->danio);
    }


    virtual ListaSE<Posicion> movPocibles(){

        ListaSE<Posicion> posiblesPos = ListaSE<Posicion>();

        posiblesPos.agregar(this->pos);

        int a = 1;
        int b = 0;

        for (int i = 0; i < 4; i++){
            Posicion auxPos1 = Posicion(this->pos.X + a, this->pos.Y +b);

            if(auxPos1.enRango(this->tamanio)){
                posiblesPos.agregar(auxPos1);
            }
            int aux = a;
            a = b;
            b = aux;
            a = a*-1;
       }
       return posiblesPos;
    }
};


#endif // ENANO_H_INCLUDED
