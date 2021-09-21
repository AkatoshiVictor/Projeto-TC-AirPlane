#include "Produto.h"
#include <string>
#include <iomanip>

Produto::Produto(string Data_de_ida, string Data_de_volta, int TipoDeViagem, int origem, int destino){
        Escolha_Tipo_de_viagem(TipoDeViagem);
        this->Data_de_ida=Data_de_ida;
        this->Data_de_volta=Data_de_volta;
        Escolha_Origem(origem);
        Escolha_Destino(destino);
}

void Produto::set_Data_de_ida(string Data_de_ida){
    this->Data_de_ida=Data_de_ida;
}

void Produto::set_Data_de_volta(string Data_de_volta){
    this->Data_de_volta=Data_de_volta;
}

string Produto::get_Data_de_ida(){
    return Data_de_ida;
}

string Produto::get_Data_de_volta(){
    return Data_de_volta;
}

void Produto::Escolha_Tipo_de_viagem(int a){
    switch(a){
        case 0:{
            Tipo_de_viagem="Ônibus";
        }break;
        case 1:{
            Tipo_de_viagem="Avião";
        }break;
        case 2:{
            Tipo_de_viagem="Cruzeiro";
        }break;
    }
}

string Produto::Retorna_Tipo_de_viagem(){
    return Tipo_de_viagem;
}

void Produto::Escolha_Origem(int b){
    if(Retorna_Tipo_de_viagem()!="Cruzeiro"){

        switch(b){
            case 0:{
                Origem="Brasília";
            }break;
            case 1:{
                Origem="Florianópolis";
            }break;
            case 2:{
                Origem="João Pessoa";
            }break;
            case 3:{
                Origem="Manaus";
            }break;
            case 4:{
                Origem="São Paulo";
            }break;
        }
    }else{
        Origem="Salvador";
    }
}

string Produto::Retorna_Origem(){
    return Origem;
}

void Produto::Escolha_Destino(int c){
    string Destinos[27]={"Aracajú", "Belém" ,"Belo Horizonte", "Boa Vista", "Brasília",
        "Campo Grande", "Cuiabá", "Curitiba", "Florianópolis", "Fortaleza", "Goiânia",
        "João Pessoa", "Macapá", "Maceió", "Manaus", "Natal", "Palmas", "Porto Alegre",
        "Porto Velho", "Recife", "Rio Branco", "Rio de Janeiro", "Salvador", "São Luis",
        "São Paulo", "Teresina", "Vitória"};

        Destino=Destinos[c];

}

string Produto::Retorna_Destino(){
    return Destino;
}

void Produto::Define_TempoDeViagem(string TempoDaViagem){

    this->TempoDaViagem=TempoDaViagem;
}

string Produto::Retorna_TempoDeViagem(){
    return TempoDaViagem;
}

void Produto::Define_PrecoDaPassagem(float PrecoDaPassagem){
    this->PrecoDaPassagem = PrecoDaPassagem;
}

float Produto::Retorna_PrecoDaPassagem(){
    return PrecoDaPassagem;
}

void Produto::Define_TagPassagem(){
    srand(time(0));

    char vetor[8];
    char i;

    for(i=0; i<4; i++){
        vetor[i]= 'a' + (char)(rand()%26);
        TagPassagem=TagPassagem+vetor[i];
    }

    for(int j=4; j<8; j++){
        vetor[j]=(rand()%10);
        TagPassagem=TagPassagem+to_string(vetor[j]);
    }
}

string Produto::Retorna_TagPassagem(){
    return TagPassagem;
}

void Produto::ImprimirDadosDaViagem(){
    Define_TagPassagem();
    cout<<"---------------------------------------------------------------"
        <<"\nPassagem de "<<Retorna_Tipo_de_viagem()
        <<"\nRegistro: "<<Retorna_TagPassagem()
        <<"\nData de Embarque: "<<get_Data_de_ida()
        <<"\nData de volta: "<<get_Data_de_volta()
        <<"\nOrigem: "<<Retorna_Origem()
        <<"\nDestino: "<<Retorna_Destino();
}
