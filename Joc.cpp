#include "Joc.h"
#include "Jugador.h"
#include "Baralla.h"
#include "Tauler.h"
#include "PilaCartes.h"
#include "Seguidors.h"
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

Joc::Joc(int llavor){
    a_llavor=llavor;
}

int Joc::n_jugadors(){
    n_jug=0;
    cout << "ENTRA EL NUMERO DE JUGADORS (2-4):" << endl;
    cin >> n_jug;
    while(n_jug<2 or n_jug>4){
        cout << "NUMERO DE JUGADORS INCORRECTE" << endl;
        cout << "ENTRA EL NUMERO DE JUGADORS (2-4):" << endl;
        cin >> n_jug;
    }
    return n_jug;
}

void Joc::llegir_jugadors(Jugador&j){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int k=0;k<n_jug;k++){
        cout << "ENTRA EL NOM DEL JUGADOR " << k+1 << ":" << endl;
        j.llegir_jugador();
    }
}

void Joc::preparar(){
    Baralla baralla(a_llavor);
    baralla.barrejar();
    retirar(baralla);
    baralla.descomptar_a_n();
    repartir(baralla);
    int aa=baralla.getA_N()-13;
    omplir_piles(baralla,dreta,esquerra,aa);
    omplir_tauler(baralla,t);
}

void Joc::retirar(Baralla&baralla){
    int n=6*4+6*(4-n_jug);
    int treure=90-n;
    for(int k=90;k>treure;k--){
        baralla.descomptar_a_n();
    }
}

void Joc::repartir(Baralla&baralla){
    for(int k=0;k<n_jug;k++){
        vec_jug[k].afegir_cartes(baralla);
    }
    baralla.suma_a_n();
}

void Joc::posar_al_vector(const Jugador&jugador,int k){
    vec_jug[k]=jugador;
}

void Joc::mostrar_jugador_ma(int k){
    cout << "MA DE " << vec_jug[k].getNom() << ":" << endl;
}

void Joc::mostrar_jugador_torn(int k){
    cout << "TORN DE " << vec_jug[k].getNom() << endl;
    string jugador=vec_jug[k].getNom();
    cout << string(8 + jugador.size(), '=') << endl;
}

void Joc::omplir_tauler(Baralla&baralla,Tauler&t){
    baralla.descomptar_a_n();
    for(int s=0;s<12;s++){
        int a=baralla.getA_N();
        Carta c=baralla.agafa_carta(a);
        t.introduir_carta(c);
        baralla.descomptar_a_n();
    }
}

void Joc::omplir_piles(Baralla&baralla,PilaCartes&dreta,PilaCartes&esquerra,int aa){
    int a=aa;
    int b=aa;
    for(int t=0;t<=a;t++){
        Carta c=baralla.agafa_carta(b);
        if(b<=aa/2) dreta.empila(c);
        else esquerra.empila(c);
        b--;
    }
}

void Joc::mostrar_cartes_jugador(int k){
    for(int s=0;s<4;s++){
        cout << s << ":";
        vec_jug[k].mostrar_carta(s);
        cout << " ";
    }
    cout << endl;
}

int Joc::get_N_Jug(){
    return n_jug;
}

void Joc::accedir_a_carta_i_colocarla(Carta&ca,int k,int p,int i,int jj){
    vec_jug[k].agafar_carta(ca,p);
    t.colocar_carta(ca,i,jj);
}

void Joc::mostrar_ma_oponents(int k){
    cout << "MANS DELS OPONENTS:"<< endl;
    for(int i=0;i<n_jug;i++){
        if(i!=k){
            for(int j=0;j<4;j++){
                vec_jug[i].mostrar_magia(j);
                cout << " ";
            }
            cout << i+1 << " " << vec_jug[i].getNom() << endl;
        }
    }
}

void Joc::robar_carta(int k,int p,char r){
    if(r=='e'){
        Carta ca=esquerra.cim();
        vec_jug[k].agafar_carta_pila(ca,p);
        esquerra.desempila();
    }
    else{
        Carta ca=dreta.cim();
        vec_jug[k].agafar_carta_pila(ca,p);
        dreta.desempila();
    }
}

