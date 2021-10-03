/*As bibliotecas inclu�das s�o usadas
tamb�m nas outras classes*/

#include <conio.h>
#include <iostream>
#include <locale>
#include <vector>
#include <windows.h>
#include <fstream>

using namespace std;

/*Inclus�o dos arquivos necess�rios para a execu��o da main*/

#include "Menus.cpp"
#include "AgenciaDeViagens.cpp" /*As outras classes s�o iclu�das em ag�ncia*/

int main(){

    /*Bloco de preapa��o inicial*/

        /*Preparando o terminal de exibi��o*/
        setlocale(LC_ALL,"Portuguese");
        system("cls");

        /*Cria��o dos objetos utilizados dentro da main*/
        Menus Agencia;
        AgenciaDeViagens ObjAgencia;

        /*Vari�vel padr�o usada no switch*/
        int Escolhas = 0;


    /*Bloco de chamada do menu geral*/
    while(1){
        Escolhas = Agencia.MenuGeral();
        switch(Escolhas){

            /*##################################################################################*/
            /*######################### BLOCO PARA OS FUNCION�RIOS #############################*/
            /*##################################################################################*/

            case 0:{

                /*Bloco de chamada do menu de patentes*/
                while(1){
                    Escolhas = Agencia.Funcionario();
                    switch(Escolhas){

                        /*##################################################################################*/
                        /*########################## BLOCO PARA O PRESIDENTE ###############################*/
                        /*##################################################################################*/

                        case 0:{

                            /*Bloco de verifica��o de login do presidente*/
                            system("cls");
                            if(ObjAgencia.LoginFuncionario(Escolhas)){

                                /*Bloco de repeti��o para as op��es do presidente*/
                                while(1){
                                    Escolhas = Agencia.FuncionarioPresidente();
                                    switch(Escolhas){

                                        /*Case de exibi��o do relat�rio de gastos e lucros
                                        da empresa*/
                                        case 0:{
                                            cout << endl << "EXIBA O REL�TORIO DA EMPRESA" << endl;
                                            system("pause");
                                        }
                                        break;

                                        /*Case usado para op��o de demitir funcion�rios (pelo presidente)*/
                                        case 1:{
                                            ObjAgencia.DemiteFuncionario();
                                            system("pause");
                                        }
                                        break;

                                        /*Case usado para op��o de exibi��o das passagens vendidas*/
                                        case 2:{

                                            /*Bloco de repeti��o das op��es de passagens vendidas*/
                                            while(1){
                                                Escolhas = Agencia.FuncionarioPresidenteRegistroDePassagens();
                                                switch(Escolhas){

                                                    /*Case para as passagens vendidas de �nibus*/
                                                    case 0:{
                                                        cout << endl << "EXECUTE O M�TODO DE EXIBI��O DE VEBDA DAS PASSAGENS DE �NIBUS" << endl;
                                                        system("pause");
                                                    }
                                                    break;

                                                    /*Case para as passagens vendidas de avi�o*/
                                                    case 1:{
                                                        cout << endl << "EXECUTE O M�TODO DE EXIBI��O DE VEBDA DAS PASSAGENS DE AVI�O" << endl;
                                                        system("pause");
                                                    }
                                                    break;

                                                    /*Case para as passagens vendidas de cruzeiro*/
                                                    case 2:{
                                                        cout << endl << "EXECUTE O M�TODO DE EXIBI��O DE VEBDA DAS PASSAGENS DE CRUZEIRO" << endl;
                                                        system("pause");
                                                    }
                                                    break;

                                                }/*Fecha o switch do bloco de repeti��o*/

                                                /*Trava para o bloco de repeti��o das passagens vendidas*/
                                                if(Escolhas == 99){
                                                    Escolhas = 0;
                                                    break;
                                                }

                                            } /*Fecha o while do bloco*/

                                        } /*Fecha o case 2 - para op��es das passagens vendidas*/
                                        break;

                                    } /*Fecha o switch do bloco das op��es do presidente*/

                                    /*Trava para o bloco das op��es do presidente*/
                                    if(Escolhas == 99){
                                        Escolhas = 0;
                                        break;
                                    }

                                }/*Feche a repeti��o das op��es do presidente*/

                            }/*Fehca o bloco do if de verifica��o de login do presidente*/

                            /*Bloco de usu�rio incorreto para o presidente*/
                            else{
                                system("cls");
                                cout << "\nUsu�rio ou senha incorretos" << endl;
                                system("pause");
                            }

                        }/*Fecha o case 0 - geral do presidente*/
                        break;

                        /*##################################################################################*/
                        /*############################ BLOCO PARA O GERENTE ################################*/
                        /*##################################################################################*/

                        case 1:{

                            /*Bloco para verifica��o de login do gerente*/
                            system("cls");
                            if (ObjAgencia.LoginFuncionario(Escolhas)){

                                /*Bloco de repeti��o das op��es gerais do gerente*/
                                while(1){
                                    Escolhas = Agencia.FuncionarioGerente();
                                    switch(Escolhas){

                                        /*Case para demitir funcion�rio (atrav�s do gerente)*/
                                        case 0:{
                                            ObjAgencia.DemiteFuncionario();
                                            system("pause");
                                        }
                                        break;

                                        /*Case para cadastras um funcion�rio*/
                                        case 1:{
                                            ObjAgencia.CadastraFuncionario();
                                            system("pause");
                                        }
                                        break;

                                        /*Case para exibir um funcion�rio atrav�s do email (para o gerente)*/
                                        case 2:{
                                            int posicao = ObjAgencia.RetornaPosicaoFuncionario();
                                            ObjAgencia.set_posicao_atual(posicao);
                                            ObjAgencia.ExibirFuncionario();
                                            system("pause");
                                        }
                                        break;

                                    }/*Fecha o switch do gerente*/

                                    /*Trava para o bloco de repeti��o das op��es do gerente*/
                                    if(Escolhas == 99){
                                        Escolhas = 0;
                                        break;
                                    }

                                }/*Fecha o bloco de repeti��o do gerente*/

                            }/*Fecha o bloco de verifica��o do login*/

                            /*Bloco de usu�rio incorreto para o gerente*/
                            else{
                                system("cls");
                                cout << "\nUsu�rio ou senha incorretos" << endl;
                                system("pause");
                            }

                        }/*Fecha o case 1 - Do gerente*/
                        break;

                        /*##################################################################################*/
                        /*########################## BLOCO PARA O FUNCION�RIO ###############################*/
                        /*##################################################################################*/

                        case 2:{

                            /*Bloco de verifica��o do login do funcion�rio (vendedor)*/
                            system("cls");
                            if(ObjAgencia.LoginFuncionario(Escolhas)){

                                /*Bloco de repeti��o para as op��es do funcion�rio*/
                                while(1){
                                    Escolhas = Agencia.FuncionarioFuncionario();
                                    switch(Escolhas){

                                        /*Case para a venda de passagens*/
                                        case 0:{

                                            /*Bloco de repeti��o para a venda de passagens*/
                                            while(1){
                                                Escolhas = Agencia.FuncionarioFuncionarioVenderPassagens();
                                                switch(Escolhas){

                                                    /*Case para a venda de passagens de avi�o*/
                                                    case 0:{
                                                        //cout << endl << "EXECUTE O M�TODO DE VENDA DE PASSAGENS DE AVI�O" << endl;
                                                        system("pause");
                                                    }
                                                    break;

                                                    /*Case para a venda de passagens de �nibus*/
                                                    case 1:{
                                                        cout << endl << "EXECUTE O M�TODO DE VENDA DE PASSAGENS DE �NIBUS" << endl;
                                                        system("pause");
                                                    }
                                                    break;

                                                    /*Case para a venda de passagens de cruzeiro*/
                                                    case 2:{
                                                        cout << endl << "EXECUTE O M�TODO VENDA DE PASSAGENS DE CRUZEIRO" << endl;
                                                        system("pause");
                                                    }
                                                    break;

                                                }/*Fecha o switch das op��es de vendas de passagens*/

                                                /*Trava para o bloco de repeti��o de venda de passagens*/
                                                if(Escolhas == 99){
                                                    Escolhas = 0;
                                                    break;
                                                }

                                            }/*Fecha o bloco de repeti��o de vendas de passagens*/

                                        }/*Fecha o case 0 - das vendas de passagens pelo funcion�rio*/
                                        break;

                                        /*Case respons�vbel por exibir os dados do funcion�rio (que est� logado)*/
                                        case 1:{
                                            ObjAgencia.RetornaPosicaoParaFuncionario();
                                            ObjAgencia.ExibirFuncionario();
                                            system("pause");
                                            system("cls");
                                        }
                                        break;

                                        /*Bloco de alter��o do funcion�rio logado*/
                                        case 2:{

                                            /*Bloco de repeti��o para as op��es do menu de altera��o de dados*/
                                            while(1){
                                                Escolhas = Agencia.FuncionarioAlteracaoDados();

                                                ObjAgencia.AlterarDadosFuncionario(Escolhas);
                                                system("pause");

                                                /*Trava do bloco de repeti��o das op��es de altera��o de dados*/
                                                if(Escolhas == 99){
                                                    Escolhas = 0;
                                                    break;
                                                }

                                            }/*Fecha o bloco de repeti��o de altera��o de dados*/

                                        }/*Fecha o case 2 - da altera��o de dados do funcion�rio (logado)*/
                                        break;

                                    }/*Fecha o switch de exibi��o de op��es do funcion�rio vendedor*/

                                    /*Trava do bloco de repeti��o de funcion�rios vendedor*/
                                    if(Escolhas == 99){
                                        Escolhas = 0;
                                        break;
                                    }

                                }/*Fecha o bloco de repeti��o das op��es do funcion�rio*/

                            }/*Fecha o if de verifica��o de login do funcio�rio*/

                            /*Bloco de login incorreto para o vendedor*/
                            else{
                                system("cls");
                                cout << "\nUsu�rio ou senha incorretos" << endl;
                                system("pause");
                            }

                        }/*Fecha o case 2 - das op��es do funcion�rio vendedor*/
                        break;

                    }/*Fecha o switch de exibi��o das op��es do funcion�rio*/

                    /*Trava do bloco de repeti��o do funcion�rio*/
                    if(Escolhas == 99){
                        Escolhas = 0;
                        break;
                    }

                }/*Fecha o bloco de repeti��o das op��es do funcion�rio*/

            }/*Fecha o case 0 - respons�vel pelo gerenciamento das op��es do funcion�rio*/
            break;

            /*##################################################################################*/
            /*########################### BLOCO PARA OS CLIENTES ###############################*/
            /*##################################################################################*/

            case 1:{

                /*Bloco de repeti��o para as op��es do cliente*/
                while(1){
                    Escolhas = Agencia.Cliente();
                    switch(Escolhas){

                        /*Case respons�vel para o cliente entrar nos sistema*/
                        case 0:{

                            /*Bloco de verifica��o de login do cliente*/
                            if(ObjAgencia.LoginCliente()){

                                /*Bloco de repeti��o para as op��es do cliente*/
                                while(1){
                                    Escolhas = Agencia.ClienteEntrar();
                                    switch(Escolhas){

                                        /*Case respons�vel pelas op��es de comprar uma passagem*/
                                        case 0:{

                                            /*Bloco de repeti��o de compra de passagens*/
                                            while(1){
                                                Escolhas = Agencia.ClienteComprarPassagens();
                                                switch(Escolhas){

                                                    /*Case resons�vel para compra de passagens de avi�o*/
                                                    case 0:{

                                                        /*Defini��o de vari�veis para montagem da passagem de avi�o, essas vari�veis
                                                        s� existem dentro desse case, por isso s�o definidas aqui, ao sair desse case
                                                        as vari�veis s�o destru�das*/

                                                        int DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDePassagem,
                                                        Regiao, Cidade, TipoDeViagem, Origem, Horario;

                                                        /*Foi escolhido o n�mero 999 para definir vari�veis n�o preenchidas pelo usu�rio, como
                                                        as vari�veis s�o definidas atrav�s de inteiros gerados no menu, o n�mero 999 n�o pode
                                                        ser gerado por engano nunda*/

                                                        DiaDeIda = MesDeIda = AnoDeIda = DiaDeVolta = MesDeVolta = AnoDeVolta = TipoDePassagem = 999;
                                                        Regiao = Origem = Cidade = Horario = 999;

                                                        /*Tipo de viagem, para viagens de avi�o � denidio como 0*/
                                                        TipoDeViagem = 0;

                                                        /*Bloco de repeti��o para as passagens de avi�o*/
                                                        while(1){
                                                            Escolhas = Agencia.ClienteCriacaoDePassagem();
                                                            switch(Escolhas){

                                                                /*Case para escolha de origem do avi�o*/
                                                                case 0:{
                                                                    Escolhas = Agencia.ClienteOrigem();

                                                                    /*Trava modelo cliente para escolha de origem*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        Origem = 999;
                                                                    }
                                                                    else{
                                                                        Origem = Escolhas;
                                                                    }
                                                                }
                                                                break;

                                                                /*Case para escolha do destino*/
                                                                case 1:{

                                                                    /*Bloco parar exibi��o das regi�es de destino*/
                                                                    Escolhas = Agencia.ClientePassagensRegioes();
                                                                    switch(Escolhas){

                                                                        /*Case para a regi�o centro-oeste*/
                                                                        case 0:{

                                                                            /*Defini��o de regi�o recebe o n�mero do case do switch*/
                                                                            Regiao = 0;

                                                                            Escolhas = Agencia.ClientePassagensCentroOeste();
                                                                            Cidade = Escolhas;

                                                                            /*Trava modelo cliente para a cidade de destino*/
                                                                            if(Escolhas == 99){
                                                                                Escolhas = 0;
                                                                                Cidade = 999;
                                                                            }
                                                                            else{
                                                                                Cidade = Escolhas;
                                                                            }
                                                                        }
                                                                        break;
                                                                        /*A repeti��o para os pr�ximos casos � padr�o ao anterior*/

                                                                        /*Case para regi�o nordeste*/
                                                                        case 1:{

                                                                            Regiao = 1;
                                                                            Escolhas = Agencia.ClientePassagensNordeste();
                                                                            Cidade = Escolhas;

                                                                            if(Escolhas == 99){
                                                                                Escolhas = 0;
                                                                                Cidade = 999;
                                                                            }
                                                                            else{
                                                                                Cidade = Escolhas;
                                                                            }

                                                                        }
                                                                        break;

                                                                        /*Case para a regi�o norte*/
                                                                        case 2:{

                                                                            Regiao = 2;
                                                                            Escolhas = Agencia.ClientePassagensNorte();
                                                                            Cidade = Escolhas;

                                                                            if(Escolhas == 99){
                                                                                Escolhas = 0;
                                                                                Cidade = 999;
                                                                            }
                                                                            else{
                                                                                Cidade = Escolhas;
                                                                            }
                                                                        }
                                                                        break;

                                                                        /*Case para a regi�o sudeste*/
                                                                        case 3:{

                                                                            Regiao = 3;
                                                                            Escolhas = Agencia.ClientePassagensSudeste();
                                                                            Cidade = Escolhas;

                                                                            if(Escolhas == 99){
                                                                                Escolhas = 0;
                                                                                Cidade = 999;
                                                                            }
                                                                            else{
                                                                                Cidade = Escolhas;
                                                                            }

                                                                        }
                                                                        break;

                                                                        /*Case para a regi�o Sul*/
                                                                        case 4:{

                                                                            Regiao = 4;
                                                                            Escolhas = Agencia.ClientePassagensSul();
                                                                            Cidade = Escolhas;

                                                                            if(Escolhas == 99){
                                                                                Escolhas = 0;
                                                                                Cidade = 999;
                                                                            }
                                                                            else{
                                                                                Cidade = Escolhas;
                                                                            }

                                                                        }
                                                                        break;

                                                                    }/*Fecha o switch para escolha de destino do avi�o*/

                                                                    /*Bloco de redefini��o de escolha*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        Regiao = 999;
                                                                    }

                                                                }/*Fecha o case 1 - respons�vvel pela escolha de desnito*/
                                                                break;

                                                                /*Case respons�vel pela escolha de tipo de passagem no avi�o*/
                                                                case 2:{
                                                                    Escolhas = Agencia.ClienteEscolhaDeTaxaDeAviao();
                                                                    TipoDePassagem = Escolhas;

                                                                    /*Trava modelo cliente para o tipo de passagem*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        TipoDePassagem = 999;
                                                                    }
                                                                    else{
                                                                        TipoDePassagem = Escolhas;
                                                                    }
                                                                }
                                                                break;

                                                                /*Case respons�vel pela escolha de op��o de datas*/
                                                                case 3:{

                                                                    /*Bloco de repeti��o para a inser��o de datas*/
                                                                    while(1){
                                                                        Escolhas = Agencia.ClienteInserindoData();
                                                                        switch(Escolhas){

                                                                            /*Case para a data de ida*/
                                                                            case 0:{

                                                                                /*Execute o m�todo de verifica��o para saber se foi digitado um valor v�lido
                                                                                ao final execute o m�todo de verifica��o para saber se a data inserida est� no passado
                                                                                ou mais de 2 anos no futuro*/

                                                                                cout << endl << "Digite a data de ida da sua viagem" << endl;
                                                                                cin >> DiaDeIda;
                                                                                cin >> MesDeIda;
                                                                                cin >> AnoDeIda;

                                                                                cout << endl << "Digite o hor�rio da sua viagem" << endl;
                                                                                cin >> Horario;

                                                                                system("pause");
                                                                            }
                                                                            break;

                                                                            /*Case para a data de volta*/
                                                                            case 1:{

                                                                                /*Execute o m�todo de verifica��o para saber se foi digitado um valor v�lido
                                                                                ao final execute o m�todo de verifica��o para saber se a data inserida est� no passado
                                                                                ou mais de 2 anos no futuro*/

                                                                                cout << endl << "Digite a data de volta da sua viagem" << endl;
                                                                                cin >> DiaDeVolta;
                                                                                cin >> MesDeVolta;
                                                                                cin >> AnoDeVolta;

                                                                                cout << endl << "Digite o hor�rio da sua viagem" << endl;
                                                                                cin >> Horario;

                                                                                system("pause");
                                                                            }
                                                                            break;

                                                                        }/*FEcha o switch respons�vel pela exibi��o das datas*/

                                                                        /*Trava para o bloco de repeti��o inser��o de datas*/
                                                                        if(Escolhas == 99){
                                                                            Escolhas = 0;
                                                                            break;
                                                                        }

                                                                    }/*Fecha o bloco de repeti��o de datas*/

                                                                }/*Fecha o case 3 respons�vel pela escolha de op��o de datas*/
                                                                break;

                                                                /*Ao terminar de montar a passagem o case 4 � respons�vel pela confirma��o
                                                                e gera��o da passagem, para adicionar aos vector da ag�ncia*/
                                                                case 4:{

                                                                    ObjAgencia.PassaParaOGeradorDePassagens(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDePassagem,
                                                                    Regiao, Cidade, TipoDeViagem, Origem, Horario);

                                                                    system("pause");
                                                                }
                                                                break;

                                                            }/*Fecha o switch respons�vel pela cria��o de passagens de avi�o*/

                                                            /*Trava para o bloco de repeti��o de passagens*/
                                                            if(Escolhas == 99){
                                                                Escolhas = 0;
                                                                break;
                                                            }

                                                        }/*Fecha o bloco de repeti��o das op��es de cria��o de passagem de avi�o*/

                                                    }/*Fecha o case 0 - Respons�vel pelas op��es de venda de passagem de avi�o*/
                                                    break;

                                                    /*Case resons�vel para compra de passagens de �nibus*/
                                                    case 1:{

                                                        /*Defini��o de vari�veis para montagem da passagem de �nibus, essas vari�veis
                                                        s� existem dentro desse case, por isso s�o definidas aqui, ao sair desse case
                                                        as vari�veis s�o destru�das*/

                                                        int DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDePassagem,
                                                        Regiao, Cidade, TipoDeViagem, Origem, Horario;

                                                        /*Foi escolhido o n�mero 999 para definir vari�veis n�o preenchidas pelo usu�rio, como
                                                        as vari�veis s�o definidas atrav�s de inteiros gerados no menu, o n�mero 999 n�o pode
                                                        ser gerado por engano nunda*/

                                                        DiaDeIda = MesDeIda = AnoDeIda = DiaDeVolta = MesDeVolta = AnoDeVolta = TipoDePassagem = 999;
                                                        Regiao = Origem = Cidade = Horario = 999;

                                                        /*Tipo de viagem, para viagens de �nibus � denidio como 0*/
                                                        TipoDeViagem = 1;
                                                        /*As passagens de �nibus possuem apenas um hor�rio*/
                                                        Horario = 2;

                                                        /*Bloco de repeti��o para as passagens de �nibus*/
                                                        while(1){
                                                            Escolhas = Agencia.ClienteCriacaoDePassagem();
                                                            switch(Escolhas){

                                                                /*Case para escolha de origem do �nibus*/
                                                                case 0:{
                                                                    Escolhas = Agencia.ClienteOrigem();

                                                                    /*Trava modelo cliente para escolha de origem*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        Origem = 999;
                                                                    }
                                                                    else{
                                                                        Origem = Escolhas;
                                                                    }
                                                                }
                                                                break;

                                                                /*Case para escolha do destino*/
                                                                case 1:{

                                                                    /*Bloco parar exibi��o das regi�es de destino*/
                                                                    Escolhas = Agencia.ClientePassagensRegioes();
                                                                    switch(Escolhas){

                                                                        /*Case para a regi�o centro-oeste*/
                                                                        case 0:{

                                                                            /*Defini��o de regi�o recebe o n�mero do case do switch*/
                                                                            Regiao = 0;

                                                                            Escolhas = Agencia.ClientePassagensCentroOeste();
                                                                            Cidade = Escolhas;

                                                                            /*Trava modelo cliente para a cidade de destino*/
                                                                            if(Escolhas == 99){
                                                                                Escolhas = 0;
                                                                                Cidade = 999;
                                                                            }
                                                                            else{
                                                                                Cidade = Escolhas;
                                                                            }
                                                                        }
                                                                        break;
                                                                        /*A repeti��o para os pr�ximos casos � padr�o ao anterior*/

                                                                        /*Case para regi�o nordeste*/
                                                                        case 1:{

                                                                            Regiao = 1;
                                                                            Escolhas = Agencia.ClientePassagensNordeste();
                                                                            Cidade = Escolhas;

                                                                            if(Escolhas == 99){
                                                                                Escolhas = 0;
                                                                                Cidade = 999;
                                                                            }
                                                                            else{
                                                                                Cidade = Escolhas;
                                                                            }

                                                                        }
                                                                        break;

                                                                        /*Case para a regi�o norte*/
                                                                        case 2:{

                                                                            Regiao = 2;
                                                                            Escolhas = Agencia.ClientePassagensNorte();
                                                                            Cidade = Escolhas;

                                                                            if(Escolhas == 99){
                                                                                Escolhas = 0;
                                                                                Cidade = 999;
                                                                            }
                                                                            else{
                                                                                Cidade = Escolhas;
                                                                            }
                                                                        }
                                                                        break;

                                                                        /*Case para a regi�o sudeste*/
                                                                        case 3:{

                                                                            Regiao = 3;
                                                                            Escolhas = Agencia.ClientePassagensSudeste();
                                                                            Cidade = Escolhas;

                                                                            if(Escolhas == 99){
                                                                                Escolhas = 0;
                                                                                Cidade = 999;
                                                                            }
                                                                            else{
                                                                                Cidade = Escolhas;
                                                                            }

                                                                        }
                                                                        break;

                                                                        /*Case para a regi�o Sul*/
                                                                        case 4:{

                                                                            Regiao = 4;
                                                                            Escolhas = Agencia.ClientePassagensSul();
                                                                            Cidade = Escolhas;

                                                                            if(Escolhas == 99){
                                                                                Escolhas = 0;
                                                                                Cidade = 999;
                                                                            }
                                                                            else{
                                                                                Cidade = Escolhas;
                                                                            }

                                                                        }
                                                                        break;

                                                                    }/*Fecha switch para escolha de destino do �nibus*/

                                                                    /*Bloco de redefini��o de escolha*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        Regiao = 999;
                                                                    }

                                                                }/*Fecha o case 1 - respons�vvel pela escolha de desnito*/
                                                                break;

                                                                /*Case respons�vel pela escolha de tipo de passagem no �nibus*/
                                                                case 2:{
                                                                    Escolhas = Agencia.ClienteEscolhaDeTaxaDeAviao();
                                                                    TipoDePassagem = Escolhas;

                                                                    /*Trava modelo cliente para o tipo de passagem*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        TipoDePassagem = 999;
                                                                    }
                                                                    else{
                                                                        TipoDePassagem = Escolhas;
                                                                    }
                                                                }
                                                                break;

                                                                /*Case respons�vel pela escolha de op��o de datas*/
                                                                case 3:{

                                                                    /*Bloco de repeti��o para a inser��o de datas*/
                                                                    while(1){
                                                                        Escolhas = Agencia.ClienteInserindoData();
                                                                        switch(Escolhas){

                                                                            /*Case para a data de ida*/
                                                                            case 0:{

                                                                                /*Execute o m�todo de verifica��o para saber se foi digitado um valor v�lido
                                                                                ao final execute o m�todo de verifica��o para saber se a data inserida est� no passado
                                                                                ou mais de 2 anos no futuro*/

                                                                                cout << endl << "Digite a data de ida da sua viagem" << endl;
                                                                                cin >> DiaDeIda;
                                                                                cin >> MesDeIda;
                                                                                cin >> AnoDeIda;

                                                                                system("pause");
                                                                            }
                                                                            break;

                                                                            /*Case para a data de volta*/
                                                                            case 1:{

                                                                                /*Execute o m�todo de verifica��o para saber se foi digitado um valor v�lido
                                                                                ao final execute o m�todo de verifica��o para saber se a data inserida est� no passado
                                                                                ou mais de 2 anos no futuro*/

                                                                                cout << endl << "Digite a data de volta da sua viagem" << endl;
                                                                                cin >> DiaDeVolta;
                                                                                cin >> MesDeVolta;
                                                                                cin >> AnoDeVolta;

                                                                                system("pause");
                                                                            }
                                                                            break;

                                                                        }/*FEcha o switch respons�vel pela exibi��o das datas*/

                                                                        /*Trava para o bloco de repeti��o inser��o de datas*/
                                                                        if(Escolhas == 99){
                                                                            Escolhas = 0;
                                                                            break;
                                                                        }

                                                                    }/*Fecha o bloco de repeti��o de datas*/

                                                                }/*Fecha o case 3 respons�vel pela escolha de op��o de datas*/
                                                                break;

                                                                /*Ao terminar de montar a passagem o case 4 � respons�vel pela confirma��o
                                                                e gera��o da passagem, para adicionar aos vector da ag�ncia*/
                                                                case 4:{

                                                                    ObjAgencia.PassaParaOGeradorDePassagens(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDePassagem,
                                                                    Regiao, Cidade, TipoDeViagem, Origem, Horario);

                                                                    system("pause");
                                                                }
                                                                break;

                                                            }/*Fecha o switch respons�vel pela cria��o de passagens*/

                                                            /*Trava para o bloco de repeti��o de cria��o de passagens de �nibus*/
                                                            if(Escolhas == 99){
                                                                Escolhas = 0;
                                                                break;
                                                            }

                                                        }/*Fecha o bloco de repeti��o das op��es de cria��o de passagem de �nibus*/

                                                    }/*Fecha o case 0 - Respons�vel pelas op��es de venda de passagem de �nibus*/
                                                    break;

                                                    /*Case respons�vel para cria��o de passagens de cruzeiro*/
                                                    case 2:{

                                                        /*Bloco de repeti��o para cria��o de passagens de cruzeiro*/
                                                        while(1){
                                                            Escolhas = Agencia.ClientePassagensCruzeiro();
                                                            switch(Escolhas){

                                                                /*Respons�vel para as passagens de cruzeiro (salvador - caribe)*/
                                                                case 0:{
                                                                    cout << endl << "SER� CHAMADO OS M�TODOS RESPONS�VEIS PARA A MONTAGEM DE PASSGEM DE CRUZEIRO" << endl;
                                                                    system("pause");
                                                                }
                                                                break;

                                                                /*Respons�vel pelas passagens de cruzeiro (salvador - europa)*/
                                                                case 1:{
                                                                    cout << endl << "SER� CHAMADO OS M�TODOS RESPONS�VEIS PARA A MONTAGEM DE PASSGEM DE CRUZEIRO" << endl;
                                                                    system("pause");
                                                                }
                                                                break;

                                                            }/*Fecha o switch respons�vel pelas escolhas de passagens de cruzeiro*/

                                                            /*Trava do bloco de repeti��o do cruzeiro*/
                                                            if(Escolhas == 99){
                                                                Escolhas = 0;
                                                                break;
                                                            }

                                                        }/*Fecha o bloco de repeti��o para a gera��o de passagens de cruzeiro*/

                                                    }/*Fecha o case 2 respons�vel pelas op��es de cria��o de passagem de cruzeiro*/

                                                }/*Fecha o switch da esolha do tipo de passagem*/

                                                /*Trava para repeti��o do bloco de escolhas do tipo de passagem*/
                                                if(Escolhas == 99){
                                                    Escolhas = 0;
                                                    break;
                                                }

                                            }/*Fecha o bloco de repeti��o para a escolha do tipo de passagem*/

                                        }/*Fecha o case 0 - respons�vel pelas escolhas do tipo de passagem*/
                                        break;

                                        /*Respons�vel pela exibi��o e escolha de h�teis*/
                                        case 1:{

                                            /*Case apenas para mostrar os cr�ditos dos respons�veis pela cria��o do projeto
                                            como forma de brincadeira, pois tinhamos a ideia de implementa um sistema de reserva h�teis
                                            em conjunto com o sistema de venda de passagens*/

                                            system("cls");
                                            cout << "Presado cliente, infelizmente nossa parceria com o ramo de h�teis foi cancelada." << endl;
                                            cout << "Talvez em um futuro prox�mo, voltaremos a utilizar o sistema de parceria com h�teis" << endl;
                                            cout << "Temos para voc� a recomenda��o de poss�veis h�teis, para que supra sua necessidade:" << endl;
                                            cout << "H�tel: Caio Brito" << endl;
                                            cout << "H�tel: Jo�o Victor" << endl;
                                            cout << "H�tel: Jos� Savyo" << endl;
                                            cout << "H�tel: Mateus Figueiredo" << endl;
                                            system("pause");
                                        }
                                        break;

                                        /*Case para o m�todo de cancelamento de passagens*/
                                        case 2:{
                                            cout << endl << "EXECUTE O M�TODO DE CANCELAMENTO DE PASSAGENS" << endl;
                                            system("pause");
                                        }
                                        break;

                                        /*Case para a altera��o de dados do cliente (logado)*/
                                        case 3:{

                                            /*Bloco de repeti��o para a altera��o de dados do cliente*/
                                            while(1){
                                                Escolhas = Agencia.ClienteEditarCadastro();

                                                /*Trava para o bloco de repeti��o para a altera��o de dados do cliente*/
                                                if(Escolhas == 99){
                                                    Escolhas = 0;
                                                    break;
                                                }
                                                ObjAgencia.AlterarDadosCliente(Escolhas);
                                            }
                                        }
                                        break;

                                        /*Case respons�vel para exibi��o dos dados do cliente (logado)*/
                                        case 4:{
                                            cout << "EXECUTE O M�TODO DE EXIBI��O DOS DADOS DO CLIENTE" << endl;
                                            system("pause");
                                        }
                                        break;

                                        /*Case repons�vel para exibi��o das passagens compradas pelo cliente*/
                                        case 5:{
                                            //cout << "EXECUTE O M�TODO DE EXIBI��O DAS PASSAGENS DO CLIENTE" << endl;
                                            //cout << "AS PASSAGENS S� APARECEM AQUI QUANDO FOREM CONFIRMADAS AS VENDAS PELO FUNCION�RIO" << endl;
                                            ObjAgencia.ImprimaPassagemVendida();
                                            system("pause");
                                        }

                                        /*Case respons�vel por exibir os custos das passagens atuais do cliente*/
                                        case 6:{
                                            //cout << "EXECUTE O M�TODO QUE EXIBE AS PASSAGENS QUE FALTAM SER CONFIRMADAS PELO FUNCION�RIO" << endl;
                                            ObjAgencia.ImprimaPassagemPendente();
                                            system("pause");
                                        }
                                        break;

                                    }/*Fecha o switch do cliente respons�vel pela fun��o entrar*/

                                    /*Trava para o bloco de repeti��o das func�es do cliente, entrar*/
                                    if(Escolhas == 99){
                                        Escolhas = 0;
                                        break;
                                    }

                                }/*Fecha o bloco de repeti��o respons�vel pela exibi��o das escolhas do cliente, entrar*/

                            }/*Fecha o bloco if de login do cliente*/

                            /*Bloco de exibi��o de mensagem de login incorreto para o cliente*/
                            else{
                                system("cls");
                                cout << "\nUsu�rio ou senha incorretos" << endl;
                                system("pause");
                            }

                        }/*Fecha o case 0 - respons�vel pela entrada na fun��o entrar (do cliente)*/
                        break;

                        /*Respons�vel pela fun��o cadastrar um cliente*/
                        case 1:{
                            ObjAgencia.CadastraCliente();
                            system("pause");
                        }
                        break;

                    }/*Fecha o switch respons�vel pelas funcion��es do cliente (entrar e cadastra-se)*/

                    /*Trava para o bloco de repeti��o do sistema de exibi��o de cliente(entrar e cadastra-se)*/
                    if(Escolhas == 99){
                        Escolhas = 0;
                        break;
                    }

                }/*Fecha o bloco de repeti��o do sistema de exibi��o de cliente(entrar e cadastrar-se)*/

            }/*Fecha o case 1 - respons�vel pela intera��o com o cliente*/

        }/*Fecha o primeiro switch aberto na main*/

        /*Trava modelo geral para o primeiro while aberto na main*/
        if(Escolhas == 99){
            Escolhas = 0;
            cout << endl << "O programa foi encerrado" << endl;
            system("pause");
            break;
        }

    }/*Fecha o primeiro while aberto na main*/

    /*Encerramento do programa*/
    return 0;
}
