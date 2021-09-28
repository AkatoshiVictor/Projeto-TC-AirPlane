#include "Onibus.h"

Onibus::Onibus(string Data_de_ida, string Data_de_volta, int TipoDeViagem, int origem, int destino, int escolha)
    :Produto(Data_de_ida, Data_de_volta, TipoDeViagem, origem, destino){

    Define_Distancia_Onibus(origem, destino);
    Calcula_TempoDeViagemOnibus();
    Calcula_PrecoDaPassagemOnibus(escolha);

}

int Onibus::Regioes(int A, int B) const{
	switch(A){
		case 0:{
            switch(B){
                case 0:{
                    return 4;
                }
                break;
                case 1:{
                    return 5;
                }
                break;
                case 2:{
                    return 6;
                }
                break;
                case 3:{
                    return 10;
                }
                break;
            }
		}
		break;
		case 1:{
            switch(B){
                case 0:{
                    return 0;
                }
                break;
                case 1:{
                    return 9;
                }
                break;
                case 2:{
                    return 11;
                }
                break;
                case 3:{
                    return 13;
                }
                break;
                case 4:{
                    return 15;
                }
                break;
                case 5:{
                    return 19;
                }
                break;
                case 6:{
                    return 22;
                }
                break;
                case 7:{
                    return 23;
                }
                break;
                case 8:{
                    return 25;
                }
                break;
            }
		}
		break;
		case 2:{
			switch(B){
                case 0:{
                    return 1;
                }
                break;
                case 1:{
                    return 3;
                }
                break;
                case 2:{
                    return 12;
                }
                break;
                case 3:{
                    return 14;
                }
                break;
                case 4:{
                    return 16;
                }
                break;
                case 5:{
                    return 18;
                }
                break;
                case 6:{
                    return 20;
                }
                break;
            }
		}
		break;
		case 3:{
			switch(B){
                case 0:{
                    return 2;
                }
                break;
                case 1:{
                    return 21;
                }
                break;
                case 2:{
                    return 24;
                }
                break;
                case 3:{
                    return 26;
                }
                break;
	        }
		}
		break;
		case 4:{
			switch(A){
                case 0:{
                    return 7;
                }
                break;
                case 1:{
                    return 8;
                }
                break;
                case 2:{
                    return 17;
                }
                break;
            }
		}
		break;
    }
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

int Onibus::Retorna_Distancia_Onibus(){
    return Distancia_Onibus;
}

void Onibus::Calcula_TempoDeViagemOnibus(){
    int horas, minutos;
    horas=(Retorna_Distancia_Onibus()/80);
    minutos=(horas-(Retorna_Distancia_Onibus()/80))*100;

    Define_TempoDeViagem(to_string(horas)+" hr(s) e "+to_string(minutos)+" min(s)");
}

void Onibus::Calcula_PrecoDaPassagemOnibus(int escolha){
    float calc_do_preco;
    switch(escolha){
        case 0:{
            calc_do_preco = TaxaEconomica_Onibus*Retorna_Distancia_Onibus();
        }break;
        case 1:{
            calc_do_preco = TaxaExecutiva_Onibus*Retorna_Distancia_Onibus();
        }break;
    }
    Define_PrecoDaPassagem(calc_do_preco);
}

void Onibus::ImprimirPassagemOnibus(){
    ImprimirDadosDaViagem();
    cout<<"\nDistância à ser percorrida: "<<Retorna_Distancia_Onibus()
        <<"\nDuração média da viagem: "<<Retorna_TempoDeViagem()
        <<"\nPreco da passagem: R$ "<<Retorna_PrecoDaPassagem();
}

