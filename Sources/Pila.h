#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "Cursor.h"

template<class T> class Pila{

private:

    NodoS<T>* tope;

    unsigned int tamanio;

    Cursor<T>* cursor;

public:

    Pila();

    Pila(const Pila<T>& otraPila);

    ~Pila();

    bool estaVacia() const;

    unsigned int contarElementos() const;

    void push(const T& elemento);

    T pop();

    T& top();

    unsigned int esta(const T& elemento) const;

    T& obtenerElemento(unsigned int posicion) const;

    bool operator== (const Pila<T>& otraPila) const;

    void invertir();

    Cursor<T>* conocerCursor() const;

private:

    NodoS<T>* obtenerNodo(unsigned int posicion) const;

};

//IMPLEMENTACIONES

template<class T> Pila<T>::Pila(){

    this->tope = NULL;
    this->tamanio = 0;
    this->cursor = new Cursor<T>(this->tope);
}

template<class T> Pila<T>::Pila(const Pila<T>& otraPila){

    this->tope = NULL;

    this->tamanio = 0;

    this->cursor = new Cursor<T>(this->tope);

    Cursor<T>* cursorOtraPila = otraPila.conocerCursor();

    cursorOtraPila->reiniciarCursor();

    while(cursorOtraPila->avanzarCursor()){

        this->push(cursorOtraPila->obtenerCursor());
    }

    this->invertir();

}

template<class T> Pila<T>::~Pila(){

    while(this->tamanio > 0){

        this->pop();
    }

    delete cursor;
}

template<class T> bool Pila<T>::estaVacia() const{

    return (this->tamanio == 0);
}

template<class T> unsigned int Pila<T>::contarElementos() const{

    return this->tamanio;
}

template<class T> void Pila<T>::push(const T& elemento){

    NodoS<T>* aux = tope;

    this->tope = new NodoS<T>(elemento);

    this->tope->cambiarSiguiente(aux);

    delete this->cursor;

    this->cursor = new Cursor<T>(this->tope);

    this->tamanio++;
}

template<class T> T Pila<T>::pop(){

    if(this->tope != NULL){

        T dato = this->tope->obtenerDato();

        NodoS<T>* nodoEliminar = this->tope;

        this->tope = this->tope->obtenerSiguiente();

        delete nodoEliminar;

        delete this->cursor;

        this->cursor = new Cursor<T>(this->tope);

        this->tamanio--;

        return dato;
    }

    throw std::out_of_range("Pila vacia");
}

template<class T> T& Pila<T>::top(){

    if(this->tope != NULL){

        return this->tope->obtenerDato();
    }

    throw std::out_of_range("Pila vacia");
}

template<class T> unsigned int Pila<T>::esta(const T& elemento) const{

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

template<class T> T& Pila<T>::obtenerElemento(unsigned int posicion) const{

    if(posicion < this->tamanio){

        return this->obtenerNodo(posicion)->obtenerDato();
    }

    throw std::invalid_argument("Fuera de Rango");
}

template<class T> bool Pila<T>::operator== (const Pila<T>& otraPila) const{

    if(this->tamanio == otraPila.tamanio){

        Cursor<T>* cursorOtraPila = otraPila.conocerCursor();

        cursorOtraPila->reiniciarCursor();

        this->cursor->reiniciarCursor();

        while(this->cursor->avanzarCursor() && cursorOtraPila->avanzarCursor()){

            if(this->cursor->obtenerCursor() != cursorOtraPila->obtenerCursor()){

                return false;
            }
        }

        return true;
    }

    return false;
}

template<class T> void Pila<T>::invertir(){

    unsigned int tamanioPila = this->tamanio;

    T* aux = new T[tamanioPila];

    for(unsigned int i = 0; i < tamanioPila; i++){

        aux[i] = this->pop();
    }

    for(unsigned int i = 0; i < tamanioPila; i++){

        this->push(aux[i]);
    }

    delete[] aux;
}

template<class T> Cursor<T>* Pila<T>::conocerCursor() const{

    return this->cursor;
}


//PRIVADO

template<class T> NodoS<T>* Pila<T>::obtenerNodo(unsigned int posicion) const{

    NodoS<T>* punteroActual = this->tope;

    for(unsigned int i = 0; i < posicion; i++){

        punteroActual = punteroActual->obtenerSiguiente();
    }

    return punteroActual;
}

#endif // PILA_H_INCLUDED
