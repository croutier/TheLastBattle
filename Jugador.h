#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "Sources/ListaSE.h"
#include "Sources/Cola.h"
#include "Unidades/Arquero.h"
#include "Unidades/Ballestero.h"
#include "Unidades/Contendiente.h"
#include "Unidades/Enano.h"
#include "Unidades/Guardian.h"
#include "Unidades/Ninja.h"
#include "Unidades/Samurai.h"
#include "Unidades/Vikingo.h"

class Jugador {

private:
    std::string nombre;
    int equipo;
    int tamanioCampo;
    int puntos;
    Cola<Tropa*>* tropasMuertas;
    ListaSE<Tropa*>* tropasActivas;
    ListaSE<Tropa*>* tropasAgotadas;

public:
    Jugador(std::string nombre, int tamanioCampo, int equipo);
    ~Jugador();
    Tropa* obtenerSiguienteTropaActiva();
    void reclutarTropa(int tropa);
    void matarTropa(Tropa* tropa);
    int conocerEquipo();
    void finDeturno();
    int obtenerPuntos();
    bool conocerTropasMuertas();
    void asignarPuntos(int puntos);
    unsigned int conocerTropasRestantes();
    Tropa* revivirTropa();
    std::string conocerNombre();
};


#endif // JUGADOR_H_INCLUDED
