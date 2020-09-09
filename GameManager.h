#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED

#include "Jugador.h"
#include "Campo.h"
#include "Sources/Timer.h"
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>

using namespace std;
enum Modo{
DM,
BPP
};



class GameManager{

private:
    int tamanioCampo;
    Timer* reloj;
    Campo* miCampo;
    Jugador* jugador1;
    Jugador* jugador2;
    Modo modoDeJuego;
    Dado* dado;

public:
    GameManager();
    ~GameManager();
    void jugar();

private:
    void cargarJugadores();
    void seleccionarCampo();
    void seleccionarModo();
    void draftearTropas(Jugador* jugador);
    void gotoxy(int x, int y);
    bool turno(Jugador* jugador, Jugador* otroJugador);
    void colocarTropas();
    void imprimirCampo();
};

#endif // GAMEMANAGER_H_INCLUDED
