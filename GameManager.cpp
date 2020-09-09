#include "GameManager.h"




GameManager::GameManager(){
    this->miCampo = NULL;
    this->jugador1=NULL;
    this->jugador2=NULL;
    this->dado = NULL;
    this->tamanioCampo = 0;
}
GameManager::~GameManager(){

    delete this->miCampo;
    delete this->jugador1;
    delete this->jugador2;
    delete this->dado;

}

void GameManager::jugar(){

    gotoxy(50,2);
    cout<< "Bienvenido a THE LAST BATTLE";
    gotoxy(0,6);
    seleccionarModo();
    seleccionarCampo();
    cargarJugadores();
    draftearTropas(jugador1);
    draftearTropas(jugador2);
    colocarTropas();
    bool j1SigueEnPie = true;
    bool j2SigueEnPie = true;

    while(j1SigueEnPie && j2SigueEnPie){

        j2SigueEnPie = turno(jugador1,jugador2);
        if (j2SigueEnPie){
            j1SigueEnPie = turno(jugador2,jugador1);
        }
    }
    system("cls");
    gotoxy(40,5);
    if(j1SigueEnPie){
        cout<<"Felicitaciones " << jugador1->conocerNombre() << " eres el vencedor de THE LAST BATTLE";
    }
    else{

        cout<<"Felicitaciones " << jugador2->conocerNombre() << " eres el vencedor de THE LAST BATTLE";

    }
}

void GameManager::seleccionarModo(){

    cout<< "Seleccione el modo de juego con el pad numerico"<<endl<<endl;

    cout<< "   presione 1 para Death Match (el primer jugador que se quede sin tropas pierde)"<< endl;
    cout<< "   presione 2 para Combate Por Puntos (las unidades reviven cada turno pero se pierde puntos cada vez que una unidad muere, el primero en llegar a 0 pierde"<< endl;

    int ingreso= 0;
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

    while (ingreso < 1 || ingreso > 2){

        ingreso = (getch() - 48);

    }
    if (ingreso == 1){
        this->modoDeJuego = DM;
        cout<< "Modo Death Match seleccionado"<<endl;
    }
    else{
        this->modoDeJuego = BPP;
        cout<< "Modo Combate Por Puntos seleccionado"<<endl;
    }
    reloj->contar(2);
}
void GameManager::seleccionarCampo(){

    system("cls");
    gotoxy(0,3);
    cout<< "Seleccione el tama�o del campo con el pad numerico" <<endl<<endl;
    cout<< "  presione 1 para mapa Chico   ( 8x8 )"<<endl;
    cout<< "  presione 2 para mapa Mediano ( 10x10 )"<<endl;
    cout<< "  presione 3 para mapa Grande  ( 12x12 )"<<endl;


    int ingreso= 0;
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

    while (ingreso < 1 || ingreso > 3){

        ingreso = (getch() - 48);

    }
     if (ingreso == 1){
        this->tamanioCampo = 8;
        cout<< "Mapa Chico seleccionado"<<endl;
    }
    else if (ingreso == 2){

        this->tamanioCampo = 10;
        cout << "Mapa Mediano seleccionado"<<endl;

    }
    else{

        this->tamanioCampo = 12;
        cout<< "Mapa Grande seleccionado"<< endl;

    }
    miCampo = new Campo(tamanioCampo);
    reloj->contar(2);


}


void GameManager::cargarJugadores(){
    delete this->dado;
    dado = new Dado(2);
    string nombre1;
    string nombre2;
    system("cls");
    gotoxy(0,3);
    cout<< "Jugador 1 ingrese su nombre, el orden en que se ingresen es indifrente, el jugador que empezara se elegira aleatoriamente"<< endl;

    cin>>nombre1;
    cout<< "Jugadro 2 ingrese su nombre"<< endl;
    cin>>nombre2;

    if(dado->lanzar()==1){
        jugador1 = new Jugador(nombre1,tamanioCampo,1);
        jugador2 = new Jugador(nombre2,tamanioCampo,2);
    }
    else{
        jugador2 = new Jugador(nombre1,tamanioCampo,2);
        jugador1 = new Jugador(nombre2,tamanioCampo,1);
    }
    cout<<endl<<endl;
    cout<< "Felicitaciones " << jugador1->conocerNombre() << ", tu comienzas"<< endl;
    reloj->contar(2);

}



