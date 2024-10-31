#ifndef JOC_H
#define JOC_H
#include "Jugador.h"
#include "Tauler.h"
#include "PilaCartes.h"
#include "Seguidors.h"

class Joc
{
    public:
        Joc(int llavor);
        //Pre:--;Post:donar valor a a_llavor
        int n_jugadors();
        //Pre:--;Post:retorna els jugadors del joc
        void llegir_jugadors(Jugador&j);
        //Pre:--;Post:escriure i guardar els jugadors del joc
        void preparar();
        //Pre:--;Post:preparar joc
        void retirar(Baralla&baralla);
        //Pre:--;Post:retirar cartes de la baralla
        void repartir(Baralla&baralla);
        //Pre:--;Post:repartir les cartes de la baralla als jugadors
        void posar_al_vector(const Jugador&jugador,int k);
        //Pre:--;Post:posar al vector de jugadors el nom del jugador
        void mostrar_jugador_ma(int k);
        //Pre:--;Post:mostrar ma del jugador
        void mostrar_jugador_torn(int k);
        //Pre:--;Post:mostrar el torn del jugador
        void omplir_tauler(Baralla&baralla,Tauler&t);
        //Pre:--;Post:omplir el tauler de les cartes de la baralla
        void omplir_piles(Baralla&baralla,PilaCartes&dreta,PilaCartes&esquerra,int aa);
        //Pre:--;Post:omplir les piles esquerra i dreta de la baralla
        void mostrar_cartes_jugador(int k);
        //Pre:--;Post:mostrar les cartes del jugador de la posicio k
        int get_N_Jug();
        //Pre:--;Post:retorna els jugadors del joc
        void accedir_a_carta_i_colocarla(Carta&ca,int k,int p,int i,int jj);
        //Pre:--;Post:agafar la carta i col·locar-la al tauler
        void mostrar_ma_oponents(int k);
        //Pre:--;Post:mostrar la ma dels oponents
        void robar_carta(int k,int p,char r);
        //Pre:--;Post:robar la carta d'una de les piles
        bool complir_condicions(char m,int jug,int k);
        //Pre:--;Post:retorna true si compleix les condicions
        void omplir_resum_seguidors_jugadors();
        //Pre:--;Post:omplir el resum de tots els seguidors
        void mostrar_resum_seguidors(int k);
        //Pre:--;Post:mostrar el resum dels seguidors
        void cedir_influencia_jugador(char m,int jug,int k);
        //Pre:--;Post:cedir influencia del jugador
        void agafar_cartes_fila_tauler(Carta ca,int i,int jj,int k);
        //Pre:--;Post:agafar les cartes de la fila i del tauler
        void agafar_cartes_columna_tauler(Carta ca,int i,int jj,int k);
        //Pre:--;Post:agafar les cartes de la columna i del tauler
        void crisi_magica(int i,int jj,int k);
        //Pre:--;Post:executar la crisi màgica
        void mostrar_seguidors();
        //Pre:--;Post:mostrar els seguidors
        void puntuacio();
        //Pre:--;Post:muntar la puntuació de cada jugador
        void torn_de_jugador(int&k);
        //Pre:--;Post:executar tota la partida fins la part final
        bool ocupada(int i,int jj);
        //Pre:--;Post:retorna true si la carta del tauler està ocupada
        void afegir_cartes(Carta ca,int k,int i,int jj,char r);
        //Pre:--;Post:afegir cartes si la fila o la columna és igual a 10 o es compleix la crisi màgica
        void mostrar_piles();
        //Pre:--;Post:mostrar les dues piles
        bool piles_buides();
        //Pre:--;Post:retorna true si les piles estan buides
        void passar_cartes_ma_a_seguidors(int l);
        //Pre:--;Post:pasasr les cartes de la ma als seguidors quan tots els jugadors tenen tres cartes
        bool pila_esquerra_buida();
        //Pre:--;Post:retorna true si la pila esquerra està buida
        bool tots_tres_cartes();
        //Pre:--;Post:retorna true si tots els jugadors tenen tres cartes a la ma
        void mostrar_seguidors_final();
        //Pre:--;Post:mostrar tots els seguidors de cada jugador
        bool una_pila_buida();
        //Pre:--;Post:retorna si una de les piles no hi ha cap carta

    private:
        unsigned a_llavor;
        int n_jug;
        Jugador vec_jug[4];
        Tauler t;
        PilaCartes esquerra;
        PilaCartes dreta;
};

#endif // JOC_H
