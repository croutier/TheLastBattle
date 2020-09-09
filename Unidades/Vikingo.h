#ifndef VIKINGO_H_INCLUDED
#define VIKINGO_H_INCLUDED

#include "../Tropa.h"

class Vikingo : public Tropa{
private:
    int espera;

public:
     Vikingo(int equipo, int tamanioCampo){
        this->tamanio= tamanioCampo;
        this->equipo = equipo;
        this->espera = 0;
        this->vida = 120;
        this->danio = 40;
        this->vision = 1;
        this->nombre = "Vikingo";
    }

    virtual void revivir(){

        this->vida = 120;
        espera = 0;

    }

    virtual bool atacar(Tropa*  objetivo){
        std::cout<< this->nombre << " ataco a " << objetivo->obtenerNombre() << " por un daño total de " << danio << "y perdio 20 puntos de salud" <<std::endl;
        if (this->recibirAtaque(20))
            this->vida = 1;

        return objetivo->recibirAtaque(this->danio);

    }


    virtual ListaSE<Posicion> movPocibles(){

        ListaSE<Posicion> posiblesPos = ListaSE<Posicion>();

        if (this->espera >= 1){

            posiblesPos.agregar(this->pos);
            espera=0;
            return posiblesPos;
        }

        espera ++;

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

#endif // VIKINGO_H_INCLUDED