void GameManager::colocarTropas(){
    Posicion pos;
    pos.X=0;
    for(int i = 0; i<tamanioCampo;i++){

        pos.Y=i;
        miCampo->spawnearTropa(jugador1->obtenerSiguienteTropaActiva(),pos);

    }
    jugador1->finDeturno();

    pos.X=tamanioCampo-1;
    for(int i = 0; i<tamanioCampo;i++){

        pos.Y=i;
        miCampo->spawnearTropa(jugador2->obtenerSiguienteTropaActiva(),pos);

    }
    jugador2->finDeturno();


}


 void GameManager::draftearTropas(Jugador* jugador){
    delete this->dado;
    dado=new Dado(8);
    int num1;
    int num2;
    int num3;
    int ingreso;
    int seleccion;
    system("cls");
    gotoxy(0,3);
    cout<< jugador->conocerNombre() << " es tu turno de draftear"<< endl<<endl;

    cout<< "    El drafteo consta de una eleccion entre 3 unidades que se seleccionaran con el pad numerico, piensa bien ya que estas seran tus unidades por el resto de la partida"<<endl;

    for(int i = 0; i<this->tamanioCampo;i++){
        gotoxy(0,7);
        num1=dado->lanzar();
        do{
            num2=dado->lanzar();
        }while(num2 == num1);

        do{
            num3=dado->lanzar();
        }while(num3 == num1 || num3 == num2);

        int n;

        for(int j = 0; j < 3;j++){

            cout<< j+1 << ") ";

            switch(j){

                case 0:
                    n= num1;
                    break;
                case 1:
                    n=num2;
                    break;

                case 2:
                    n=num3;
                    break;
            }
            switch(n){

                case 1:
                    cout<< "Arquero";
                    break;
                case 2:
                    cout<< "Ballestero";
                    break;
                case 3:
                    cout<< "Contendiente";
                    break;
                case 4:
                    cout<< "Enano";
                    break;
                case 5:
                    cout<< "Guardian";
                    break;
                case 6:
                    cout<< "Ninja";
                    break;
                case 7:
                    cout<< "Samurai";
                    break;
                case 8:
                    cout<< "Vikingo";
                    break;

            }

            cout<< "    ";

        }
        cout<< "                                ";

        ingreso= 0;
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

        while (ingreso < 1 || ingreso > 3){

            ingreso = (getch() - 48);

        }
        switch (ingreso){
            case 1:
                seleccion=num1;
                break;
            case 2:
                seleccion=num2;
                break;
            case 3:
                seleccion=num3;
                break;
        }
        jugador->reclutarTropa(seleccion);

    }
    system ("cls");
    gotoxy(0,3);
    cout<< "Draft de "<< jugador->conocerNombre() <<" finalizado";
    reloj->contar(3);


 }





