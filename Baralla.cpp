#include "Baralla.h"
#include "Joc.h"
#include "Carta.h"
using namespace std;

Baralla::Baralla(){
    a_n = 0;
    a_max = 90;
    a_llavor=0;
    reserva();
}

Baralla::Baralla(int llavor) {
    a_n = 0;
    a_max = 90;
    a_llavor=llavor;
    reserva();
    while(a_n<a_max){
        for(int i=0; i<6; i++){
            for(int k=0; k<3; k++){
                for(int j=0; j<5; j++){
                    a_t[a_n]=Carta(i,j,k);
                    suma_a_n();
                }
            }
        }
    }
}

Baralla::Baralla(const Baralla &baralla) {
    copia(baralla);
}

Baralla::~Baralla() {
    allibera();
}

Baralla &Baralla::operator=(const Baralla &baralla) {
    if (this != &baralla) {
        allibera();
        copia(baralla);
    }
    return *this;
}

void Baralla::afegir(const Carta &c) {
    if (a_n < a_max)expandeix();
        a_t[a_n] = c;
        a_n++;
}

void Baralla::allibera() {
    delete[] a_t;
}

void Baralla::copia(const Baralla &baralla) {
    a_n = baralla.a_n;
    a_max = baralla.a_max;
    reserva();
    for(int i=0; i<a_n; i++)
        a_t[i] = baralla.a_t[i];
}

void Baralla::reserva() {
    a_t = new Carta[a_max];
}

void Baralla::mostrar()const{
    for(int i=0;i<a_n;i++){
        a_t[i].mostrar();
    }
    if(a_n==0)cout << "NO HI HA CAP CARTA" << endl;
    else cout << endl;
}

void Baralla::barrejar(){
    for(int i=a_max-1; i>0; i--) {
        int pos = aleatori(i+1);
        intercanvi(a_t[pos], a_t[i]);
    }
}

int Baralla::aleatori(int rang){
    a_llavor=1103515245*a_llavor+12345;
    return ((a_llavor/32)%32768)%rang;
}

void Baralla::intercanvi(Carta&a ,Carta&b){
    Carta aux=a;
    a=b;
    b=aux;
}

Carta Baralla::agafa_carta(int i){
    return a_t[i];
}

void Baralla::expandeix() {
    Carta *aux = a_t;
    a_max = 2*a_max;
    reserva();
    for(int i=0; i<a_n; i++)
        a_t[i] = aux[i];
    delete[] aux;
}

void Baralla::descomptar_a_n(){
    a_n--;
}

void Baralla::suma_a_n(){
    a_n++;
}

int Baralla::getA_N()const{
    return a_n;
}
