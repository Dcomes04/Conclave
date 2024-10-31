#include "Tauler.h"
#include <iomanip>
using namespace std;
Tauler::Tauler() {
    a_n=4; a_m=4; a_mp=NULL;
    i=0; j=0;
    reserva();
}

Tauler::Tauler(int nf, int nc) {
    a_n=nf; a_m=nc;
    i=0; j=0;
    reserva();
}

Tauler::Tauler(const Tauler &t) {
    copia(t);
}

Tauler::~Tauler() {
    allibera();
}

Tauler & Tauler::operator=(const Tauler &t) {
    if(this!=&t){
        allibera();
        copia(t);
    }
    return *this;
}

void Tauler::posarElem(int i, int j, const Carta &c){
    a_mp[i][j] = c;
}

Carta Tauler::obtElem(int i, int j) const{
    return a_mp[i][j];
}

int Tauler::obtNF()const{
     return a_n;
}

int Tauler::obtNC()const{
     return a_m;
}

void Tauler::introduir_carta(const Carta& c){
    if(i<a_n){
        while((i==1 or i==2) and (j==1 or j==2)){
            j++;
            if(j==a_m){
                i++;
                j=0;
            }
        }
        a_mp[i][j]=c;

        j++;
        if(j==a_m){
            i++;
            j=0;
        }
    }
}

void Tauler::mostrar(const PilaCartes&dreta,const PilaCartes&esquerra)const{
    cout << string(5, ' ');
    for (int i = 0; i < MIDA_TAULER; i++) {
            cout << setfill(' ') << setw(6) << i;
    }
    cout << endl;

    for (int i = 0; i < MIDA_TAULER; i++) {
        if (i == 1){
            esquerra.mostrar_cim();
        }
        else cout << "   ";

        cout << setfill(' ') << setw(3) << i << " ";
        for (int j = 0; j < MIDA_TAULER; j++) {
            cout << " ";
            if(a_mp[i][j].get_influencia()==0) cout << "[   ]";
            else a_mp[i][j].mostrar();
        }

        if (i == 1) {
            cout << "  ";
            dreta.mostrar_cim();
        }

        cout << endl;
    }

}

void Tauler::reserva() {
    a_mp = new Carta*[a_n];
    for(int i=0; i<a_n; i++)
    a_mp[i]= new Carta[a_m];
}

void Tauler::copia(const Tauler &t) {
    a_n = t.a_n; a_m = t.a_m;
    reserva();
    for (int i=0; i<a_n; i++){
        for (int j=0; j<a_m; j++){

        }
    }
}

void Tauler::allibera() {
    for(int i=0;i<a_n; i++)
        delete [] a_mp[i];
    delete [] a_mp;
}

void Tauler::colocar_carta(Carta ca,int i,int jj){
    a_mp[i][jj]=ca;
}

void Tauler::omplir_forats(int r,PilaCartes&dreta,PilaCartes&esquerra){
    int compt=0;
    for(int ii=0;ii<MIDA_TAULER;ii++){
        for(int j=0;j<MIDA_TAULER;j++){
            if(a_mp[ii][j].get_influencia()==0) compt++;
        }
    }
    if(compt>4){
        bool omplert=false;
        int ii=0, j=0;
        while(ii<MIDA_TAULER and not omplert){
            while(j<MIDA_TAULER and not omplert){
                if(a_mp[ii][j].get_influencia()==0){
                    if((r=='e' or dreta.buida())and not esquerra.buida()){
                        Carta ca=esquerra.cim();
                        a_mp[ii][j]=ca;
                        esquerra.desempila();
                    }
                    else if((r=='d' or esquerra.buida()) and not dreta.buida()){
                        Carta ca=dreta.cim();
                        a_mp[ii][j]=ca;
                        dreta.desempila();
                    }
                    compt--;
                }
                j++;
                if(compt<=4) omplert=true;
                if(dreta.buida() and esquerra.buida()) omplert=true;
            }
            j=0;
            ii++;
        }
    }
}

bool Tauler::ocupada(int i,int jj){
    return a_mp[i][jj].get_influencia()!=0;
}

