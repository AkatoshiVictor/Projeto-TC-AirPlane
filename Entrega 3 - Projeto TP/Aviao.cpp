#include "Aviao.h"

Aviao::Aviao(string TipoDeViagem, string Origem, string Destino, string Tempo, string TagPassagem, 
float Preco, int Distancia, int DiaI, int MesI, int AnoI, int DiaV, int MesV, int AnoV, int Hora):Produto(TipoDeViagem, Origem, Destino,
 Tempo, TagPassagem, Preco, DiaI, MesI, AnoI, DiaV, MesV, AnoV, Hora){
    
    set_distancia(Distancia);

}

Aviao::Aviao(int dia_de_ida, int mes_de_ida, int ano_de_ida, int dia_de_volta, int mes_de_volta,
                 int ano_de_volta, int TipoDeViagem, int origem, int destino, int escolha, int turno)
    :Produto(dia_de_ida, mes_de_ida, ano_de_ida, dia_de_volta, mes_de_volta,
            ano_de_volta, TipoDeViagem, origem, destino, turno){

    Define_Distancia_Aviao(origem, destino);
    Calcula_TempoDeViagemAviao();
    Calcula_PrecoDaPassagemAviao(escolha);

}

void Aviao::Define_Distancia_Aviao(int a, int c){

    switch(a){
        case 0:{
            Distancia_Aviao=Aereo_Brasilia[c];
        }break;
        case 1:{
            Distancia_Aviao=Aereo_Florianopolis[c];
        }break;
        case 2:{
            Distancia_Aviao=Aereo_Joao_Pessoa[c];
        }break;
        case 3:{
            Distancia_Aviao=Aereo_Manaus[c];
        }break;
        case 4:{
            Distancia_Aviao=Aereo_Sao_Paulo[c];
        }break;
    }
}

int Aviao::Retorna_Distancia_Aviao(){
    return Distancia_Aviao;
}

void Aviao::Calcula_TempoDeViagemAviao(){
    int horas, minutos;
    horas=(Retorna_Distancia_Aviao()/800.00);
    minutos=((Retorna_Distancia_Aviao()/800.00)-horas)*60;

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

void Aviao::ImprimePassagemAviao(){
    ImprimirDadosDaViagem();
    cout<<"\nDistância à ser percorrida: "<<Retorna_Distancia_Aviao()<<" Km"
        <<"\nDuração média da viagem: "<<Retorna_TempoDeViagem()
        <<"\nPreco da passagem: R$ "<<Retorna_PrecoDaPassagem()<<endl;
}

void Aviao::set_distancia(int distancia){
    Distancia_Aviao = distancia;
}