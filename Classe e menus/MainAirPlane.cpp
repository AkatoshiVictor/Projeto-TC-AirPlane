#include <conio.h>
#include <iostream>
#include <locale>
#include <vector>
#include <windows.h>

using namespace std;

/*COMO ESSA � A MAIN PRINCIPAL DO PROJETO
ELA N�O FOI FINALIZADA, E SER� FINALIZADA APENAS
NA VERS�O 1 DO PROJETO*/

/*Inclus�o de arquivos utilizados*/
#include "Menus.cpp"

/*PARA O FUNCIONAMENTO CORRETO DO PROGRAMA DESLIGUE O "CAPS LOCK"*/
int main(){
    setlocale(LC_ALL,"Portuguese");
    system("cls");
    Menus Agencia;

    int Escolhas = 0;

    /*Chamada do m�todo de menus*/
    while(1){
        Escolhas = Agencia.MenuGeral();
        /*Switch do menu geral*/
        switch(Escolhas){
            /*Funciom�rio Patentes*/
            case 0:{
                while(1){
                    Escolhas = Agencia.Funcionario();
                    switch(Escolhas){
                        /*Funcion�rio presidente*/
                        case 0:{
                            /*if M�todo de verifical�ao de login*/
                            while(1){
                                Escolhas = Agencia.FuncionarioPresidente();
                                switch(Escolhas){
                                    case 0:{
                                        cout << endl << "EXIBDA O REL�TORIO DA EMPRESA" << endl;
                                        system("pause");
                                    }
                                    break;
                                    /*Case para os m�todos de altera��o de taxas*/
                                    case 1:{
                                        while(1){
                                            Escolhas = Agencia.FuncionarioPresidenteAlteracaoDeTaxas();
                                            switch(Escolhas){
                                                case 0:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE TAXAS A�REAS ECONOMICA" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 1:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE TAXAS A�REAS EXECUTIVA" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 2:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE TAXAS A�REAS PRIMEIRA CLASSE" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 3:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE TAXAS TERRESTRE ECONOMICA" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 4:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE TAXAS TERRESTRE EXECUTIVA" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 5:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE TAXAS MAR�TIMAS" << endl;
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
                                        cout << endl << "EXECUTE O M�TODO DE DEMI��O DE FUNCION�RIO" << endl;
                                        system("pause");
                                    }
                                    break;
                                    /*Case para os m�todos de exibi��o de passagens vendidas*/
                                    case 3:{
                                        while(1){
                                            Escolhas = Agencia.FuncionarioPresidenteRegistroDePassagens();
                                            switch(Escolhas){
                                                case 0:{
                                                    cout << endl << "EXECUTE O M�TODO DE EXIBI��O DE VEBDA DAS PASSAGENS DE �NIBUS" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 1:{
                                                    cout << endl << "EXECUTE O M�TODO DE EXIBI��O DE VEBDA DAS PASSAGENS DE AVI�O" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 2:{
                                                    cout << endl << "EXECUTE O M�TODO DE EXIBI��O DE VEBDA DAS PASSAGENS DE CRUZEIRO" << endl;
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
                        /*Funcion�rio gerente*/
                        case 1:{

                        }
                        break;
                        /*Funcion�rio vendedor*/
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
            Escolhas = 0; /*Redefinindo o valor da vari�vel*/
            cout << endl << "O programa foi encerrado" << endl;
            system("pause");
            break;
        }
    }

    return 0;
}
