#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include "Baralla.h"
#include "Seguidors.h"
using namespace std;

class Jugador
{
    public:
        Jugador();
        //Pre:--;//Post:--
        Jugador(string nom);
        //Pre:--;//Post:donar valor a a_nom
        void llegir_jugador();
        //Pre:--;//Post:llegir un jugador
        void afegir_cartes(Baralla&baralla);
        //Pre:--;//Post:afegir cartes de la baralla a cada jugador
        void afegir_carta(Baralla&baralla);
        //Pre:--;//Post:afegir carta de la baralla
        void afegir_cartes_jugador(Carta c,int l);
        //Pre:--;//Post:afegir cartes a un jugador
        string getNom();
        //Pre:--;//Post:retorna a_nom
        void mostrar_carta(int s);
        //Pre:--;//Post:mostrar la carta
        void mostrar_magia(int j);
        //Pre:--;//Post:mostrar la màgia de la carta
        void agafar_carta(Carta&ca,int p);
        //Pre:--;//Post:agafar la carta
        void agafar_carta_pila(Carta ca,int p);
        //Pre:--;//Post:agafar la carta de la pila
        void omplir_resum_seguidors();
        //Pre:--;//Post:mplir el resum dels seguidors
        void mostrar_resum_seguidors();
        //Pre:--;//Post:mostrar el resum dels seguidors
        void mostrar_seguidors();
        //Pre:--;//Post:mostrar els seguidors
        bool tenir_seg(char m);
        //Pre:--;//Post:retorna true si té seguidors de la màgia m
        void buscar_m(char m,int&j,int&num);
        //Pre:--;//Post:buscar la màgia m al resum dels seguidors
        void cedir_influencies(int j,int num);
        //Pre:--;//Post:cedir influències
        void inserir_a_seguidors(Carta c);
        //Pre:--;//Post:inserir c a seguidors d'un jugador
        void buscar_carta_seguidor(char m,Carta&c,bool&trobat,bool&acabar);
        //Pre:--;//Post:buscar c als seguidors d'un jugador
        void afegir_resum_seguidors(Carta cb);
        //Pre:--;//Post:afegir la inflúencia de cb a seguidor d'un jugador
        int get_puntuacio_de_una_magia(int j);
        //Pre:--;//Post:retorna la puntuacio d'una màgia
        void passar_a_seguidors();
        //Pre:--;//Post:passar a seguidors
        int n_cartes();
        //Pre:--;//Post:retorna el número de cartes de la ma d'un jugador

    private:
        string a_nom;
        int jug_afegir;
        Carta vec_cartes[4];
        Carta vec_seg[6];
        Seguidors a_seguidor;
};

#endif // JUGADOR_H