bool Joc::complir_condicions(char m,int jug,int k){
    bool complir=false;
    if((m=='b' or m=='o' or m=='p' or m=='r' or m=='t' or m=='v') and (jug>=1 and jug<=n_jug) and vec_jug[k].tenir_seg(m) and not vec_jug[jug-1].tenir_seg(m)) complir=true;
    return complir;
}

void Joc::omplir_resum_seguidors_jugadors(){
    for(int i=0;i<n_jug;i++){
        vec_jug[i].omplir_resum_seguidors();
    }
}

void Joc::mostrar_resum_seguidors(int k){
    cout << "RESUM DELS SEGUIDORS:" << endl;
    vec_jug[k].mostrar_resum_seguidors();
    cout << " " << k+1 << " " << vec_jug[k].getNom() << endl;

    for(int i=0;i<n_jug;i++){
        if(k!=i){
            vec_jug[i].mostrar_resum_seguidors();
            cout << " " << i+1 << " " << vec_jug[i].getNom() << endl;
        }
    }
}

void Joc::cedir_influencia_jugador(char m,int jug,int k){
    Carta ca;
    int j=0,num=0;
    vec_jug[k].buscar_m(m,j,num);
    vec_jug[jug-1].cedir_influencies(j,num);
    bool trobat=false;
    bool acabar=false;
    while(not acabar){
        trobat=false;
        vec_jug[k].buscar_carta_seguidor(m,ca,trobat,acabar);
        if(trobat){
            vec_jug[jug-1].inserir_a_seguidors(ca);
        }
    }
}

void Joc::agafar_cartes_fila_tauler(Carta ca,int i,int jj,int k){
    Carta cb;
    bool plena=true;
    int j=jj;
    if(jj<=0){
        while(j<4 and plena){
            if(jj!=j){
                if(t.plena(i,j)){
                    if(t.mateixa_magia_fila(ca,i,j) or t.mateixa_germandat_fila(ca,i,j)){
                        t.agafar_carta_tauler(cb,i,j);
                        vec_jug[k].inserir_a_seguidors(cb);
                        vec_jug[k].afegir_resum_seguidors(cb);
                        t.eliminar_de_tauler(i,j);
                    }
                }
                else plena=false;
            }
            j++;
        }
    }

    else if(jj>=3){
        while(j>=0 and plena){
            if(jj!=j){
                if(t.plena(i,j)){
                    if(t.mateixa_magia_fila(ca,i,j) or t.mateixa_germandat_fila(ca,i,j)){
                        t.agafar_carta_tauler(cb,i,j);
                        vec_jug[k].inserir_a_seguidors(cb);
                        vec_jug[k].afegir_resum_seguidors(cb);
                        t.eliminar_de_tauler(i,j);
                    }
                }
                else plena=false;
            }
            j--;
        }
    }

    else{
        if(jj==1){
            if(t.plena(i,0)){
                if(t.mateixa_magia_fila(ca,i,0) or t.mateixa_germandat_fila(ca,i,0)){
                    t.agafar_carta_tauler(cb,i,0);
                    vec_jug[k].inserir_a_seguidors(cb);
                    vec_jug[k].afegir_resum_seguidors(cb);
                    t.eliminar_de_tauler(i,0);
                }
            }
            j=jj+1;
            while(j<4 and plena){
                if(jj!=j){
                    if(t.plena(i,j)){
                        if(t.mateixa_magia_fila(ca,i,j) or t.mateixa_germandat_fila(ca,i,j)){
                            t.agafar_carta_tauler(cb,i,j);
                            vec_jug[k].inserir_a_seguidors(cb);
                            vec_jug[k].afegir_resum_seguidors(cb);
                            t.eliminar_de_tauler(i,j);
                        }
                    }
                    else plena=false;
                }
                j++;
            }
        }

        else{
            while(j>=0 and plena){
                if(jj!=j){
                    if(t.plena(i,j)){
                        if(t.mateixa_magia_fila(ca,i,j) or t.mateixa_germandat_fila(ca,i,j)){
                            t.agafar_carta_tauler(cb,i,j);
                            vec_jug[k].inserir_a_seguidors(cb);
                            vec_jug[k].afegir_resum_seguidors(cb);
                            t.eliminar_de_tauler(i,j);
                        }
                    }
                    else plena=false;
                }
                j--;
            }
            if(t.plena(i,3)){
                if(t.mateixa_magia_fila(ca,i,3) or t.mateixa_germandat_fila(ca,i,3)){
                    t.agafar_carta_tauler(cb,i,3);
                    vec_jug[k].inserir_a_seguidors(cb);
                    vec_jug[k].afegir_resum_seguidors(cb);
                    t.eliminar_de_tauler(i,3);
                }
            }
        }
    }
}

