#include "Cruzeiro.h"

Cruzeiro::Cruzeiro(int dia_de_ida, int mes_de_ida, int ano_de_ida, int dia_de_volta, int mes_de_volta,
                 int ano_de_volta, int TipoDeViagem, int origem, int destino, int turno, int Cabine, int PacoteLuaDeMel)
    :Produto(dia_de_ida, mes_de_ida, ano_de_ida, dia_de_volta, mes_de_volta,
            ano_de_volta, TipoDeViagem, origem, destino, turno){

    this->Cabine=Cabine;
    this->PacoteLuaDeMel=PacoteLuaDeMel;

}



void Cruzeiro::set_Cabine(int Cabine){
    this->Cabine=Cabine;
}

void Cruzeiro::set_PacoteLuaDeMel(int PacoteLuaDeMe){
    this->PacoteLuaDeMel=PacoteLuaDeMe;
}

int Cruzeiro::get_Cabine(){
    return Cabine;
}

int Cruzeiro::get_PacoteLuaDeMel(){
    return PacoteLuaDeMel;
}

void Cruzeiro::Define_Distancia_Cruzeiro(int a, int b){
    switch(a){
        case 0:{
            Distancia_Cruzeiro=maritimo_Salvador[b];
        }break;
        case 1:{
            Distancia_Cruzeiro=maritimo_Salvador[b];
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

void Cruzeiro::Calcula_PrecoDaPassagemCruzeio(int escolha){
    float calc_do_preco;
    switch(escolha){
        case 0:{
            calc_do_preco = TaxaFixaDeDistancia*Retorna_Distancia_Cruzeiro();
        }break;
        case 1:{
            calc_do_preco = TaxaFixaDeDistancia*Retorna_Distancia_Cruzeiro();
        }break;
    }
    switch(get_Cabine()){
        case 0 :{
            calc_do_preco=calc_do_preco+500;
        }break;
        case 1:{
            calc_do_preco=calc_do_preco+800;
        }break;
        case 2:{
            calc_do_preco=calc_do_preco+1200;
        }break;
    }
    if(get_PacoteLuaDeMel()==1){
        calc_do_preco=calc_do_preco+500;
    }
    Define_PrecoDaPassagem(calc_do_preco);
}

void Cruzeiro::ImprimePassagemCruzeiro(){
    ImprimePassagemCruzeiro();
}

