#ifndef CARTA_H
#define CARTA_H
#include <iostream>

class Carta {
    public:
        Carta();
        // Pre: --;// Post: Crea una Carta amb valors per defecte.
        Carta(int i, int j, int k);
        // Pre: --;// Post: Crea una Carta amb els valors especificats.
        Carta(int i);
        // Pre: --;// Post: Crea una Carta amb el valor especificat per a l'atribut magia i els altres atributs amb valors per defecte.
        char agafar_magia(int i);
        // Pre: --;// Post: Retorna la magia de la carta en forma de car�cter.
        Carta(const Carta& c);
        // Pre: --;// Post: Crea una nova Carta a partir de la Carta c.
        ~Carta();
        // Pre: --;// Post: Destrueix l'objecte Carta.
        char get_magia() const;
        // Pre: --;// Post: Retorna la magia de la carta en forma de car�cter.
        int get_influencia() const;
        // Pre: --;// Post: Retorna la influ�ncia de la carta.
        char get_germandat() const;
        // Pre: --;// Post: Retorna la germandat de la carta en forma de car�cter.
        bool es_buida() const;
        // Pre: --;// Post: Retorna true si la carta est� buida
        void mostrar() const;
        // Pre: --;// Post:mostrar la carta
        void mostrar_magia() const;
        // Pre: --;// Post:mostrar la magia de la carta
        void mostrar_seguidor() const;
        // Pre: --;// Post:mostrar la carta
        void mmostrar_seguidor() const;
        // Pre: --;// Post:mostrar la carta
        void mmmostrar_seguidor() const;
        // Pre: --;// Post:mostrar la carta
        void eliminar_carta_tauler();
        // Pre: --;// Post:elminiar la carta del tauler
        bool igual_magia(Carta c);
        // Pre: --;// Post:retorna true si la carta t� la mateixa m�gia que c
        bool no_magia();
        // Pre: --;// Post:retorna true si no hi has carta
        void canviar_influencia(int num);
        // Pre: --;// Post:canviar influ�ncia de la carta
        void buidar_influencia();
        // Pre: --;// Post:posar influ�ncia a 0
        bool mateixa_magia(char m);
        // Pre: --;// Post:retorna true si la m�gia de la carta �s m
        bool magia_superior(char m);
        // Pre: --;// Post:retorna true si la m�gia de la carta �s superior a m
        bool inferior_influencia(Carta c);
        // Pre: --;// Post:retorna true si la influ�ncia de la carta �s inferior a la influencia de c
        bool superior_influencia(Carta c);
        // Pre: --;// Post:retorna true si la influ�ncia de la carta �s superior a la influencia de c
        bool igual_influencia(Carta c);
        // Pre: --;// Post:retorna true si la influ�ncia de la carta �s la m�gia de la influencia de c
        bool inferior_germandat(Carta c);
        // Pre: --;// Post:retorna true si la germandat de la carta �s inferior a la germandat de c
        bool superior_germandat(Carta c);
        // Pre: --;// Post:retorna true si la germandat de la carta �s superior a la germandat de c
        bool igual_germandat(Carta c);
        // Pre: --;// Post:retorna true si la germandat de la carta �s igual a la germandat de c
        void sumar_influencia(Carta cb);
        // Pre: --;// Post:sumar la influ�ncia de cb
        void eliminar_carta();
        // Pre: --;// Post:eliminar la carta
        bool dada_igual(Carta c);
        // Pre: --;// Post:retorna true si la carta �s igual a c
        bool igual_o_superior(Carta c);
        // Pre: --;// Post:retorna true si la carta �s igual o superior a c
        bool igual_o_superior_seguidors(Carta c);
        // Pre: --;// Post:retorna true si la carta situada a seguidors �s igual o superior a c
        void agafar_carta_seguidors(char m,bool&trobat,bool&acabar);


    private:
        char magia;
        int influencia;
        char germandat;
        static const char v_magia[];
        static const char v_germandat[];
        static const char v_influencia[];
};

#endif  // CARTA_H
