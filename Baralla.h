#ifndef BARALLA_H
#define BARALLA_H
#include "Carta.h"

class Baralla
{
    public:
        Baralla();
        //Pre: --; Post: aquesta taula és còpia de la taula baralla
        Baralla(int llavor);
        //Pre:--; Post: muntar la baralla de cartes
        Baralla(const Baralla &baralla);
        //Pre: --; Post: memòria alliberada
        ~Baralla();
        //Pre: --; Post: aquesta taula és còpia de la taula baralla
        Baralla &operator=(const Baralla &baralla);
        //Pre: --; Post: p afegit a la taula
        void afegir(const Carta &c);
        //Pre: --; Post: afegir c a la baralla
        void mostrar()const;
        //Pre: --; Post: mostrar la baralla
        void barrejar();
        //Pre: --; Post: barrejar la baralla
        int aleatori(int rang);
        //Pre: --; Post: et retorna un número aleatori
        void intercanvi(Carta&a ,Carta&b);
        //Pre: --; Post:intercanviar dues cartes
        Carta agafa_carta(int i);
        //Pre: --; Post:agafa la carta de la posició i
        void descomptar_a_n();
        //Pre: --; Post:restar un al número de cartes de la baralla
        void suma_a_n();
        //Pre: --; Post:sumar un al número de cartes de la baralla
        int getA_N()const;
        //Pre: --; Post:retorna el valor del número de cartes de la baralla

    private:
        int a_n;
        int a_max;
        Carta *a_t;
        unsigned a_llavor;
        void allibera();
        //Pre: --; Post: memòria alliberada
        void copia(const Baralla &baralla);
        //Pre: --; Post: memòria reservada per a_max Punt2D
        void reserva();
        //Pre: --; Post: la memòria reservada es dobla
        void expandeix();
        //Pre: --; Post: la memòria reservada es dobla
};

#endif // BARALLA_H
