#ifndef BALLESTERO_H_INCLUDED
#define BALLESTERO_H_INCLUDED

#include "../Tropa.h"

class Ballestero : public Tropa{
private:
    int numDeAtaques;

public:
     Ballestero(int equipo, int tamanioCampo){
        this->tamanio= tamanioCampo;
        this->equipo = equipo;
        this->numDeAtaques = 0;
        this->vida = 60;
        this->danio = 30;
        this->vision = 2;
        this->nombre = "Ballestero";
    }

    virtual void revivir(){

        this->vida = 60;
        numDeAtaques = 0;
        vision = 2;

    }

    virtual bool atacar(Tropa*  objetivo){

        std::cout<< this->nombre << " ataco a " << objetivo->obtenerNombre() << " por un daño total de " << danio <<std::endl;
        numDeAtaques++;
        if(numDeAtaques>=3){
            this->vision = 1;
        }

        return objetivo->recibirAtaque(this->danio);


    }

    virtual ListaSE<Posicion> movPocibles(){

        ListaSE<Posicion> posiblesPos = ListaSE<Posicion>();

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

#endif // BALLESTERO_H_INCLUDED