bool Tauler::fila_superior_a_deu(int i,int jj){
    bool superior=false;
    int suma=0;
    bool plena=true;

    if(jj<=0){
        int j=0;
        while(j<MIDA_TAULER and plena){
            if(a_mp[i][j].get_influencia()!=0) suma=suma+a_mp[i][j].get_influencia();
            else plena=false;
            j++;
        }
    }
    else if(jj>=3){
        int j=jj;
        while(j>=0 and plena){
            if(a_mp[i][j].get_influencia()!=0) suma=suma+a_mp[i][j].get_influencia();
            else plena=false;
            j--;
        }
    }
    else{
        int j=jj;
        while(j>=0 and plena){
            if(a_mp[i][j].get_influencia()!=0) suma=suma+a_mp[i][j].get_influencia();
            else{
                if(j==1)plena=false;
            }
            j--;
        }
        if(not plena){
            suma=0;
            plena=true;
            j=jj;
        }
        else j=jj+1;

        while(j<MIDA_TAULER and plena){
            if(a_mp[i][j].get_influencia()!=0) suma=suma+a_mp[i][j].get_influencia();
            else{
                plena=false;
            }
            j++;
        }
    }

    if(suma>=10)superior=true;
    return superior;
}

bool Tauler::columna_superior_a_deu(int i,int jj){
    bool superior=false;
    int suma=0;
    bool plena=true;

    if(i<=0){
        int ii=0;
        while(ii<MIDA_TAULER and plena){
            if(a_mp[ii][jj].get_influencia()!=0) suma=suma+a_mp[ii][jj].get_influencia();
            else plena=false;
            ii++;
        }
    }
    else if(i>=3){
        int ii=i;
        while(ii>=0 and plena){
            if(a_mp[ii][jj].get_influencia()!=0) suma=suma+a_mp[ii][jj].get_influencia();
            else plena=false;
            ii--;
        }
    }
    else{
        int ii=i;
        while(ii>=0 and plena){
            if(a_mp[ii][jj].get_influencia()!=0) suma=suma+a_mp[ii][jj].get_influencia();
            else{
                if(ii==1)plena=false;
            }
            ii--;
        }
        if(not plena){
            suma=0;
            plena=true;
            ii=i;
        }
        else ii=i+1;

        while(ii<MIDA_TAULER and plena){
            if(a_mp[ii][jj].get_influencia()!=0) suma=suma+a_mp[ii][jj].get_influencia();
            else{
                plena=false;
            }
            ii++;
        }
    }

    if(suma>=10)superior=true;
    return superior;
}

bool Tauler::tauler_ple(){
    bool ple=false;
    int compt=0;
    for(int i=0;i<MIDA_TAULER;i++){
        for(int j=0;j<MIDA_TAULER;j++){
            if(not a_mp[i][j].es_buida()) compt++;
        }
    }
    if(compt==MIDA_TAULER*MIDA_TAULER){
        ple=true;
    }
    return ple;
}

bool Tauler::mateixa_magia_fila(Carta ca,int i,int j){
    return ca.get_magia()==a_mp[i][j].get_magia();
}

bool Tauler::mateixa_germandat_fila(Carta ca,int i,int j){
    return ca.get_germandat()==a_mp[i][j].get_germandat();
}

bool Tauler::mateixa_magia_columna(Carta ca,int ii,int jj){
    return ca.get_magia()==a_mp[ii][jj].get_magia();
}

bool Tauler::mateixa_germandat_columna(Carta ca,int ii,int jj){
    return ca.get_germandat()==a_mp[ii][jj].get_germandat();
}

void Tauler::agafar_carta_tauler(Carta&cb,int i,int j){
    cb=a_mp[i][j];
}

bool Tauler::diferent_germandat(int i,int ii,int j,int jj){
    return a_mp[ii][j].get_germandat()!=a_mp[i][jj].get_germandat();
}

void Tauler::eliminar_de_tauler(int i,int j){
    a_mp[i][j].eliminar_carta_tauler();
}

bool Tauler::buida(int i,int j){
    return a_mp[i][j].get_influencia()==0;
}

bool Tauler::plena(int i,int j){
    return a_mp[i][j].get_influencia()!=0;
}
