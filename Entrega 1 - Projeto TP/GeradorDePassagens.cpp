#include "GeradorDePassagens.h"

GeradorDePassagens::GeradorDePassagens(){

}

void GeradorDePassagens::AgendandoPassagemOnibus(Onibus x){
    PassagensOnibus.push_back(x);
}

void GeradorDePassagens::AgendandoPassagemAviao(Aviao x){
    PassagensAviao.push_back(x);
}

void GeradorDePassagens::AgendandoPassagemCruzeiro(Cruzeiro x){
    PassagensCruzeiro.push_back(x);
}

void GeradorDePassagens::Retornar_passagens(){

    fstream Dadospassagens;
    Dadospassagens.open("DadosPassagens.txt", ios::out);

    if(Dadospassagens){
        Dadospassagens<<PassagensAviao.size();
        for(int i=0;i<PassagensAviao.size();i++){
            Dadospassagens<<PassagensAviao[i].Retorna_Tipo_de_viagem();
            Dadospassagens<<PassagensAviao[i].get_Data_de_ida();
            Dadospassagens<<PassagensAviao[i].get_Data_de_volta();
            Dadospassagens<<PassagensAviao[i].Retorna_Origem();
            Dadospassagens<<PassagensAviao[i].Retorna_Destino();
            Dadospassagens<<PassagensAviao[i].Retorna_Distancia_Aviao();
            Dadospassagens<<PassagensAviao[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensAviao[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensAviao[i].Retorna_TagPassagem();
        }

        Dadospassagens<<PassagensOnibus.size();
        for(int i=0;i<PassagensOnibus.size();i++){
            Dadospassagens<<PassagensOnibus[i].Retorna_Tipo_de_viagem();
            Dadospassagens<<PassagensOnibus[i].get_Data_de_ida();
            Dadospassagens<<PassagensOnibus[i].get_Data_de_volta();
            Dadospassagens<<PassagensOnibus[i].Retorna_Origem();
            Dadospassagens<<PassagensOnibus[i].Retorna_Destino();
            Dadospassagens<<PassagensOnibus[i].Retorna_Distancia_Onibus();
            Dadospassagens<<PassagensOnibus[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensOnibus[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensOnibus[i].Retorna_TagPassagem();
        }

        Dadospassagens<<PassagensCruzeiro.size();
        for(int i=0;i<PassagensCruzeiro.size();i++){
            Dadospassagens<<PassagensCruzeiro[i].Retorna_Tipo_de_viagem();
            Dadospassagens<<PassagensCruzeiro[i].get_Data_de_ida();
            Dadospassagens<<PassagensCruzeiro[i].get_Data_de_volta();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_Origem();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_Destino();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_Distancia_Cruzeiro();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_TagPassagem();
        }
    }

    if(Dadospassagens){
        Dadospassagens<<PassagensVendidasAviao.size();
        for(int i=0;i<PassagensVendidasAviao.size();i++){
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_Tipo_de_viagem();
            Dadospassagens<<PassagensVendidasAviao[i].get_Data_de_ida();
            Dadospassagens<<PassagensVendidasAviao[i].get_Data_de_volta();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_Origem();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_Destino();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_Distancia_Aviao();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_TagPassagem();
        }

        Dadospassagens<<PassagensVendidasOnibus.size();
        for(int i=0;i<PassagensVendidasOnibus.size();i++){
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_Tipo_de_viagem();
            Dadospassagens<<PassagensVendidasOnibus[i].get_Data_de_ida();
            Dadospassagens<<PassagensVendidasOnibus[i].get_Data_de_volta();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_Origem();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_Destino();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_Distancia_Onibus();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_TagPassagem();
        }

        Dadospassagens<<PassagensVendidasCruzeiro.size();
        for(int i=0;i<PassagensVendidasCruzeiro.size();i++){
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_Tipo_de_viagem();
            Dadospassagens<<PassagensVendidasCruzeiro[i].get_Data_de_ida();
            Dadospassagens<<PassagensVendidasCruzeiro[i].get_Data_de_volta();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_Origem();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_Destino();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_Distancia_Cruzeiro();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_TagPassagem();
        }
    }
    Dadospassagens.close();
}

int GeradorDePassagens::Retorna_distancia(string tipo, int x){
    if(tipo=="Avião"){
        PassagensAviao[x].Retorna_Distancia_Aviao();
    }else if(tipo=="Ônibus"){

    }
}



