#ifndef VACIO_H_INCLUDED
#define VACIO_H_INCLUDED
#include "../Tropa.h"
class Vacio : public Tropa{
private:


public:
     Vacio(){
        this->nombre = "Vacio";
}
    virtual void revivir(){
    }
    virtual bool atacar(Tropa*  objetivo){
        return false;
    }

    virtual ListaSE<Posicion> movPocibles(){
        ListaSE<Posicion> posiblesPos = ListaSE<Posicion>();
        posiblesPos.agregar(this->pos);
        return posiblesPos;
    }
};


#endif // VACIO_H_INCLUDED
