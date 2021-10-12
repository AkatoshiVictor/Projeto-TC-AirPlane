#include "Cruzeiro.h"

Cruzeiro::Cruzeiro(string TagPassagem, int DiaI, int MesI, int AnoI, int DiaV, int MesV, int AnoV, 
int Hora, string Origem, string Destino, int Preco, int Distancia):Produto(TagPassagem, DiaI, MesI, 
AnoI, DiaV, MesV, AnoV, Hora, Origem, Destino, Preco){

    set_Distancia(Distancia);

}

Cruzeiro::Cruzeiro(int dia_de_ida, int mes_de_ida, int ano_de_ida, int dia_de_volta, int mes_de_volta,
                 int ano_de_volta, int TipoDeViagem, int origem, int destino, int TipoDePassagem, int turno)
    :Produto(dia_de_ida, mes_de_ida, ano_de_ida, dia_de_volta, mes_de_volta,
            ano_de_volta, TipoDeViagem, origem, destino, turno){

    PacoteDeLuaDeMel = TipoDePassagem;
    Define_Distancia_Cruzeiro(destino);
    Calcula_PrecoDaPassagemCruzeio();
}

void Cruzeiro::set_Distancia(int Distancia){
    Distancia_Cruzeiro = Distancia;
}

void Cruzeiro::set_PacoteLuaDeMel(int TipoDePassagem){
    PacoteDeLuaDeMel = TipoDePassagem;
}

int Cruzeiro::get_PacoteLuaDeMel(){
    return PacoteDeLuaDeMel;
}

void Cruzeiro::Define_Distancia_Cruzeiro(int a){
    switch(a){
        case 0:{
            Distancia_Cruzeiro=maritimo_Salvador[0];
        }break;
        case 1:{
            Distancia_Cruzeiro=maritimo_Salvador[1];
        }break;
    }
}

int Cruzeiro::Retorna_Distancia_Cruzeiro(){
    return Distancia_Cruzeiro;
}

void Cruzeiro::Calcula_TempoDeViagemCruzeiro(){
    int horas, minutos;
    horas=(Retorna_Distancia_Cruzeiro()/80);
    minutos=(horas-(Retorna_Distancia_Cruzeiro()/80))*100;

    Define_TempoDeViagem(to_string(horas)+" hr(s) e "+to_string(minutos)+" min(s)");
}

void Cruzeiro::Calcula_PrecoDaPassagemCruzeio(){
    float calc_do_preco;

    calc_do_preco = TaxaFixaDeDistancia*Retorna_Distancia_Cruzeiro();

    if(get_PacoteLuaDeMel()==1){
        calc_do_preco=calc_do_preco+5000;
    }
    Define_PrecoDaPassagem(calc_do_preco);
}

void Cruzeiro::ImprimePassagemCruzeiro(){
    ImprimirDadosDaViagem();
    cout<<"\nDistância à ser percorrida: "<<Retorna_Distancia_Cruzeiro()<<" Km"
        <<"\nDuração média da viagem: 15 dias"
        <<"\nPreco da passagem: R$ "<<Retorna_PrecoDaPassagem()<<endl;
}

