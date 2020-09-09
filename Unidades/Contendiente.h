#ifndef CONTENDIENTE_H_INCLUDED
#define CONTENDIENTE_H_INCLUDED

#include "../Tropa.h"

class Contendiente : public Tropa{

public:
     Contendiente(int equipo, int tamanioCampo){
        this->tamanio= tamanioCampo;
        this->equipo = equipo;
        this->vida = 80;
        this->danio = 30;
        this->vision = 1;
        this->nombre = "Contendiente";
    }

    virtual bool atacar(Tropa*  objetivo){

        if(this->vida<40){
            std::cout<< this->nombre << " ataco a " << objetivo->obtenerNombre() << " por un daño total de " << danio*2 <<std::endl;
            return objetivo->recibirAtaque(danio*2);
        }
        else{
            std::cout<< this->nombre << " ataco a " << objetivo->obtenerNombre() << " por un daño total de " << danio <<std::endl;
            return objetivo->recibirAtaque(this->danio);
        }
    }

    virtual void revivir(){

        this->vida = 80;

    }


    virtual ListaSE<Posicion> movPocibles(){

        ListaSE<Posicion> posiblesPos = ListaSE<Posicion>();

        int a = 1;
        int b = 0;

        for (int i = 0; i < 4; i++){
            Posicion auxPos1 = Posicion(this->pos.X + a, this->pos.Y +b);
            Posicion auxPos2 = Posicion(this->pos.X + a*2, this->pos.Y +b*2);
            if(auxPos1.enRango(this->tamanio)){
                posiblesPos.agregar(auxPos1);
            }
            if(auxPos2.enRango(this->tamanio)){
                posiblesPos.agregar(auxPos2);
            }

            int aux = a;
            a = b;
            b = aux;
            a = a*-1;
       }
       return posiblesPos;
    }
};

#endif // CONTENDIENTE_H_INCLUDED
