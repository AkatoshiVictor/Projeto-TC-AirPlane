#include "Produto.h"
#include <string>
#include <iomanip>

Produto::Produto(string TipoDeViagem, string Origem, string Destino,
 string Tempo, string TagPassagem, float Preco, int DiaI, int MesI, int AnoI, int DiaV, int MesV, int AnoV, int Hora){
    
    set_tipo(TipoDeViagem);
    set_origem(Origem);
    set_destino(Destino);
    set_tempo(Tempo);
    set_tag(TagPassagem);
    set_preco(Preco);
    set_dia_de_ida(DiaI);
    set_mes_de_ida(MesI);
    set_ano_de_ida(AnoI);
    set_dia_de_volta(DiaV);
    set_mes_de_volta(MesV);
    set_ano_de_volta(AnoV);
    set_horario(Hora);

}

Produto::Produto(string TagPassagem, int DiaI, int MesI, int AnoI, int DiaV, int MesV, 
int AnoV, int Hora, string Origem, string Destino, int Preco){

    set_origem(Origem);
    set_destino(Destino);
    set_tag(TagPassagem);
    set_preco(Preco);
    set_dia_de_ida(DiaI);
    set_mes_de_ida(MesI);
    set_ano_de_ida(AnoI);
    set_dia_de_volta(DiaV);
    set_mes_de_volta(MesV);
    set_ano_de_volta(AnoV);
    set_horario(Hora);

}

Produto::Produto(int dia_de_ida, int mes_de_ida, int ano_de_ida, int dia_de_volta, int mes_de_volta,
                 int ano_de_volta, int TipoDeViagem, int origem, int destino, int turno){
        Escolha_Tipo_de_viagem(TipoDeViagem);
        Embarque.Dia_de_ida=dia_de_ida;
        Embarque.Mes_de_ida=mes_de_ida;
        Embarque.Ano_de_ida=ano_de_ida;
        Retorno.Dia_de_volta=dia_de_volta;
        Retorno.Mes_de_volta=mes_de_volta;
        Retorno.Ano_de_volta=ano_de_volta;
        Escolha_Origem(origem);
        Escolha_Destino(destino);
        set_Horario(turno);
        Define_TagPassagem();
}

void Produto::set_dia_de_ida(int dia_de_ida){
    Embarque.Dia_de_ida=dia_de_ida;
}

void Produto::set_mes_de_ida(int mes_de_ida){
    Embarque.Mes_de_ida=mes_de_ida;
}

void Produto::set_ano_de_ida(int ano_de_ida){
    Embarque.Ano_de_ida=ano_de_ida;
}

void Produto::set_dia_de_volta(int dia_de_volta){
    Retorno.Dia_de_volta=dia_de_volta;
}

void Produto::set_mes_de_volta(int mes_de_volta){
    Retorno.Mes_de_volta=mes_de_volta;
}

void Produto::set_ano_de_volta(int ano_de_volta){
    Retorno.Ano_de_volta=ano_de_volta;
}

int Produto::get_dia_de_ida(){
    return Embarque.Dia_de_ida;
}

int Produto::get_mes_de_ida(){
    return Embarque.Mes_de_ida;
}

int Produto::get_ano_de_ida(){
    return Embarque.Ano_de_ida;
}

int Produto::get_dia_de_volta(){
    return Retorno.Dia_de_volta;
}

int Produto::get_mes_de_volta(){
    return Retorno.Mes_de_volta;
}

int Produto::get_ano_de_volta(){
    return Retorno.Ano_de_volta;
}

void Produto::set_preco(float preco){
    PrecoDaPassagem = preco;
}

void Produto::set_tag(string tag){
    TagPassagem = tag;
}

void Produto::set_destino(string destino){
    Destino = destino;
}

void Produto::set_origem(string origem){
    Origem = origem;
}

void Produto::set_tempo(string tempo){
    TempoDaViagem = tempo;
}

void Produto::set_tipo(string tipo){
    Tipo_de_viagem = tipo;
}

void Produto::set_horario(int hora){
    Horario = hora;
}

void Produto::Escolha_Tipo_de_viagem(int a){
    switch(a){
        case 0:{
            Tipo_de_viagem="Avião";
            TagPassagem="A";
        }break;

        case 1:{
            Tipo_de_viagem="Ônibus";
            TagPassagem="O";
        }break;

        case 2:{
            Tipo_de_viagem="Cruzeiro";
            TagPassagem="C";
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
                Origem="João Pessoa";

            }break;
            case 2:{
                 Origem="Manaus";
            }break;
            case 3:{
                 Origem="São Paulo";
            }break;
            case 4:{
                 Origem="Florianópolis";
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
    if(Retorna_Tipo_de_viagem() == "Avião" || Retorna_Tipo_de_viagem() == "Ônibus"){
        string Destinos[27]={"Aracajú", "Belém" ,"Belo Horizonte", "Boa Vista", "Brasília",
            "Campo Grande", "Cuiabá", "Curitiba", "Florianópolis", "Fortaleza", "Goiânia",
            "João Pessoa", "Macapá", "Maceió", "Manaus", "Natal", "Palmas", "Porto Alegre",
            "Porto Velho", "Recife", "Rio Branco", "Rio de Janeiro", "Salvador", "São Luis",
            "São Paulo", "Teresina", "Vitória"};

            Destino=Destinos[c];
    }
    else if(Retorna_Tipo_de_viagem() == "Cruzeiro"){
        string Destinos[2] = {"Europa", "Caribe"};

        Destino=Destinos[c];
    }

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

    for(i=0; i<3; i++){
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

void Produto::set_Horario(int turno){

    switch(turno){
        case 0:{
            Horario = 10;
        }
        break;

        case 1:{
            Horario = 15;
        }
        break;

        case 2:{
            Horario = 21;
        }
        break;
    }

}

int Produto::get_Horario(){
    return Horario;
}

void Produto::ImprimirDadosDaViagem(){

    cout<<"---------------------------------------------------------------"
        <<"\nPassagem de "<<Retorna_Tipo_de_viagem()
        <<"\nRegistro: "<<Retorna_TagPassagem()
        <<"\nData de Embarque: "<<get_dia_de_ida()<<"/"
        <<get_mes_de_ida()<<"/"<<get_ano_de_ida()
        <<"\nData de volta: "<<get_dia_de_volta()<<"/"
        <<get_mes_de_volta()<<"/"<<get_ano_de_volta()
        <<"\nHorário de partida: "<<get_Horario()<<"Hrs"
        <<"\nOrigem: "<<Retorna_Origem()
        <<"\nDestino: "<<Retorna_Destino();
}
