#include "Jugador.h"
#include <limits>
#include <iostream>
#include <string>
#include "Baralla.h"
#include "Seguidors.h"
using namespace std;

Jugador::Jugador(){

}

Jugador::Jugador(string nom){
    a_nom=nom;
}

void Jugador::llegir_jugador(){
    getline(cin,a_nom);
}

void Jugador::afegir_cartes(Baralla&baralla){
    afegir_carta(baralla);
}

void Jugador::afegir_carta(Baralla&baralla){
    for(int l=0;l<4;l++){
        int i=baralla.getA_N();
        Carta c = baralla.agafa_carta(i);
        afegir_cartes_jugador(c,l);
        baralla.descomptar_a_n();
    }
}

void Jugador::afegir_cartes_jugador(Carta c,int l){
    vec_cartes[l]=c;
}

string Jugador::getNom(){
    return a_nom;
}

void Jugador::mostrar_carta(int s){
    vec_cartes[s].mostrar();
}

void Jugador::mostrar_magia(int j){
    vec_cartes[j].mostrar_magia();
}

void Jugador::agafar_carta(Carta&ca,int p){
    ca=vec_cartes[p];
    vec_cartes[p].eliminar_carta();
}

void Jugador::agafar_carta_pila(Carta ca,int p){
    vec_cartes[p]=ca;
}

void Jugador::omplir_resum_seguidors(){
    for(int i=0;i<6;i++){
        Carta ca(i);
        vec_seg[i]=ca;
    }
}

void Jugador::mostrar_resum_seguidors(){
    for(int i=0;i<6;i++){
        int infl=vec_seg[i].get_influencia();
        if(infl<=0) vec_seg[i].mmostrar_seguidor();
        else if(infl>0 and infl<10) vec_seg[i].mostrar_seguidor();
        else vec_seg[i].mmmostrar_seguidor();
    }
}

void Jugador::mostrar_seguidors(){
    a_seguidor.mostrar();
}

bool Jugador::tenir_seg(char m){
    bool complir=false;
    int i=0;
    while(i<6 and not complir){
        if(vec_seg[i].get_magia()==m and vec_seg[i].get_influencia()!=0) complir=true;
        else i++;
    }
    return complir;
}

void Jugador::buscar_m(char m,int&j,int&num){
    bool trobat=false;
    while(not trobat){
        if(vec_seg[j].get_magia()==m){
            trobat=true;
            num=vec_seg[j].get_influencia();
            vec_seg[j].buidar_influencia();
        }
        else j++;
    }
}

void Jugador::cedir_influencies(int j,int num){
    vec_seg[j].canviar_influencia(num);
}

void Jugador::inserir_a_seguidors(Carta c){
    a_seguidor.inserir(c);
}

void Jugador::afegir_resum_seguidors(Carta cb){
    bool trobat=false;
    int i=0;
    while(not trobat){
        if(vec_seg[i].get_magia()==cb.get_magia()){
            trobat=true;
            vec_seg[i].sumar_influencia(cb);
        }
            else i++;
    }
}

void Jugador::buscar_carta_seguidor(char m,Carta&ca,bool&trobat,bool&acabar){
    a_seguidor.buscar_carta(m,ca,trobat,acabar);
    if(trobat)a_seguidor.eliminar(ca);
}

int Jugador::get_puntuacio_de_una_magia(int j){
    return vec_seg[j].get_influencia();
}

void Jugador::passar_a_seguidors(){
    Carta cb;
    for(int v=0;v<4;v++){
        if(not vec_cartes[v].no_magia()){
            cb=vec_cartes[v];
            a_seguidor.inserir(cb);
            int w=0;
            bool trobat=false;
            while(w<6 and not trobat){
                if(vec_seg[w].igual_magia(cb)){
                    vec_seg[w].sumar_influencia(cb);
                    trobat=true;
                }
                else w++;
            }
        }

    }
}

int Jugador::n_cartes(){
    int compt=0;
    for(int i=0;i<4;i++){
        if(vec_cartes[i].get_influencia()!=0) compt++;
    }
    return compt;
}
