#include "Timer.h"
#include <iostream>

void Timer::contar(int tiempo, bool imprimir){

        if(imprimir) {
            for(int i = tiempo; i > 0; i--){
                Sleep(1000);
                std::cout << i << std::endl;
            }
        }
        else{
            Sleep(tiempo * 1000);
        }
}
