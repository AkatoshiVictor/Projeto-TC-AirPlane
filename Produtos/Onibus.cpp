#include "Onibus.h"

Onibus::Onibus(string Data_de_ida, string Data_de_volta, int TipoDeViagem, int origem, int destino, int escolha)
    :Produto(Data_de_ida, Data_de_volta, TipoDeViagem, origem, destino){
    Define_Distancia_Onibus(origem, destino);
    Calcula_TempoDeViagemOnibus();
    Calcula_PrecoDaPassagemOnibus(escolha);

}

void Onibus::Define_Distancia_Onibus(int a, int b){
    switch(a){
        case 0:{
            Distancia_Onibus=Terrestre_Brasilia[b];
        }break;
        case 1:{
            Distancia_Onibus=Terrestre_Florianopolis[b];
        }break;
        case 2:{
            Distancia_Onibus=Terrestre_Joao_Pessoa[b];
        }break;
        case 3:{
            Distancia_Onibus=Terrestre_Manaus[b];
        }break;
        case 4:{
            Distancia_Onibus=Terrestre_Sao_Paulo[b];
        }break;
    }
}

int Onibus::Retorna_Distancia_onibus(){
    return Distancia_Onibus;
}

void Onibus::Calcula_TempoDeViagemOnibus(){
    int horas, minutos;
    horas=(Retorna_Distancia_onibus()/80);
    minutos=(horas-(Retorna_Distancia_onibus()/80))*100;

    Define_TempoDeViagem(to_string(horas)+" hr(s) e "+to_string(minutos)+" min(s)");
}

void Onibus::Calcula_PrecoDaPassagemOnibus(int escolha){
    float calc_do_preco;
    switch(escolha){
        case 0:{
            calc_do_preco = TaxaEconomica_Onibus*Retorna_Distancia_onibus();
        }break;
        case 1:{
            calc_do_preco = TaxaExecutiva_Onibus*Retorna_Distancia_onibus();
        }break;
    }
    Define_PrecoDaPassagem(calc_do_preco);
}

void Onibus::ImprimirPassagemOnibus(){
    ImprimirDadosDaViagem();
    cout<<"\nDistância à ser percorrida: "<<Retorna_Distancia_onibus()
        <<"\nDuração média da viagem: "<<Retorna_TempoDeViagem()
        <<"\nPreco da passagem: R$ "<<Retorna_PrecoDaPassagem();
}

