#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "Cursor.h"

template<class T> class Cola{

private:

    NodoS<T>* frente;

    NodoS<T>* ultimo;

    unsigned int tamanio;

    Cursor<T>* cursor;

public:

    Cola();

    Cola(const Cola<T>& otraCola);

    ~Cola();

    bool estaVacia() const;

    unsigned int contarElementos() const;

    void enqueue(const T& elemento);

    T dequeue(); //elimina el último y lo retorna

    T& next(); //conocer el último

    unsigned int esta(const T& elemento) const;

    T& obtenerElemento(unsigned int posicion) const;

    bool operator== (const Cola<T>& otraCola) const;

    Cursor<T>* conocerCursor() const;

private:

    NodoS<T>* obtenerNodo(unsigned int posicion) const;

};

//IMPLEMENTACIONES

template<class T> Cola<T>::Cola(){

    this->frente = NULL;

    this->ultimo = NULL;

    this->tamanio = 0;

    this->cursor = new Cursor<T>(this->frente);
}

template<class T> Cola<T>::Cola(const Cola<T>& otraCola){

    this->frente = NULL;

    this->ultimo = NULL;

    this->tamanio = 0;

    this->cursor = new Cursor<T>(this->frente);

    Cursor<T>* cursorOtraCola = otraCola.conocerCursor();

    cursorOtraCola->reiniciarCursor();

    while(cursorOtraCola->avanzarCursor()){

        this->enqueue(cursorOtraCola->obtenerCursor());
    }
}

template<class T> Cola<T>::~Cola(){

    while(this->tamanio > 0){

        this->dequeue();
    }

    delete cursor;
}

template<class T> bool Cola<T>::estaVacia() const{

    return (this->tamanio == 0);
}

template<class T> unsigned int Cola<T>::contarElementos() const{

    return this->tamanio;
}

template<class T> void Cola<T>::enqueue(const T& elemento){

    NodoS<T>* aux = new NodoS<T>(elemento);

    if (this->frente == NULL) {

        this->frente = aux;

        this->ultimo = aux;

        delete this->cursor;

        this->cursor = new Cursor<T>(this->frente);
    }

    else {

        this->ultimo->cambiarSiguiente(aux);

        this->ultimo = aux;
    }

    this->tamanio++;
}

template<class T> T Cola<T>::dequeue(){

   if(frente != NULL) {

        T dato = this->frente->obtenerDato();

        NodoS<T>* aElminiar = this->frente;

        this->frente = this->frente->obtenerSiguiente();

        delete aElminiar;

        delete this->cursor;

        this->cursor = new Cursor<T>(this->frente);

        this->tamanio--;

        return dato;
    }

    throw std::out_of_range("Cola vacia");
}

template<class T> T& Cola<T>::next(){

    if(this->frente != NULL){

        return this->frente->obtenerDato();
    }

    throw std::out_of_range("Cola vacia");
}

template<class T> unsigned int Cola<T>::esta(const T& elemento) const{

    this->cursor->reiniciarCursor();

    unsigned int i = 0;

    while(this->cursor->avanzarCursor()){

        if(this->cursor->obtenerCursor() == elemento){

            return i;
        }

        i++;
    }

    return (-1);
}

template<class T> T& Cola<T>::obtenerElemento(unsigned int posicion) const{

    if(posicion < this->tamanio){

        return this->obtenerNodo(posicion)->obtenerDato();
    }

    throw std::invalid_argument("Fuera de Rango");
}

template<class T> bool Cola<T>::operator== (const Cola<T>& otraCola) const{

    if(this->tamanio == otraCola.tamanio){

        Cursor<T>* cursorOtraCola = otraCola.conocerCursor();

        cursorOtraCola->reiniciarCursor();

        this->cursor->reiniciarCursor();

        while(this->cursor->avanzarCursor() && cursorOtraCola->avanzarCursor()){

            if(this->cursor->obtenerCursor() != cursorOtraCola->obtenerCursor()){

                return false;
            }
        }

        return true;
    }

    return false;
}

template<class T> Cursor<T>* Cola<T>::conocerCursor() const{

    return this->cursor;
}

//PRIVADO

template<class T> NodoS<T>* Cola<T>::obtenerNodo(unsigned int posicion) const{

    NodoS<T>* punteroActual = this->frente;

    for(unsigned int i = 0; i < posicion; i++){

        punteroActual = punteroActual->obtenerSiguiente();
    }

    return punteroActual;
}

#endif // COLA_H_INCLUDED
