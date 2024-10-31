#include "Carta.h"
using namespace std;

const char Carta::v_magia[]={'b','o','p','r','t','v'};
const char Carta::v_influencia[]={1,2,3,4,5};
const char Carta::v_germandat[]={'c','g','s'};

Carta::Carta(){
    magia = ' ';
    influencia = 0;
    germandat = ' ';
}

Carta::Carta(int i, int j, int k){
    magia = v_magia[i];
    influencia = v_influencia[j];
    germandat = v_germandat[k];
}

Carta::Carta(int i){
    magia = v_magia[i];
    influencia = 0;
    germandat = ' ';
}

char Carta::agafar_magia(int i){
    return v_magia[i];
}

Carta::Carta(const Carta&c){
    magia = c.magia;
    influencia = c.influencia;
    germandat = c.germandat;
}

Carta::~Carta() {}

char Carta::get_magia() const{
    return magia;
}

int Carta::get_influencia() const{
    return influencia;
}

char Carta::get_germandat() const{
    return germandat;
}

bool Carta::es_buida() const{
    return influencia==0;
}

void Carta::mostrar() const{
    cout << "[" << magia << influencia << germandat << "]";
}

void Carta::mostrar_magia() const{
    cout << "[" << magia << "]";
}

void Carta::mostrar_seguidor() const{
    cout << "[" << germandat << influencia << magia << "]";
}

void Carta::mmostrar_seguidor() const{
    cout << "[" << germandat << " " << magia << "]";
}

void Carta::mmmostrar_seguidor() const{
    cout << "[" << influencia << magia << "]";
}

void Carta::eliminar_carta_tauler(){
    magia=' ';
    influencia=0;
    germandat=' ';
}

bool Carta::igual_o_superior(Carta c){
    return magia>=c.magia;
}

bool Carta::igual_magia(Carta c){
    return magia==c.magia;
}

bool Carta::no_magia(){
    return influencia==0;
}

void Carta::canviar_influencia(int num){
    influencia=num;
}

void Carta::buidar_influencia(){
    influencia=0;
}

bool Carta::mateixa_magia(char m){
    return magia==m;
}

bool Carta::magia_superior(char m){
    return m<magia;
}

bool Carta::inferior_influencia(Carta c){
    return influencia<c.influencia;
}

bool Carta::superior_influencia(Carta c){
    return influencia>c.influencia;
}

bool Carta::igual_influencia(Carta c){
    return influencia==c.influencia;
}

bool Carta::inferior_germandat(Carta c){
    return germandat<c.germandat;
}

bool Carta::superior_germandat(Carta c){
    return germandat>c.germandat;
}

bool Carta::igual_germandat(Carta c){
    return germandat>c.germandat;
}

void Carta::sumar_influencia(Carta cb){
    influencia=influencia+cb.get_influencia();
}

void Carta::eliminar_carta(){
    magia=' ';
    influencia=0;
    germandat=' ';
}

bool Carta::dada_igual(Carta c){
    bool trobat=false;
    if(magia==c.magia and influencia==c.influencia and germandat==c.germandat) trobat=true;

    return trobat;
}

bool Carta::igual_o_superior_seguidors(Carta c){
    bool trobat=false;

    if(magia>c.magia) trobat=true;
    else if(magia==c.magia){
        if(influencia>c.influencia) trobat=true;
        else if(influencia==c.influencia){
            if(germandat>=c.germandat) trobat=true;
        }
    }

    return trobat;
}

void Carta::agafar_carta_seguidors(char m,bool&trobat,bool&acabar){
    if(m==magia) trobat=true;
    else if(m<magia) acabar=true;
}
