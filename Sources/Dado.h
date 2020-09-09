#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

#include <time.h>
#include <windows.h>

class Dado{

private:
    int caras;

public:
    Dado(int caras = 6);

    int lanzar();

    int getCaras();

};

#endif // DADO_H_INCLUDED
