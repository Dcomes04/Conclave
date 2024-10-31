#ifndef TAULER_H
#define TAULER_H
#include "Carta.h"
#include "Baralla.h"
#include "PilaCartes.h"

class Tauler{
    public:
        Tauler();
        //Pre:--; Post: matriu buida
        Tauler(int nf, int nc);
        //Pre: nf>0 i nc>0; Post: objecte vàlid amb memòria reservada
        Tauler(const Tauler &t);
        //Pre:--; Post: informació de t copiada a l’actual
        ~Tauler();
        //Pre:-;- Post: allibera la memòria reservada per l’objecte
        Tauler &operator=(const Tauler &t);
        // Pre: --; Post: s’ha assignat sense aliasing la informació de t a l’objecte actual
        void posarElem(int i, int j, const Carta &c);
        // Pre: --; Post: posar carta a c
        Carta obtElem(int i, int j) const;
        // Pre: --; Post: agafar element de la matriu
        int obtNF()const;
        // Pre: --; Post: retorna nf
        int obtNC()const;
        // Pre: --; Post: retorn nc
        void introduir_carta(const Carta&c);
        // Pre: --; Post: introduir c a tauler
        void mostrar(const PilaCartes&dreta,const PilaCartes&esquerra)const;
        // Pre: --; Post: mostrar pila dreta i esquerra
        void colocar_carta(Carta ca,int i,int jj);
        // Pre: --; Post: col·locar ca al tauler
        void omplir_forats(int r,PilaCartes&dreta,PilaCartes&esquerra);
        // Pre: --; Post: omplir caselles del tauler
        bool ocupada(int i,int jj);
        // Pre: --; Post: retorna true si hi ha carta a tauler
        bool fila_superior_a_deu(int i,int jj);
        // Pre: --; Post: retorna true si la fila i suma 10
        bool columna_superior_a_deu(int i,int jj);
        // Pre: --; Post: retorna true si la columna i suma 10
        bool tauler_ple();
        // Pre: --; Post: retorna true si el tauler està ple
        bool mateixa_magia_fila(Carta ca,int i,int j);
        // Pre: --; Post: retorna true si ca té la mateixa màgia que la carta del tauler en la fila
        bool mateixa_germandat_fila(Carta ca,int i,int j);
        // Pre: --; Post: retorna true si ca té la mateixa germandat que la carta del tauler en la fila
        bool mateixa_magia_columna(Carta ca,int ii,int jj);
        // Pre: --; Post: retorna true si ca té la mateixa màgia que la carta del tauler en la columna
        bool mateixa_germandat_columna(Carta ca,int ii,int jj);
        // Pre: --; Post: retorna true si ca té la mateixa germandat que la carta del tauler en la columna
        void agafar_carta_tauler(Carta&cb,int i,int j);
        // Pre: --; Post:agafar la carta a tauler i posar-la a cb
        bool diferent_germandat(int i,int ii,int j,int jj);
        // Pre: --; Post: retorna true si ca té una diferent germandat que la carta del tauler en la fila
        void eliminar_de_tauler(int i,int j);
        // Pre: --; Post: eliminar carta del tauler
        bool buida(int i,int j);
        // Pre: --; Post: retorna true si la carta de tauler està buida
        bool plena(int i,int j);
        // Pre: --; Post: retorna true si la carta de tauler no està buida

    private:
        void allibera();
        // Pre: --; Post: memòria alliberada
        void reserva();
        // Pre: a_n>0 ^ a_m>0; Post: memòria reservada
        void copia(const Tauler &t);
        // Pre: --; Post: fa un duplicat de la matriu
        int i;
        int j;
        int a_n;
        int a_m;
        Carta**a_mp;
        static const int MIDA_TAULER=4;
};

#endif // TAULER_H
