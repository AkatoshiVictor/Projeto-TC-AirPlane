#include <conio.h>
#include <iostream>
#include <locale>
#include <vector>
#include <windows.h>

using namespace std;

/*COMO ESSA É A MAIN PRINCIPAL DO PROJETO
ELA NÃO FOI FINALIZADA, E SERÁ FINALIZADA APENAS
NA VERSÃO 1 DO PROJETO*/

/*Inclusão de arquivos utilizados*/
#include "Menus.cpp"

/*PARA O FUNCIONAMENTO CORRETO DO PROGRAMA DESLIGUE O "CAPS LOCK"*/
int main(){
    setlocale(LC_ALL,"Portuguese");
    system("cls");
    Menus Agencia;

    int Escolhas = 0;

    /*Chamada do método de menus*/
    while(1){
        Escolhas = Agencia.MenuGeral();
        /*Switch do menu geral*/
        switch(Escolhas){
            /*Funciomário Patentes*/
            case 0:{
                while(1){
                    Escolhas = Agencia.Funcionario();
                    switch(Escolhas){
                        /*Funcionário presidente*/
                        case 0:{
                            /*if Método de verificalçao de login*/
                            while(1){
                                Escolhas = Agencia.FuncionarioPresidente();
                                switch(Escolhas){
                                    case 0:{
                                        cout << endl << "EXIBDA O RELÁTORIO DA EMPRESA" << endl;
                                        system("pause");
                                    }
                                    break;
                                    /*Case para os métodos de alteração de taxas*/
                                    case 1:{
                                        while(1){
                                            Escolhas = Agencia.FuncionarioPresidenteAlteracaoDeTaxas();
                                            switch(Escolhas){
                                                case 0:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE TAXAS AÉREAS ECONOMICA" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 1:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE TAXAS AÉREAS EXECUTIVA" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 2:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE TAXAS AÉREAS PRIMEIRA CLASSE" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 3:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE TAXAS TERRESTRE ECONOMICA" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 4:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE TAXAS TERRESTRE EXECUTIVA" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 5:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE TAXAS MARÍTIMAS" << endl;
                                                    system("pause");
                                                }
                                                break;
                                            }
                                             if(Escolhas == 99){
                                                Escolhas = 0;
                                                break;
                                            }
                                        }
                                    }
                                    break;
                                    case 2:{
                                        cout << endl << "EXECUTE O MÉTODO DE DEMIÇÃO DE FUNCIONÁRIO" << endl;
                                        system("pause");
                                    }
                                    break;
                                    /*Case para os métodos de exibição de passagens vendidas*/
                                    case 3:{
                                        while(1){
                                            Escolhas = Agencia.FuncionarioPresidenteRegistroDePassagens();
                                            switch(Escolhas){
                                                case 0:{
                                                    cout << endl << "EXECUTE O MÉTODO DE EXIBIÇÃO DE VEBDA DAS PASSAGENS DE ÔNIBUS" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 1:{
                                                    cout << endl << "EXECUTE O MÉTODO DE EXIBIÇÃO DE VEBDA DAS PASSAGENS DE AVIÃO" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 2:{
                                                    cout << endl << "EXECUTE O MÉTODO DE EXIBIÇÃO DE VEBDA DAS PASSAGENS DE CRUZEIRO" << endl;
                                                    system("pause");
                                                }
                                                break;
                                            }
                                             if(Escolhas == 99){
                                                Escolhas = 0;
                                                system("pause");
                                                break;
                                            }
                                        }
                                    }
                                    break;
                                }
                                if(Escolhas == 99){
                                    Escolhas = 0;
                                    system("pause");
                                    break;
                                }
                            }
                        }
                        break;
                        /*Funcionário gerente*/
                        case 1:{

                        }
                        break;
                        /*Funcionário vendedor*/
                        case 2:{

                        }
                        break;
                    }

                    if(Escolhas == 99){
                        Escolhas = 0;
                        system("pause");
                        break;
                    }
                }
            }
            break;
            /*Cliente*/
            case 1:{

            }
            /*Case cliente*/
            break;
        }
        if(Escolhas == 99){
            Escolhas = 0; /*Redefinindo o valor da variável*/
            cout << endl << "O programa foi encerrado" << endl;
            system("pause");
            break;
        }
    }

    return 0;
}
