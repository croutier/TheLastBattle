#include "Dado.h"

Dado::Dado(int caras){
    if(caras >= 2){
        this->caras = caras;
    }
    srand(time (NULL));
}

int Dado::lanzar(){
    return (1 + (rand() % this->caras));
}

int Dado::getCaras(){
    return this->caras;
}