void Joc::agafar_cartes_columna_tauler(Carta ca,int i,int jj,int k){
    Carta cb;
    bool plena=true;
    int ii=i;
    if(i<=0){
        while(ii<4 and plena){
            if(i!=ii){
                if(t.plena(ii,jj)){
                    if(t.mateixa_magia_fila(ca,ii,jj) or t.mateixa_germandat_fila(ca,ii,jj)){
                        t.agafar_carta_tauler(cb,ii,jj);
                        vec_jug[k].inserir_a_seguidors(cb);
                        vec_jug[k].afegir_resum_seguidors(cb);
                        t.eliminar_de_tauler(ii,jj);
                    }
                }
                else plena=false;
            }
            ii++;
        }
    }

    else if(i>=3){
        while(ii>=0 and plena){
            if(i!=ii){
                if(t.plena(ii,jj)){
                    if(t.mateixa_magia_fila(ca,ii,jj) or t.mateixa_germandat_fila(ca,ii,jj)){
                        t.agafar_carta_tauler(cb,ii,jj);
                        vec_jug[k].inserir_a_seguidors(cb);
                        vec_jug[k].afegir_resum_seguidors(cb);
                        t.eliminar_de_tauler(ii,jj);
                    }
                }
                else plena=false;
            }
            ii--;
        }
    }

    else{
        if(i==1){
            if(t.plena(0,jj)){
                if(t.mateixa_magia_fila(ca,0,jj) or t.mateixa_germandat_fila(ca,0,jj)){
                    t.agafar_carta_tauler(cb,0,jj);
                    vec_jug[k].inserir_a_seguidors(cb);
                    vec_jug[k].afegir_resum_seguidors(cb);
                    t.eliminar_de_tauler(0,jj);
                }
            }
            ii=i+1;
            while(ii<4 and plena){
                if(i!=ii){
                    if(t.plena(ii,jj)){
                        if(t.mateixa_magia_fila(ca,ii,jj) or t.mateixa_germandat_fila(ca,ii,jj)){
                            t.agafar_carta_tauler(cb,ii,jj);
                            vec_jug[k].inserir_a_seguidors(cb);
                            vec_jug[k].afegir_resum_seguidors(cb);
                            t.eliminar_de_tauler(ii,jj);
                        }
                    }
                    else plena=false;
                }
                ii++;
            }
        }

        else if(ii==2){
            while(ii>=0 and plena){
                if(i!=ii){
                    if(t.plena(ii,jj)){
                        if(t.mateixa_magia_fila(ca,ii,jj) or t.mateixa_germandat_fila(ca,ii,jj)){
                            t.agafar_carta_tauler(cb,ii,jj);
                            vec_jug[k].inserir_a_seguidors(cb);
                            vec_jug[k].afegir_resum_seguidors(cb);
                            t.eliminar_de_tauler(ii,jj);
                        }
                    }
                    else plena=false;
                }
                ii--;
            }
            if(t.plena(3,jj)){
                if(t.mateixa_magia_fila(ca,3,jj) or t.mateixa_germandat_fila(ca,3,jj)){
                    t.agafar_carta_tauler(cb,3,jj);
                    vec_jug[k].inserir_a_seguidors(cb);
                    vec_jug[k].afegir_resum_seguidors(cb);
                    t.eliminar_de_tauler(3,jj);
                }
            }
        }
    }
}