bool GameManager::turno(Jugador* jugador,Jugador* otroJugador){

    int ingreso = 0;


    system("cls");
    imprimirCampo();

    if(modoDeJuego==BPP){
        gotoxy(tamanioCampo*10+2,5);
        std::cout<< "Puntaje actual:";
        gotoxy(tamanioCampo*10+2,6);
        std::cout<<" "<< jugador1->conocerEquipo()<< ":";
        gotoxy(tamanioCampo*10+2,7);
        std::cout<< "    " << jugador1->obtenerPuntos();
        gotoxy(tamanioCampo*10+2,8);
        std::cout<<" "<< jugador2->conocerEquipo()<< ":";
        gotoxy(tamanioCampo*10+2,9);
        std::cout<< "    " << jugador2->obtenerPuntos();
    }

    gotoxy(0, 5*tamanioCampo+2);

    if (this->modoDeJuego == BPP){
            Posicion pos;
            pos.X = (0 + (jugador->conocerEquipo()-1)*(this->tamanioCampo-1));
            pos.Y = pos.X;
            if (!miCampo->obtenerCasillero(pos)->estaOcupada()){
                miCampo->revivirTropa(jugador,pos);
            }
    }

    unsigned int restantes = jugador->conocerTropasRestantes();
    std::cout<< "                                                        Turno de movimientos de "<< jugador->conocerNombre() <<std::endl<<std::endl;

    for(unsigned int i = 0; i<restantes;i++){ //Turno de movimiento

        std::cout<< "Torno de movimiento " << i << ":" << std::endl<<std::endl;

        Tropa* tropaActual = jugador->obtenerSiguienteTropaActiva();

        ListaSE<Posicion> posVerificadas = miCampo->verificarMovimientos(tropaActual);

        miCampo->moverTropa(tropaActual,posVerificadas.obtenerRandom());
        std::cout<<std::endl;

    }

    jugador->finDeturno(); // fin de turno de movimiento

    std::cout<< "                           Fin del turno de movimientos de "<< jugador->conocerNombre()<< " Presione 1,2 o 3 para continuar "<<std::endl;
    reloj->contar(1);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

        while (ingreso < 1 || ingreso > 3){

            ingreso = (getch() - 48);

        }
        ingreso = 0;

    system("cls");
    imprimirCampo();

    if(modoDeJuego==BPP){
        gotoxy(tamanioCampo*10+2,5);
        std::cout<< "Puntaje actual:";
        gotoxy(tamanioCampo*10+2,6);
        std::cout<<" "<< jugador1->conocerEquipo()<< ":";
        gotoxy(tamanioCampo*10+2,7);
        std::cout<< "    " << jugador1->obtenerPuntos();
        gotoxy(tamanioCampo*10+2,8);
        std::cout<<" "<< jugador2->conocerEquipo()<< ":";
        gotoxy(tamanioCampo*10+2,9);
        std::cout<< "    " << jugador2->obtenerPuntos();
    }
    gotoxy(0, 5*tamanioCampo+2);


    std::cout<< "                                                        Turno de ataques de "<< jugador->conocerNombre()<<std::endl<<std::endl;
    restantes = jugador->conocerTropasRestantes();

    for(unsigned int i = 0; i<restantes;i++){//Turno de ataque

        std::cout<< "Torno de movimiento " << i << ":" << std::endl<<std::endl;

        Tropa* tropaAcutal = jugador->obtenerSiguienteTropaActiva();

        ListaSE<Tropa*> objetivos = miCampo->verificarObjetivo(tropaAcutal);

        if (objetivos.contarElementos()>0){

            Tropa* objetivo = objetivos.obtenerRandom();

            if (tropaAcutal->atacar(objetivo)){
                miCampo->despawnearTrop(objetivo);
                otroJugador->matarTropa(objetivo);
            }
        }
        else{
            std::cout<< "Parece que el " << tropaAcutal->obtenerNombre() << " de "<<jugador->conocerNombre()<< " no tiene objetivos para atacar este turno"<<std::endl;
        }
        std::cout<<std::endl;
    }
    jugador->finDeturno(); //Fin de turno de ataque

    std::cout<< "                           Fin del turno de ataques de "<< jugador->conocerNombre()<< " Presione 1,2 o 3 para continuar "<<std::endl;
    reloj->contar(1);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

        while (ingreso < 1 || ingreso > 3){

            ingreso = (getch() - 48);

        }

    if (otroJugador->obtenerPuntos()<=0||otroJugador->conocerTropasRestantes()==0){
        return false;
    }

    return true;
}




 void GameManager::imprimirCampo(){

     for(int i = 0; i<tamanioCampo; i++){

        for (int j = 0; j<tamanioCampo; j++){

            std::cout<< (char)201 << (char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)187;

        }
        std::cout<<std::endl;
        for (int j = 0; j<tamanioCampo; j++){

            std::cout<<(char)186<<"        "<<(char)186;

        }
        std::cout<<std::endl;
        for (int j = 0; j<tamanioCampo; j++){

            std::cout<<(char)186<<"        "<<(char)186;

        }
        std::cout<<std::endl;
        for (int j = 0; j<tamanioCampo; j++){

            std::cout<<(char)186<<"        "<<(char)186;

        }
        std::cout<<std::endl;
        for (int j = 0; j<tamanioCampo; j++){

            std::cout<< (char)200 << (char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)188;

        }
        std::cout<<std::endl;


    }

    Cursor<ListaSE<Casillero*>*>* cursorPrincipal = miCampo->conocerCursor();
    Cursor<Casillero*>* cursorSecundario;

    while(cursorPrincipal->avanzarCursor()){
        cursorSecundario = cursorPrincipal->obtenerCursor()->conocerCursor();

        while(cursorSecundario->avanzarCursor()){
                Casillero* aux = cursorSecundario->obtenerCursor();
            if (aux->estaOcupada()){

                gotoxy(aux->conocerPos().X*10+3,aux->conocerPos().Y*5+1);
                std::cout<< (aux->conocerOcupante()->conocerVida());
                gotoxy(aux->conocerPos().X*10+4,aux->conocerPos().Y*5+2);
                if(aux->conocerOcupante()->conocerEquipo()==1){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                }
                else{
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                }
                std::cout<< (aux->conocerOcupante()->obtenerNombre())[0];

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            }
        }
    }



 }

void GameManager::gotoxy(int x, int y){

    HANDLE miHandle;
    miHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD miCoordenada;
    miCoordenada.X = x;
    miCoordenada.Y = y;
    SetConsoleCursorPosition(miHandle,miCoordenada);
}
