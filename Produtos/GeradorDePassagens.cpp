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




