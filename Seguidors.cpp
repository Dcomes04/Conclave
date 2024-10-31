#include "Seguidors.h"
#include <iostream>


Seguidors::Seguidors() {
    a_inici = NULL;
}

Seguidors::Seguidors(const Seguidors &s) {
    a_inici = NULL;
    copia(s);
}

bool Seguidors::existeix(Carta c) const {
    Node *p = a_inici;
    bool fiCerca = false;
    bool trobat = false;
    while ((p!=NULL) && (!fiCerca)) {
        if (p->dada.igual_o_superior(c)){
            if (p->dada.igual_o_superior_seguidors(c)){
            fiCerca = true;
            trobat = p->dada.dada_igual(c);
            }
        }
        else{
            p = p->seg;
        }

    }
return trobat;
}

bool Seguidors::buida() const {
    return a_inici == NULL;
}

void Seguidors::mostrar() const {
    Node *p = a_inici;
    if(p==NULL) cout << "NO HI HA CAP CARTA";
    else{
        while (p!= NULL) {
            p->dada.mostrar();
            p = p->seg;
        }
    }
}

void Seguidors::inserir(Carta c) {
    Node *ant, *p, *nou;
    bool fiCerca = false;
    bool trobat = false;
    ant = NULL;
    p = a_inici;
    while((p!=NULL) && (!fiCerca)) {
        if (p->dada.igual_o_superior_seguidors(c)){
            fiCerca = true;
            trobat = p->dada.dada_igual(c);
        }
        else{
            ant = p;
            p = p->seg;
        }
    }
    if (!trobat) {
        nou = new Node;
        nou->dada = c;
        nou->seg = p;
        if (ant == NULL) a_inici = nou;
        else ant->seg = nou;
    }
}

void Seguidors::eliminar(Carta c) {
    Node *ant, *p;
    bool fiCerca = false;
    bool trobat = false;
    ant = NULL;
    p = a_inici;
    while((p!=NULL) && (!fiCerca)) {
        if (p->dada.igual_o_superior_seguidors(c)){
            fiCerca = true;
            trobat = p->dada.dada_igual(c);
        }
        else{
            ant = p;
            p = p->seg;
        }
    }
    if (trobat) {
        if(ant!= NULL) ant->seg = p->seg;
        else a_inici = p->seg;
        delete p;
    }
}

void Seguidors::copia(const Seguidors &s) {
    if(!s.buida()) {
        Node *ant, *p, *q;
        p = s.a_inici;
        q = new Node; a_inici = ant = q;
        q->dada = p->dada; q->seg = NULL;
        p = p->seg;
        while (p != NULL) {
            q = new Node;
            q->dada = p->dada; q->seg = NULL;
            ant->seg = q;
            ant = q;
            p = p->seg;
        }
    }
}

Seguidors::~Seguidors() {
    allibera();
}

void Seguidors::allibera() {
    while (!buida()) {
        Node* aux = a_inici;
        a_inici = a_inici->seg;
        delete aux;
    }
}

Seguidors& Seguidors::operator=(const Seguidors &s) {
    if (this != &s) {
        allibera();
        copia(s);
    }
    return *this;
}

void Seguidors::buscar_carta(char m,Carta&ca,bool&trobat,bool&acabar){
    Node *p = a_inici;
    trobat=false;
    acabar=false;
    if(p==NULL) acabar=true;
    while(not trobat and not acabar){
        p->dada.agafar_carta_seguidors(m,trobat,acabar);
        if(not trobat) p=p->seg;
        else ca=p->dada;
        if(p==NULL) acabar=true;
    }
}