void Joc::crisi_magica(int i,int jj,int k){
    Carta cb;
    for(int ii=0;ii<4;ii++){
        for(int j=0;j<4;j++){
            if((ii==i and jj!=j) or (jj==j and ii!=i)){
                if(t.diferent_germandat(i,ii,j,jj)){
                    t.agafar_carta_tauler(cb,ii,j);
                    vec_jug[k].inserir_a_seguidors(cb);
                    vec_jug[k].afegir_resum_seguidors(cb);
                    t.eliminar_de_tauler(ii,j);
                }
            }
        }
    }

}

void Joc::mostrar_seguidors(){
    for(int i=0;i<n_jug;i++){
        cout << i+1 << " " << vec_jug[i].getNom() << endl;
        vec_jug[i].mostrar_seguidors();
        cout << endl;
    }
}

void Joc::puntuacio(){
    string guanyador;
    int menys_punts=1000000;
    for(int i=0;i<n_jug;i++){
        int punts_decepcio=0;
        for(int j=0;j<6;j++){
            int jug=0;
            int punts_magia=vec_jug[i].get_puntuacio_de_una_magia(j);
            bool mes_gran=true;
            while(mes_gran and jug<n_jug){
                int punts_rival=0;
                if(i!=jug){
                    punts_rival=vec_jug[jug].get_puntuacio_de_una_magia(j);
                    if(punts_rival>punts_magia) mes_gran=false;
                }
                jug++;
            }
            if(not mes_gran) {
                punts_decepcio=punts_decepcio+punts_magia;
            }
        }
        cout << setfill(' ') << setw(3) << punts_decepcio << " " << vec_jug[i].getNom() << endl;

        if(menys_punts>punts_decepcio){
            menys_punts=punts_decepcio;
            guanyador=vec_jug[i].getNom();
        }
    }
    cout << endl;
    cout << "ENHORABONA " << guanyador << "! HAS GUANYAT LA PARTIDA!" << endl;
}

void Joc::torn_de_jugador(int&k){
    cout << endl;
    mostrar_jugador_torn(k);
    cout << endl;
    t.mostrar(dreta,esquerra);
    cout << endl;
    mostrar_jugador_ma(k);
    mostrar_cartes_jugador(k);
    cout << endl;
    mostrar_ma_oponents(k);
    cout << endl;
    mostrar_resum_seguidors(k);
    cout << endl;
}

bool Joc::ocupada(int i,int jj){
    return t.ocupada(i,jj);
}

void Joc::afegir_cartes(Carta ca,int k,int i,int jj,char r){
    if(t.fila_superior_a_deu(i,jj)){
        agafar_cartes_fila_tauler(ca,i,jj,k);
    }

    if(t.columna_superior_a_deu(i,jj)){
        agafar_cartes_columna_tauler(ca,i,jj,k);
    }

    if(t.tauler_ple()){
        crisi_magica(i,jj,k);
    }
    t.omplir_forats(r,dreta,esquerra);
}

void Joc::mostrar_piles(){
    cout << endl;
    cout << "PILA ESQUERRA:" << endl;
    if(esquerra.buida()) cout << "NO HI HA CAP CARTA" << endl;
    else esquerra.mostrar();
    cout << endl;
    cout << "PILA DRETA:" << endl;
    if(dreta.buida()) cout << "NO HI HA CAP CARTA" << endl;
    else dreta.mostrar();
}

bool Joc::piles_buides(){
    return esquerra.buida() and dreta.buida();
}

void Joc::passar_cartes_ma_a_seguidors(int l){
    vec_jug[l].passar_a_seguidors();
}

bool Joc::pila_esquerra_buida(){
    return esquerra.buida();
}

bool Joc::tots_tres_cartes(){
    bool compleix=false;
    int compt=0;
    for(int i=0;i<n_jug;i++){
        int n=vec_jug[i].n_cartes();
        if(n==3)compt++;
    }
    if(compt==n_jug) compleix=true;

    return compleix;
}

void Joc::mostrar_seguidors_final(){
    cout << endl;
    cout << "RESULTAT FINAL" << endl;
    cout << string(14, '=') << endl;
    cout << endl;
    cout << "TOTS ELS SEGUIDORS:" << endl;
    mostrar_seguidors();
    cout << endl;
    int k=0;
    mostrar_resum_seguidors(k);
    cout << endl;
}

bool Joc::una_pila_buida(){
    return esquerra.buida() or dreta.buida();
}


