#include "PilaCartes.h"
#include "Carta.h"
using namespace std;

PilaCartes::PilaCartes() {
    a_cim = NULL;
}

bool PilaCartes::buida() const {
    return a_cim == NULL;
}

Carta PilaCartes::cim() const {
    return a_cim->valor;
}

void PilaCartes::empila(Carta&c){
    Node* nou = new Node;
    nou->valor = c;
    nou->seg = a_cim;
    a_cim = nou;
}

void PilaCartes::desempila(){
    Node* aux = a_cim;
    a_cim = a_cim->seg;
    delete aux;
}

PilaCartes::PilaCartes(const PilaCartes& o) {
    a_cim = NULL;
    copia(o);
}

PilaCartes::~PilaCartes() {
    allibera();
}

PilaCartes& PilaCartes::operator=(const PilaCartes& o) {
    if (this != &o) {
        allibera();
        copia(o);
    }
    return *this;
}

void PilaCartes::allibera() {
    while (!buida()) {
        Node* aux = a_cim;
        a_cim = a_cim->seg;
        delete aux;
    }
}

void PilaCartes::copia(const PilaCartes& o) {
    if (!o.buida()) {
        Node *p, *q, *aux;
        p = new Node;
        a_cim = p;
        aux = o.a_cim;
        p->valor = aux->valor;
        p->seg = NULL;
        q = p;
        aux = aux->seg;
        while (aux!=NULL) {
            p = new Node;
            q->seg = p;
            p->valor = aux->valor;
            p->seg = NULL;
            q = p;
            aux = aux->seg;
        }
    }
}

void PilaCartes::mostrar()const{
    Node*p=a_cim;
    while(p!=NULL){
        p->valor.mostrar_magia();
        cout << " ";
        p=p->seg;
    }
    cout << endl;
}

void PilaCartes::mostrar_magia()const{
    Node*p=a_cim;
    while(p!=NULL){
        p->valor.mostrar_magia();
        p=p->seg;
    }
    cout << endl;
}

void PilaCartes::mostrar_cim()const{
    if(a_cim==NULL) cout << "[ ]";
    else a_cim->valor.mostrar_magia();
}
