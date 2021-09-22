#include <iostream>
#include <vector>

using namespace std;

#include "Produto.cpp"
#include "Onibus.cpp"
#include "Aviao.cpp"
#include "Cruzeiro.cpp"
#include "GeradorDePassagens.cpp"

int main(){

    /*SOMENTE AS VIAGENS DE ÔNIBUS ESTÃO SENDO EXECUTADAS*/

    GeradorDePassagens ger;

    setlocale(LC_ALL, "portuguese");

    int Tipo_de_viagem;
    string Data_de_ida;
    string Data_de_volta;
    int Origem;
    int Destino;
    int Cabine;
    int PacoteLuaDeMel;
    int escolha;

    int opc;

    cout<<"Você é?"
        <<"\n0-Cliente"
        <<"\n1-Funcionério"<<endl;
        cin>>opc;

    if(opc==0){

        cout<<"Agende sua passagem!";
        cout<<"\nSOMENTE AS VIAGENS DE ÔNIBUS ESTÃO SENDO EXECUTADAS!";
        cout<<"\nDigite o tipo de viagem!"
            <<"\n0-ônibus"
            <<"\n1-avião"
            <<"\n2-Cruzeiro\n";
            cin>>Tipo_de_viagem;

                cout<<"Digite a data de partida: "<<endl;
                cin>>Data_de_ida;
                cout<<"Digite a data de volta: "<<endl;
                cin>>Data_de_volta;
                cout<<"Escolha a origem de sua viagem!"
                    <<"\n0-Brasília"
                    <<"\n1-Florianópolis"
                    <<"\n2-João Pessoa"
                    <<"\n3-Manaus"
                    <<"\n4-São Paulo"<<endl;
                    cin>>Origem;
                    do{
                        cout<<"Escolha o destino de sua viagem!"
                        <<"\n0-Aracajú"
                        <<"\n1-Belém"
                        <<"\n2-Belo Horizonte"
                        <<"\n3-Boa vista"
                        <<"\n4-Brasília"<<endl;
                        cin>>Destino;

                    }while(Origem==0 && Destino==4);
                    switch(Tipo_de_viagem){
                        case 0:{
                            cout<<"\nEscolha a classe de viagem"
                                <<"\n0-Classe econômica"
                                <<"\n1-Classe executiva"<<endl;
                                cin>>escolha;

                            Onibus func1(Data_de_ida, Data_de_volta, Tipo_de_viagem, Origem, Destino, escolha);
                            ger.AgendandoPassagemOnibus(func1);
                            func1.ImprimirPassagemOnibus();
                        }break;
                        case 1:{
                            Aviao func2(Data_de_ida, Data_de_volta, Tipo_de_viagem, Origem, Destino);
                            ger.AgendandoPassagemAviao(func2);
                        }break;
                        case 2:{
                            cout<<"\nEscolha sua cabine"
                                <<"\n0-Suíte comum"
                                <<"\n1-Suíte com varanda"
                                <<"\n2-Suíte presidencial";
                                cin>>Cabine;

                            cout<<"Adicionar o pacote de lua de mel?"
                                <<"\n0-Não"
                                <<"\n1-Sim";
                                cin>>PacoteLuaDeMel;

                        }break;
                    }
    }

    return 0;
}
