#ifndef SAMURAI_H_INCLUDED
#define SAMURAI_H_INCLUDED

#include "../Tropa.h"

class Samurai : public Tropa{
private:

    Posicion ultimaPos;

public:

     Samurai(int equipo, int tamanioCampo){
        this->tamanio= tamanioCampo;
        this->equipo = equipo;
        this->vida = 70;
        this->vision = 1;
        this->ultimaPos = pos;
        this->nombre = "Samurai";
    }

    virtual void revivir(){

        this->vida = 70;

    }

    virtual bool atacar(Tropa*  objetivo){
        std::cout<< this->nombre << " ataco a " << objetivo->obtenerNombre() << " por un daño total de " << vida <<std::endl;
        return objetivo->recibirAtaque(this->vida);
    }

    virtual void mover(Posicion nuevaPos){
        this->ultimaPos = pos;
        this->pos = nuevaPos;
    }


    virtual ListaSE<Posicion> movPocibles(){

        ListaSE<Posicion> posiblesPos = ListaSE<Posicion>();


        int a = 1;
        int b = 1;

        for (int i = 0; i < 4; i++){ //Diaglonales

            Posicion auxPos1 = Posicion(this->pos.X + a, this->pos.Y +b);

            if(auxPos1.enRango(this->tamanio)&& !(auxPos1==ultimaPos)){
                posiblesPos.agregar(auxPos1);
            }
            int aux = a;
            a = b;
            b = aux;
            a = a*-1;
       }

       a = 1;
       b =0;

       for (int i = 0; i < 4; i++){ //Rectas

            Posicion auxPos1 = Posicion(this->pos.X + a, this->pos.Y +b);

            if(auxPos1.enRango(this->tamanio)&& !(auxPos1==ultimaPos)){
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

#endif // SAMURAI_H_INCLUDED
