#ifndef SEGUIDORS_H
#define SEGUIDORS_H
#include "Carta.h"
using namespace std;

class Seguidors {
    public:
        Seguidors();
        // Pre:--; Post: llista buida
        Seguidors(const Seguidors &s);
        // Pre:--; Post: la llista es c�pia de s
        ~Seguidors();
        // Pre: --; Post: mem�ria din�mica alliberada
        Seguidors &operator=(const Seguidors &s);
        // Pre:--; Post: aquesta llista es copia de s i abans s'ha alliberat la mem�ria ocupada per aquesta llista
        bool buida() const;
        // Pre:--; Post: ens diu si la llista es buida
        void mostrar() const;
        // Pre:--; Post: mostra la llista
        bool existeix(Carta c) const;
        // Pre:--; Post: ens diu si c existeix a la llista
        void inserir (Carta c);
        // Pre: --; Post: si c no existeix s'ha inserit en el lloc que li toca per mantenir l'ordre; en cas contrari no es fa cap inserci�
        void eliminar (Carta c);
        // Pre:--; Post: c s'ha esborrat en el cas que exist�s; en cas contrari no es fa res
        void buscar_carta(char m,Carta&ca,bool&trobat,bool&acabar);
        // Pre:--; Post: buscar la primera carta ca de la llista amb la m�gia m
    private:
        struct Node {
            Carta dada;
            Node *seg;
        };
        Node *a_inici;
        void copia(const Seguidors &s);
        // Pre: mem�ria din�mica alliberada; Post: aquesta llista es c�pia de s
        void allibera();
        // Pre: --; Post: mem�ria din�mica alliberada
};
#endif //SEGUIDORS_H
