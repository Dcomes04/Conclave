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
        // Pre: --; Post: memoria alliberada (inclosa la dinˆmica)
        bool buida() const;
        // Pre: -- ; Post: retorna cert si la pila es buida; fals en c.c.
        Carta cim() const;
        // Pre: pila no buida; Post: retorna el valor del cim de la pila
        void empila(Carta&p);
        // Pre: --; Post: ha afegit p a dalt de la pila
        void desempila();
        // Pre: pila no buida; Post: ha eliminat element de dalt de la pila
        PilaCartes& operator=(const PilaCartes& o);
        // Pre: -- ; Post: aquesta pila es copia de la pila o i la seva mem˜òria dinàmica ha estat prèviament alliberada
        void mostrar()const;
        // Pre: -- ; Post: mostrar la pila de les cartes
        void mostrar_magia()const;
        // Pre: -- ; Post: mostrar la pila de les màgies de les cartes
        Carta numero_de_cartes_piles();
        // Pre: -- ; Post:et diu el número de cartes de la pila
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
        // Pre: --; Post: memoria dinˆmica alliberada
};

#endif // PILACARTES_H
