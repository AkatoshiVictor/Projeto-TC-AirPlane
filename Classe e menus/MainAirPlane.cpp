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
                                                break;
                                            }
                                        }
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
                        /*Funcion�rio gerente*/
                        case 1:{
                            /*if M�todo de verifical�ao de login*/
                            while(1){
                                Escolhas = Agencia.FuncionarioGerente();
                                switch(Escolhas){
                                    case 0:{
                                        cout << endl << "EXECUTE O M�TODO DE DESPEDIR FUNCION�RIO" << endl;
                                        system("pause");
                                    }
                                    break;
                                    case 1:{
                                        cout << endl << "EXECUTE O M�TODO DE CADASTRAR FUNCION�RIO" << endl;
                                        system("pause");

                                    }
                                    break;
                                    case 2:{
                                        cout << endl << "EXECUTE O M�TODO PARA IMPRESS�O DE VENDAS NA REGI�O" << endl;
                                        system("pause");
                                    }
                                    break;
                                    case 3:{
                                        cout << endl << "EXECUTE O M�TODO DE IMPRESS�O DE DADOS DO GERENTE" << endl;
                                        system("pause");
                                    }
                                    break;
                                    case 4:{
                                        while(1){
                                            Escolhas = Agencia.FuncionarioAlteracaoDados();
                                            switch(Escolhas){
                                                case 0:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE EMAIL" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 1:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE SENHA" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 2:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTEREA��O DE NOME" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 3:{
                                                    cout << endl << "EXECUTE O M�TODO DE NASCIMENTO" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 4:{
                                                    cout << endl << "EXECUTE O M�TODO ALTERA��O DE ENDERE�O" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 5:{
                                                    cout << endl << "EXECUTE O M�TODO DE TELEFONE" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 6:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE TELEFONE FAMILAIR" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 7:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE DOCUMENTO" << endl;
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
                                }
                                if(Escolhas == 99){
                                    Escolhas = 0;
                                    break;
                                }
                            }
                        }
                        break;
                        /*Funcion�rio vendedor*/
                        case 2:{
                            /*if M�todo de verifical�ao de login*/
                            while(1){
                                Escolhas = Agencia.FuncionarioFuncionario();
                                switch(Escolhas){
                                    case 0:{
                                        while(1){
                                            Escolhas = Agencia.FuncionarioFuncionarioVenderPassagens();
                                            switch(Escolhas){
                                                case 0:{
                                                    cout << endl << "EXECUTE O M�TODO DE VENDA DE PASSAGENS DE AVI�O" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 1:{
                                                    cout << endl << "EXECUTE O M�TODO DE VENDA DE PASSAGENS DE �NIBUS" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 2:{
                                                    cout << endl << "EXECUTE O M�TODO VENDA DE PASSAGENS DE CRUZEIRO" << endl;
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
                                    case 1:{
                                        cout << endl << "EXECUTE O M�TODO DE IMPRESS�O DE DADOS DO VENDEDOR" << endl;
                                        system("pause");
                                    }
                                    break;
                                    case 2:{
                                        while(1){
                                            Escolhas = Agencia.FuncionarioAlteracaoDados();
                                            switch(Escolhas){
                                                case 0:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE EMAIL" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 1:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE SENHA" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 2:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTEREA��O DE NOME" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 3:{
                                                    cout << endl << "EXECUTE O M�TODO DE NASCIMENTO" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 4:{
                                                    cout << endl << "EXECUTE O M�TODO ALTERA��O DE ENDERE�O" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 5:{
                                                    cout << endl << "EXECUTE O M�TODO DE TELEFONE" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 6:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE TELEFONE FAMILAIR" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 7:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE DOCUMENTO" << endl;
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

                                }                               
                                if(Escolhas == 99){
                                    Escolhas = 0;
                                    break;
                                } 
                            }
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
            /*Cliente*/
            case 1:{
                while(1){
                    Escolhas = Agencia.Cliente();
                    switch(Escolhas){
                        case 0:{
                            /*if M�todo de verifical�ao de login*/
                            while(1){
                                Escolhas = Agencia.ClienteEntrar();
                                switch(Escolhas){
                                    /*Comprar passagem*/
                                    case 0:{
                                        while(1){
                                            Escolhas = Agencia.ClienteComprarPassagens();
                                            switch(Escolhas){
                                                /*Coisas do avi�o*/
                                                case 0:{
                                                    while(1){
                                                        Escolhas = Agencia.ClienteCriacaoDePassagem();
                                                        switch(Escolhas){
                                                            /*Escolha de origem*/
                                                            case 0:{
                                                                while(1){
                                                                    Escolhas = Agencia.ClienteOrigem();
                                                                    /*Execute o m�todo que pega a origem e passe escolhas como par�metro*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        break;
                                                                    }
                                                                }  
                                                            }
                                                            break;
                                                            case 1:{
                                                                while(1){
                                                                    Escolhas = Agencia.ClientePassagensRegioes();
                                                                    switch(Escolhas){
                                                                        case 0:{
                                                                            /*Passe a escolha de regi�o para o m�todo de gera��o de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensCentroOeste();
                                                                                /*Passe a escolha de cidade para a gera��o de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }                                                                               
                                                                            }
                                                                        }
                                                                        break;
                                                                        case 1:{
                                                                            /*Passe a escolha de regi�o para o m�todo de gera��o de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensNordeste();
                                                                                /*Passe a escolha de cidade para a gera��o de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }                                                                               
                                                                            }

                                                                        }
                                                                        break;
                                                                        case 2:{
                                                                            /*Passe a escolha de regi�o para o m�todo de gera��o de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensNorte();
                                                                                /*Passe a escolha de cidade para a gera��o de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }                                                                               
                                                                            }

                                                                        }
                                                                        break;
                                                                        case 3:{
                                                                            /*Passe a escolha de regi�o para o m�todo de gera��o de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensSudeste();
                                                                                /*Passe a escolha de cidade para a gera��o de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }                                                                               
                                                                            }

                                                                        }
                                                                        break;
                                                                        case 4:{
                                                                            /*Passe a escolha de regi�o para o m�todo de gera��o de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensSul();
                                                                                /*Passe a escolha de cidade para a gera��o de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }                                                                               
                                                                            }

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
                                                                while(1){
                                                                    Escolhas = Agencia.ClienteEscolhaDeTaxaDeAviao();
                                                                    /*Execute o m�todo de taxas e pegue como par�metro escolhas*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        break;
                                                                    }  
                                                                }

                                                            }
                                                            break;
                                                            case 3:{
                                                                cout << "EXECUTE O M�TODO QUE EXIBE A PASSAGEM DE AVI�O QUE FOI FEITA" << endl;
                                                                cout << "EXECUTE O M�TODO QUE CONFIRMA A PASSAGEM DO CLIENTE SE ELE APERTAR PARA DIREITA"
                                                                << "E CANCELA SE ELE APERTAR PARA ESQUERDA" << endl;
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
                                                /*Coisas do �nibus*/
                                                case 1:{
                                                    while(1){
                                                        Escolhas = Agencia.ClienteCriacaoDePassagem();
                                                        switch(Escolhas){
                                                            /*Escolha de origem*/
                                                            case 0:{
                                                                while(1){
                                                                    Escolhas = Agencia.ClienteOrigem();
                                                                    /*Execute o m�todo que pega a origem e passe escolhas como par�metro*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        break;
                                                                    }  
                                                                }
                                                            }
                                                            break;
                                                            case 1:{
                                                                /*Para todas as escolhas do destino, deve-se utilizar o m�todo que recebe a posi��o da respectiva regi�o
                                                                para que possa ser escolhido e atribu�do a dist�ncia correspondente*/
                                                                while(1){
                                                                    Escolhas = Agencia.ClientePassagensRegioes();
                                                                    switch(Escolhas){
                                                                        case 0:{
                                                                            /*Passe a escolha de regi�o para o m�todo de gera��o de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensCentroOeste();
                                                                                /*Passe a escolha de cidade para a gera��o de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }                                                                               
                                                                            }
                                                                        }
                                                                        break;
                                                                        case 1:{
                                                                            /*Passe a escolha de regi�o para o m�todo de gera��o de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensNordeste();
                                                                                /*Passe a escolha de cidade para a gera��o de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }                                                                               
                                                                            }

                                                                        }
                                                                        break;
                                                                        case 2:{
                                                                            /*Passe a escolha de regi�o para o m�todo de gera��o de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensNorte();
                                                                                /*Passe a escolha de cidade para a gera��o de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }                                                                               
                                                                            }

                                                                        }
                                                                        break;
                                                                        case 3:{
                                                                            /*Passe a escolha de regi�o para o m�todo de gera��o de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensSudeste();
                                                                                /*Passe a escolha de cidade para a gera��o de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }                                                                               
                                                                            }

                                                                        }
                                                                        break;
                                                                        case 4:{
                                                                            /*Passe a escolha de regi�o para o m�todo de gera��o de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensSul();
                                                                                /*Passe a escolha de cidade para a gera��o de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }                                                                               
                                                                            }

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
                                                                while(1){
                                                                    Escolhas = Agencia.ClienteEscolhaDeTaxaDeOnibus();
                                                                    /*Execute o m�todo de taxas e pegue como par�metro escolhas*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        break;
                                                                    }  
                                                                }

                                                            }
                                                            break;
                                                            case 3:{
                                                                cout << "EXECUTE O M�TODO QUE EXIBE A PASSAGEM DE �NIBUS QUE FOI FEITA" << endl;
                                                                cout << "EXECUTE O M�TODO QUE CONFIRMA A PASSAGEM DO CLIENTE SE ELE APERTAR PARA DIREITA"
                                                                << "E CANCELA SE ELE APERTAR PARA ESQUERDA" << endl;
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
                                                /*Coisas do cruzeiro*/
                                                case 2:{
                                                    while(1){
                                                        Escolhas = Agencia.ClientePassagensCruzeiro();
                                                        /*Passe escolhas como par�metro da cria��o do cliente passagens
                                                        crueiro*/
                                                        /*Execute o m�todo de pergunta (pacote lua de mel)*/
                                                        /*Execute o m�todo de pergunta de acompanhante*/
                                                        if(Escolhas == 99){
                                                            Escolhas = 0;
                                                            break;
                                                        }
                                                        else{
                                                            /*O m�todo do cruzeiro � executado depois do m�todo anteior, sendo feito no else if da escolha*/
                                                            Escolhas = Agencia.ClientePersonalizeSeuCruzeiro();
                                                            /*Esse m�todo realmente n�o tem break*/
                                                            if(Escolhas == 99){
                                                                Escolhas = 0;
                                                            }
                                                        }
                                                    }
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
                                    case 1:{
                                        while(1){
                                            Escolhas = Agencia.HotelEscolha();
                                            switch(Escolhas){
                                                case 0:{
                                                    cout << "COLOQUE OS COUTS DO H�TEL DE 5 ESTRELAS, E PASSA O PAR�METRO PARA O M�TODO DE ESCOLHA DE HO�TEIS" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 1:{
                                                    cout << "COLOQUE OS COUTS DO H�TEL DE 4 ESTRELAS, E PASSA O PAR�METRO PARA O M�TODO DE ESCOLHA DE HO�TEIS" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 2:{
                                                    cout << "COLOQUE OS COUTS DO H�TEL DE 3 ESTRELAS, E PASSA O PAR�METRO PARA O M�TODO DE ESCOLHA DE HO�TEIS" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 3:{
                                                    cout << "COLOQUE OS COUTS DO H�TEL DE 2 ESTRELAS, E PASSA O PAR�METRO PARA O M�TODO DE ESCOLHA DE HO�TEIS" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 4:{
                                                    cout << "COLOQUE OS COUTS DO H�TEL DE 1 ESTRELAS, E PASSA O PAR�METRO PARA O M�TODO DE ESCOLHA DE HO�TEIS" << endl;
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
                                        cout << endl << "EXECUTE O M�TODO DE CANCELAMENTO DE PASSAGENS" << endl;
                                        system("pause");
                                    }
                                    break;
                                    case 3:{
                                        while(1){
                                            Escolhas = Agencia.ClienteEditarCadastro();
                                            switch(Escolhas){
                                                case 0:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE EMAIL" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 1:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE SENHA" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 2:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTEREA��O DE NOME" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 3:{
                                                    cout << endl << "EXECUTE O M�TODO DE NASCIMENTO" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 4:{
                                                    cout << endl << "EXECUTE O M�TODO ALTERA��O DE ENDERE�O" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 5:{
                                                    cout << endl << "EXECUTE O M�TODO DE TELEFONE" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 6:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE TELEFONE FAMILAIR" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 7:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE DOCUMENTO" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 8:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE OR�AMENTO" << endl;
                                                    system("pause");
                                                }
                                                break;
                                                case 9:{
                                                    cout << endl << "EXECUTE O M�TODO DE ALTERA��O DE ACAOMPANHANTE" << endl;
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

                                }
                                if(Escolhas == 99){
                                    Escolhas = 0;
                                    break;
                                }
                            }

                        }
                        break;
                        case 1:{
                            cout << "EXECUTE O M�TODO PARA CADASTRAR O CLIENTE" << endl;
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
