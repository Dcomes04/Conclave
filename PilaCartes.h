#ifndef PILACARTES_H
#define PILACARTES_H
#include "Carta.h"

class PilaCartes{
    public:
        PilaCartes();
        // Pre: --; Post: pila buida
        PilaCartes(const PilaCartes& o);
        // Pre: --; Post: aquesta pila es copia de la pila o
        ~PilaCartes();
        // Pre: --; Post: memoria alliberada (inclosa la din�mica)
        bool buida() const;
        // Pre: -- ; Post: retorna cert si la pila es buida; fals en c.c.
        Carta cim() const;
        // Pre: pila no buida; Post: retorna el valor del cim de la pila
        void empila(Carta&p);
        // Pre: --; Post: ha afegit p a dalt de la pila
        void desempila();
        // Pre: pila no buida; Post: ha eliminat element de dalt de la pila
        PilaCartes& operator=(const PilaCartes& o);
        // Pre: -- ; Post: aquesta pila es copia de la pila o i la seva mem��ria din�mica ha estat pr�viament alliberada
        void mostrar()const;
        // Pre: -- ; Post: mostrar la pila de les cartes
        void mostrar_magia()const;
        // Pre: -- ; Post: mostrar la pila de les m�gies de les cartes
        Carta numero_de_cartes_piles();
        // Pre: -- ; Post:et diu el n�mero de cartes de la pila
        void mostrar_cim()const;
        // Pre: -- ; Post:mostra el cim de la pila

    private:
        struct Node{
            Carta valor;
            Node* seg;
        };
        Node* a_cim;
        void copia(const PilaCartes& o);
        // Pre: pila buida; Post: aquesta pila es copia de la pila o
        void allibera();
        // Pre: --; Post: memoria din�mica alliberada
};

#endif // PILACARTES_H
