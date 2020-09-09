#ifndef ARQUERO_H_INCLUDED
#define ARQUERO_H_INCLUDED

#include "../Tropa.h"

class Arquero : public Tropa{
private:
    bool ataco;

public:
     Arquero(int equipo, int tamanioCampo){
        this->tamanio= tamanioCampo;
        this->equipo = equipo;
        this->ataco = false;
        this->vida = 40;
        this->danio = 20;
        this->vision = 2;
        this->nombre = "Arquero";
}
    virtual void revivir(){

        this->vida = 40;
        ataco = false;

    }
    virtual bool atacar(Tropa*  objetivo){

        std::cout<< this->nombre << " ataco a " << objetivo->obtenerNombre() << " por un daño total de " << danio <<std::endl;
        this->ataco=true;
        return objetivo->recibirAtaque(this->danio);

    }

    virtual ListaSE<Posicion> movPocibles(){

        ListaSE<Posicion> posiblesPos = ListaSE<Posicion>();

        if (ataco == true){
            posiblesPos.agregar(this->pos);
            return posiblesPos;
            ataco=false;
        }


        int a = 1;
        int b = 1;

        for (int i = 0; i < 4; i++){ //Diaglonales

            Posicion auxPos1 = Posicion(this->pos.X + a, this->pos.Y +b);

            if(auxPos1.enRango(this->tamanio)){
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


#endif // ARQUERO_H_INCLUDED
