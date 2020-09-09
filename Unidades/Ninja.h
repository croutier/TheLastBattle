#ifndef NINJA_H_INCLUDED
#define NINJA_H_INCLUDED

#include "../Sources/Dado.h"
#include "../Tropa.h"

class Ninja : public Tropa{
private:

    Dado dado;
public:

     Ninja(int equipo, int tamanioCampo){
        this->tamanio= tamanioCampo;
        this->equipo = equipo;
        this->dado = Dado(4);
        this->vida = 60;
        this->danio = 20;
        this->vision = 1;
        this->nombre = "Ninja";
    }

    virtual void revivir(){

        this->vida = 60;

    }

    virtual bool atacar(Tropa*  objetivo){
            int extra = this->dado.lanzar()*10;
            std::cout<< this->nombre << " ataco a " << objetivo->obtenerNombre() << " por un daño total de " << danio+extra <<std::endl;
            return objetivo->recibirAtaque(this->danio+extra);
    }


    virtual ListaSE<Posicion> movPocibles(){

        ListaSE<Posicion> posiblesPos = ListaSE<Posicion>();

        int a = 1;
        int b = 1;

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


#endif // NINJA_H_INCLUDED
