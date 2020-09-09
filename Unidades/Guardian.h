#ifndef GUARDIAN_H_INCLUDED
#define GUARDIAN_H_INCLUDED

#include "../Tropa.h"

class Guardian : public Tropa{

public:
    Guardian(int equipo, int tamanioCampo){
        this->tamanio= tamanioCampo;
        this->equipo = equipo;
        this->vida = 100;
        this->danio = 20;
        this->vision = 1;
        this->nombre = "Guardian";
    }

    virtual void revivir(){

        this->vida = 100;
        this->danio = 20;

    }

    virtual bool atacar(Tropa*  objetivo){

        std::cout<< this->nombre << " ataco a " << objetivo->obtenerNombre() << " por un daño total de " << danio <<std::endl;
        this->danio += 10;

        return objetivo->recibirAtaque(this->danio-10);
    }


    virtual ListaSE<Posicion> movPocibles(){

        ListaSE<Posicion> posiblesPos = ListaSE<Posicion>();

        int a = 1;
        int b = 1;

        for (int i = 0; i < 4; i++){
            Posicion auxPos1 = Posicion(this->pos.X + a, this->pos.Y +b*2);
            Posicion auxPos2 = Posicion(this->pos.X + a*2, this->pos.Y +b);
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
#endif // GUARDIAN_H_INCLUDED
