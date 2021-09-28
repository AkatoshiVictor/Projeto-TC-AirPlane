#include "Aviao.h"

Aviao::Aviao(string Data_de_ida, string Data_de_volta, int TipoDeViagem, int origem, int destino)
    :Produto(Data_de_ida, Data_de_volta, TipoDeViagem, origem, destino){

}

int Aviao::Regioes(int A, int B)const {
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

void Aviao::Define_Distancia_Aviao(int a, int c){
    int b = Regioes(a, c);
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


