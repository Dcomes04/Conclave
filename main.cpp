#include <iostream>
#include "Joc.h"
#include <limits>
using namespace std;

void entrada_jugadors(Joc& joc){
    int n_jug=joc.n_jugadors();
    string nom;
    Jugador j(nom);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int k=0;k<n_jug;k++){
        cout << "ENTRA EL NOM DEL JUGADOR " << k+1 << ":" << endl;
        getline(cin,nom);
        Jugador jugador(nom);
        joc.posar_al_vector(jugador,k);
    }
}

void opcions(){
    cout << "OPCIONS:" << endl;
    cout << "(I) FER JUGADA CEDINT INFLUENCIA" << endl;
    cout << "(J) FER JUGADA SENSE CEDIR INFLUENCIA" << endl;
    cout << "(P) MOSTRAR PILES" << endl;
    cout << "(F) ABANDONAR PARTIDA" << endl;
    cout << endl;
    cout << "ENTRA UNA OPCIO:" << endl;
}

void fer_jugada(Joc&j,int&p,int&i,int&jj,char&r){
    cout << "ENTRA LA POSICIO DE LA CARTA QUE VOLS COL.LOCAR:" << endl;
    cin >> p;
    while(p<0 or p>3){
        cout << "POSICIO NO VALIDA" << endl;
        cout << "ENTRA LA POSICIO DE LA CARTA QUE VOLS COL.LOCAR:" << endl;
        cin >> p;
    }

    cout << "ENTRA LA POSICIO DEL TAULER ON VOLS COL.LOCAR LA CARTA:" << endl;
    cin >> i >> jj;
    while(((i<0 or i>3) or (jj<0 or jj>3)) or j.ocupada(i,jj)){
        if((i>=0 and i<=3) and (jj>=0 and jj<=3)){
            if(j.ocupada(i,jj)){
                cout << "JUGADA NO PERMESA" << endl;
                cout << "TORNA A INDICAR LA JUGADA" << endl;
                cout << "ENTRA LA POSICIO DE LA CARTA QUE VOLS COL.LOCAR:" << endl;
                cin >> p;
                while(p<0 or p>3){
                    cout << "POSICIO NO VALIDA" << endl;
                    cout << "ENTRA LA POSICIO DE LA CARTA QUE VOLS COL.LOCAR:" << endl;
                    cin >> p;
                }
            }
        }
        else cout << "POSICIO NO VALIDA" << endl;
        cout << "ENTRA LA POSICIO DEL TAULER ON VOLS COL.LOCAR LA CARTA:" << endl;
        cin >> i >> jj;
    }

    if(not j.una_pila_buida()){
        cout << "DE QUINA PILA VOLS ROBAR LA CARTA? (e/d)" << endl;
        cin >> r;
            while(r!='e' and r!='d'){
            cout << "AQUESTA PILA NO EXISTEIX" << endl;
            cout << "DE QUINA PILA VOLS ROBAR LA CARTA? (e/d)" << endl;
            cin >> r;
            }
    }
    else if(j.pila_esquerra_buida()) r='d';
    else r='e';

}

void sense_cedir_influencia(Joc&j,int k,bool ultim_torn){
    int p, i, jj;
    char r;
    fer_jugada(j,p,i,jj,r);
    Carta ca;
    j.accedir_a_carta_i_colocarla(ca,k,p,i,jj);
    if(not ultim_torn)j.robar_carta(k,p,r);

    j.afegir_cartes(ca,k,i,jj,r);
}

void cedir_influencia(Joc&j,int k,bool ultim_torn){
    cout << "ENTRA LA MAGIA QUE VOLS CEDIR:" << endl;
    char m;
    cin >> m;
    cout << "ENTRA EL JUGADOR A QUI LA VOLS CEDIR:" << endl;
    int jug;
    cin >> jug;
    bool seguir=true;
    bool complir=j.complir_condicions(m,jug,k);
    while(not complir and seguir){
        char opc;
        cout << "MOVIMENT NO VALID" << endl;
        cout << "ENCARA T'INTERESSA CEDIR INFLUENCIA? (s/n)" << endl;
        cin >> opc;
        if(opc=='n') seguir=false;
        else{
            cout << "ENTRA LA MAGIA QUE VOLS CEDIR:" << endl;
            cin >> m;
            cout << "ENTRA EL JUGADOR A QUI LA VOLS CEDIR:" << endl;
            cin >> jug;
            complir=j.complir_condicions(m,jug,k);
        }
    }

    if(complir)j.cedir_influencia_jugador(m,jug,k);
    sense_cedir_influencia(j,k,ultim_torn);
}

void puntuacio(Joc&j){
    cout << "PUNTS DE DECEPCIO:" << endl;
    j.puntuacio();
}

void final_de_partida(Joc&j,int&k){
    bool acabar=false;
    bool ultim_torn=true;
    bool finalitzar=false;
    int n=j.get_N_Jug();
    while(k<n and not acabar and not finalitzar){
        j.torn_de_jugador(k);
        opcions();
        char opc;
        cin >> opc;
        if(opc=='I') cedir_influencia(j,k,ultim_torn);
        else if(opc=='J') sense_cedir_influencia(j,k,ultim_torn);
        else if(opc=='P'){
            j.mostrar_piles();
            k--;
        }
        else if(opc=='F'){
            acabar=true;
            cout << "PARTIDA ABANDONADA" << endl;
        }
        else{
            cout << "OPCIO NO DEFINIDA" << endl;
            k--;
        }

        if(j.tots_tres_cartes()) finalitzar=true;
        else{
            if(k<n-1) k++;
            else k=0;
        }
    }

    if(not acabar){
        for(int l=0;l<n;l++){
            j.passar_cartes_ma_a_seguidors(l);
        }

        j.mostrar_seguidors_final();

        puntuacio(j);
    }
}

void torn_de_jugador(Joc&j,int&k,bool&acabar){
    bool ultim_torn=false;
    int n=j.get_N_Jug();
    j.omplir_resum_seguidors_jugadors();
    k=0;
    acabar=false;
    while(not acabar and not j.piles_buides()){
        j.torn_de_jugador(k);
        opcions();
        char opc;
        cin >> opc;
        if(opc=='I') cedir_influencia(j,k,ultim_torn);
        else if(opc=='J') sense_cedir_influencia(j,k,ultim_torn);
        else if(opc=='P'){
            j.mostrar_piles();
            k--;
        }
        else if(opc=='F'){
            acabar=true;
            cout << "PARTIDA ABANDONADA" << endl;
        }
        else{
            cout << "OPCIO NO DEFINIDA" << endl;
            k--;
        }

        if(k<n-1) k++;
        else k=0;

        if(j.piles_buides()) final_de_partida(j,k);
    }
}

int main(){
	unsigned llavor;

    cout << "ENTRA LA LLAVOR:" << endl;
    cin >> llavor;

    Joc j(llavor);

    entrada_jugadors(j);

    int k=0;
    bool acabar=false;

    j.preparar();

    torn_de_jugador(j,k,acabar);
}
