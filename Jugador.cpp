#include "Jugador.h"

Jugador::Jugador(std::string nombre, int tamanioCampo, int equipo){
    this->nombre=nombre;
    this->equipo = equipo;
    this->tamanioCampo = tamanioCampo;
    this->puntos = tamanioCampo*2;
    this->tropasActivas = new ListaSE<Tropa*>();
    this->tropasMuertas = new Cola<Tropa*>();
    this->tropasAgotadas = new ListaSE<Tropa*>();
}

    Jugador::~Jugador(){
        delete this->tropasActivas;
        delete this->tropasMuertas;
        delete this->tropasAgotadas;
    }

    std::string Jugador::conocerNombre(){
        return this->nombre;
    }
    Tropa* Jugador::obtenerSiguienteTropaActiva(){
        //std::cout<< "las tropas activas son "<< conocerTropasRestantes() <<std::endl;
        Tropa* aux = this->tropasActivas->obtenerElemento(0);
        this->tropasActivas->remover(0);
        this->tropasAgotadas->agregar(aux);
        return aux;
    }
    void Jugador::matarTropa(Tropa* tropa){
        int pos = this->tropasActivas->esta(tropa);
        this->tropasMuertas->enqueue(this->tropasActivas->obtenerElemento(pos));
        this->tropasActivas->remover(pos);
        this->puntos--;
        std::cout<< "El " << tropa->obtenerNombre() << " de " << this->nombre << " paso a mejor vida"<< std::endl;
    }
    Tropa* Jugador::revivirTropa(){

                Tropa* jesus = tropasMuertas->dequeue();
                std::cout << "El " << jesus->obtenerNombre() << " de " << nombre << " volvio de entre los muertos" << std::endl;
                jesus->revivir();
                tropasAgotadas->agregar(jesus);
                return jesus;

    }

    bool Jugador::conocerTropasMuertas(){

        return (this->tropasMuertas->contarElementos()>0);

    }

    void Jugador::reclutarTropa(int tropa){

         switch(tropa){

                case 1:
                    this->tropasActivas->agregar(new Arquero(this->equipo,this->tamanioCampo));
                    break;
                case 2:
                    this->tropasActivas->agregar(new Ballestero(this->equipo,this->tamanioCampo));
                    break;
                case 3:
                    this->tropasActivas->agregar(new Contendiente(this->equipo,this->tamanioCampo));
                    break;
                case 4:
                    this->tropasActivas->agregar(new Enano(this->equipo,this->tamanioCampo));
                    break;
                case 5:
                    this->tropasActivas->agregar(new Guardian(this->equipo,this->tamanioCampo));
                    break;
                case 6:
                    this->tropasActivas->agregar(new Ninja(this->equipo,this->tamanioCampo));
                    break;
                case 7:
                    this->tropasActivas->agregar(new Samurai(this->equipo,this->tamanioCampo));
                    break;
                case 8:
                    this->tropasActivas->agregar(new Vikingo(this->equipo,this->tamanioCampo));
                    break;

        }
    }

    void Jugador::finDeturno(){
        //std::cout << "fin de turno, las tropas agotadas son " << tropasAgotadas->contarElementos()<< "y las activas "<< tropasActivas->contarElementos()<< std::endl;
        ListaSE<Tropa*>* aux = this->tropasActivas;
        this->tropasActivas = this->tropasAgotadas;
        this->tropasAgotadas = aux;

    }

    int Jugador::obtenerPuntos(){
        return this->puntos;
    }
    void Jugador::asignarPuntos(int puntos){
        this->puntos-=puntos;
    }

    int Jugador::conocerEquipo(){
        return this->equipo;
        }

    unsigned int Jugador::conocerTropasRestantes(){
        return this->tropasActivas->contarElementos();
    }
