#include "Campo.h"


Campo::Campo(int tamanioCampo){

    this->tamanioCampo = tamanioCampo;
    this->casilleros = new ListaSE<ListaSE<Casillero*>*>();
    for(int i = 0; i<tamanioCampo ;i++){

         this->casilleros->agregar(new ListaSE<Casillero*>());
    }

    for(int i = 0; i<tamanioCampo ;i++){
        for(int j = 0; j<tamanioCampo ;j++){
           casilleros->obtenerElemento(i)->agregar(new Casillero(Posicion(i,j)));

        }

    }

}

Campo::~Campo(){
    for(unsigned int i = 0; i< tamanioCampo; i++){

        delete this->casilleros->obtenerElemento(i);

    }
    delete this->casilleros;
}

void Campo::revivirTropa(Jugador* jugador, Posicion pos){
    if (jugador->conocerTropasMuertas()){
        spawnearTropa(jugador->revivirTropa(),pos);
    }

}

Casillero* Campo::obtenerCasillero(Posicion pos){
    return (this->casilleros->obtenerElemento(pos.X))->obtenerElemento(pos.Y);
}

unsigned int Campo::conocerTamanio(){
    return this->tamanioCampo;
}

ListaSE<Tropa*> Campo::verificarObjetivo(Tropa* tropa){

    int rango = tropa->obtenerVision();
    Posicion pos = tropa->obtenerPosicion();
    ListaSE<Posicion> posiblesPos = ListaSE<Posicion>();

    int a;
    int b;

    if(rango>1){
        a = 1;
        b = 1;

        for (int i = 0; i < 4; i++){ //Diaglonales

            Posicion auxPos1 = Posicion(pos.X + a, pos.Y +b);

            if(auxPos1.enRango(this->tamanioCampo)){
                posiblesPos.agregar(auxPos1);
            }
            int aux = a;
            a = b;
            b = aux;
            a = a*-1;
        }
    }
    a = 1;
    b = 0;

    for (int i = 0; i < 4; i++){ //Rectas

        Posicion auxPos1 = Posicion(pos.X + a, pos.Y +b);

        if(rango>1){
            Posicion auxPos2 = Posicion(pos.X + a*rango, pos.Y +b*rango);

            if(auxPos2.enRango(this->tamanioCampo)){
                posiblesPos.agregar(auxPos2);
            }
        }


        if(auxPos1.enRango(this->tamanioCampo)){
            posiblesPos.agregar(auxPos1);
        }

        int aux = a;
        a = b;
        b = aux;
        a = a*-1;
    }
    int equipo=tropa->conocerEquipo();

    ListaSE<Tropa*> objetivosPocibles;
    Cursor<Posicion>* cursor = posiblesPos.conocerCursor();
    cursor->reiniciarCursor();
    while(cursor->avanzarCursor()){
        Casillero* aux = obtenerCasillero(cursor->obtenerCursor());
        if(aux->estaOcupada()){
            if((aux->conocerOcupante()->conocerEquipo())!=equipo){
                objetivosPocibles.agregar(aux->conocerOcupante());
            }
        }
    }
    return objetivosPocibles;
}


ListaSE<Posicion> Campo::verificarMovimientos(Tropa* tropa){
    ListaSE<Posicion> posiblesMov = tropa->movPocibles();
    ListaSE<Posicion> movSeguros;
    Cursor<Posicion>* cursor = posiblesMov.conocerCursor();
    cursor->reiniciarCursor();
    while(cursor->avanzarCursor()){
        Casillero* aux = obtenerCasillero(cursor->obtenerCursor());
        if(!aux->estaOcupada()){
            movSeguros.agregar(cursor->obtenerCursor());
        }
    }
    if (movSeguros.contarElementos()==0){
        movSeguros.agregar(tropa->obtenerPosicion());
    }
    return movSeguros;
}
void Campo::despawnearTrop(Tropa* tropa){

    obtenerCasillero(tropa->obtenerPosicion())->asignarOcupante(new Vacio());

}
void Campo::spawnearTropa(Tropa* tropa, Posicion posObjetivo){
    obtenerCasillero(posObjetivo)->asignarOcupante(tropa);

}
void Campo::moverTropa(Tropa* tropa, Posicion posObjetivo){

      if(posObjetivo == tropa->obtenerPosicion()){

        std::cout<< "El " << tropa->obtenerNombre() << " del equipo  " << tropa->conocerEquipo() << " no se movio este turno"<<std::endl;
     }
     else{
        std::cout<< "El " << tropa->obtenerNombre()<< " del equipo  " << tropa->conocerEquipo() << " se movio a " << posObjetivo.X+1 << "," << posObjetivo.Y+1<<std::endl;
     }

    obtenerCasillero(tropa->obtenerPosicion())->asignarOcupante(new Vacio());
    obtenerCasillero(posObjetivo)->asignarOcupante(tropa);

}

Cursor<ListaSE<Casillero*>*>* Campo::conocerCursor(){
    return this->casilleros->conocerCursor();
}
