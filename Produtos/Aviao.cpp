#include "Aviao.h"

Aviao::Aviao(string Data_de_ida, string Data_de_volta, int TipoDeViagem, int origem, int destino)
    :Produto(Data_de_ida, Data_de_volta, TipoDeViagem, origem, destino){

}

void Aviao::Define_Distancia_Aviao(int a, int b){
    switch(a){
        case 0:{
            Distancia_Aviao=Aereo_Brasilia[b];
        }break;
        case 1:{
            Distancia_Aviao=Aereo_Florianopolis[b];
        }break;
        case 2:{
            Distancia_Aviao=Aereo_Joao_Pessoa[b];
        }break;
        case 3:{
            Distancia_Aviao=Aereo_Manaus[b];
        }break;
        case 4:{
            Distancia_Aviao=Aereo_Sao_Paulo[b];
        }break;
    }
}

int Aviao::Retorna_Distancia_Aviao(){
    return Distancia_Aviao;
}

void Aviao::Calcula_TempoDeViagemAviao(){
    int horas, minutos;
    horas=(Retorna_Distancia_Aviao()/800);
    minutos=(horas-(Retorna_Distancia_Aviao()/800))*100;

    Define_TempoDeViagem(to_string(horas)+" hr(s) e "+to_string(minutos)+" min(s)");
}

void Aviao::Calcula_PrecoDaPassagemAviao(int escolha){
    float calc_do_preco;
    switch(escolha){
        case 0:{
            calc_do_preco = TaxaEconomica_Aviao*Retorna_Distancia_Aviao();
        }break;
        case 1:{
            calc_do_preco = TaxaExecutiva_Aviao*Retorna_Distancia_Aviao();
        }break;
        case 2:{
            calc_do_preco = TaxaPrimeiraClasse_Aviao*Retorna_Distancia_Aviao();
        }break;
    }
    Define_PrecoDaPassagem(calc_do_preco);
}


