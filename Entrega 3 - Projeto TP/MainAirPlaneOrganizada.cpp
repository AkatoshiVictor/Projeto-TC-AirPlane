/*As bibliotecas inclu�das s�o usadas
tamb�m nas outras classes*/

#include <conio.h>
#include <iostream>
#include <locale>
#include <vector>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

/*Inclus�o dos arquivos necess�rios para a execu��o da main*/

#include "Menus.cpp"
#include "AgenciaDeViagens.cpp" /*As outras classes s�o iclu�das em ag�ncia*/


/*Bloco de fun��es para auxiliar o sistemna de datas usado nas verifica��es da main
Como a biblioteca time trata de vari�veis que s�o extra�das do sistema, todas as opera��es
feitas com essas informa��es, utilizamos na main, visando que, o usu�rio poderia ter acesso
e visualiar que informa��es do sistema est�o sendo acessadas (Essa escolha de aplica��o no
c�digo, tem fundamento apenas te�rico, e foi escolhida para car�ter de explica��o do projeto
em sua apresenta��o) - Poderia ser utilizado um sistema de m�todos*/

int DefAnoAtual(){
    time_t Ano, t;
    time(&t);
    tm* ano_atual = localtime(&Ano);

    return ano_atual->tm_year+1900;
}

int DefMesAtual(){
    time_t Mes, t;
    time(&t);
    tm* mes_atual = localtime(&Mes);

    return mes_atual->tm_mon+1;
}

int DefDiaAtual(){
    time_t Dia, t;
    time(&t);
    tm* dia_atual = localtime(&Dia);

    return dia_atual->tm_mday;
}
bool verifica_data_cruzeiro(int dia, int mes, int ano){
    time_t tempo_final, t;

    time(&t);

    tm* tempo_final_info=localtime(&tempo_final);

    tempo_final_info->tm_year=ano-1900;
    tempo_final_info->tm_mon=mes-1;
    tempo_final_info->tm_mday=dia;
    tempo_final_info->tm_hour=21;

    tempo_final=mktime(tempo_final_info);

    float dif=difftime(tempo_final, t)/3600;

    if(dif<48){
        return false;
    }
    else{
        return true;
    }
}


bool verifica_data_volta(int dia_ida, int mes_ida, int ano_ida, int dia_volta, int mes_volta, int ano_volta){

    time_t tempo_inicial, tempo_final;

    tempo_inicial=0;
    tempo_final=0;

    tm *tempo_inicial_info=localtime(&tempo_inicial);
    tempo_inicial_info->tm_year=ano_ida-1900;
    tempo_inicial_info->tm_mon=mes_ida-1;
    tempo_inicial_info->tm_mday=dia_ida;

    tempo_inicial=mktime(tempo_inicial_info);

    tm* tempo_final_info=localtime(&tempo_final);
    tempo_final_info->tm_year=ano_volta-1900;
    tempo_final_info->tm_mon=mes_volta-1;
    tempo_final_info->tm_mday=dia_volta;

    tempo_final=mktime(tempo_final_info);

    float dif=difftime(tempo_final, tempo_inicial)/3600;

    if(dif>=24){
        return true;
    }
    else{
        return false;
    }
}


void DatePlusDays( struct tm* date, int days )
{
    const time_t ONE_DAY = 24 * 60 * 60 ;

    // Seconds since start of Epoch
    time_t date_seconds = mktime( date ) + (days * ONE_DAY) ;

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *date = *localtime( &date_seconds ) ; ;
}

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

    /*Vari�veis para montagem da passagem de avi�o, �nibus e cruzeiro
    Essas vari�veis s�o redefinidas dentro de cada case*/

        int DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDePassagem,
        Regiao, Cidade, TipoDeViagem, Origem, Horario;

    /*Variaveis usadas para definir os hor�rios para serem feitas as valida��es da datas*/
        int HoraioAuxiliarVolta, HoraioAuxiliarIda;

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
                                            ObjAgencia.ImprimiReceita();
                                        }
                                        break;

                                        /*Case usado para op��o de demitir funcion�rios (pelo presidente)*/
                                        case 1:{
                                            ObjAgencia.DemiteFuncionario();
                                            system("pause");
                                        }
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
                                                        ObjAgencia.VenderPassagem(0);
                                                        system("pause");
                                                    }
                                                    break;

                                                    /*Case para a venda de passagens de �nibus*/
                                                    case 1:{
                                                        //cout << endl << "EXECUTE O M�TODO DE VENDA DE PASSAGENS DE �NIBUS" << endl;
                                                        ObjAgencia.VenderPassagem(1);
                                                        system("pause");
                                                    }
                                                    break;

                                                    /*Case para a venda de passagens de cruzeiro*/
                                                    case 2:{
                                                        //cout << endl << "EXECUTE O M�TODO VENDA DE PASSAGENS DE CRUZEIRO" << endl;
                                                        ObjAgencia.VenderPassagem(2);
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
                            system("cls");
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

                                                                                /*Variavel booleana e do While respons�veis por verificar se a data
                                                                                de embarque est� dentro dos parametros exigidos*/
                                                                                bool controle = true;
                                                                                bool auxiliar = true;

                                                                                do{
                                                                                   cin.exceptions(istream::failbit);

                                                                                   do{
                                                                                       try {
                                                                                            cout << "\n\ndigite a data de ida de sua viagem:" << endl;
                                                                                            cin >> DiaDeIda;
                                                                                            cin >> MesDeIda;
                                                                                            cin >> AnoDeIda;
                                                                                            auxiliar = true;

                                                                                            if(ObjAgencia.VerificadorDeDataPossivel(DiaDeIda, MesDeIda,AnoDeIda) == true){
                                                                                                if(!((MesDeIda < 1)||(MesDeIda > 12)))
                                                                                                    continue;
                                                                                                else{
                                                                                                    cout << endl << "A data inserida n�o � v�lida (ou n�o existe) no nosso sistema" << endl;
                                                                                                    auxiliar = false;
                                                                                                }
                                                                                            }
                                                                                            else{
                                                                                                cout << endl << "A data inserida n�o � v�lida (ou n�o existe) no nosso sistema" << endl;
                                                                                                auxiliar = false;
                                                                                            }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inv�lido, por favor, digite sua data como n�meros inteiros." << endl;
                                                                                            cin.clear();
                                                                                            string digitada;
                                                                                            getline(cin, digitada);
                                                                                        }
                                                                                    }while(auxiliar == false);

                                                                                    do{
                                                                                       try {
                                                                                            cout << endl << "Digite o hor�rio da sua viagem" << endl;
                                                                                            cin >> Horario;
                                                                                            auxiliar = true;

                                                                                            if(Horario<0||Horario>2){
                                                                                                cout << "ERRO 0xC0000005 - Caractere inv�lido" << endl;
                                                                                                auxiliar = false;
                                                                                                }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inv�lido, por favor, digite sua data como n�meros inteiros." << endl;
                                                                                            cin.clear();
                                                                                            string digitada;
                                                                                            getline(cin, digitada);
                                                                                        }
                                                                                    }while(auxiliar == false);

                                                                                    switch(Horario){
                                                                                        case 0:{
                                                                                            HoraioAuxiliarIda = 10;
                                                                                        }
                                                                                        break;
                                                                                        case 1:{
                                                                                            HoraioAuxiliarIda = 15;
                                                                                        }
                                                                                        break;
                                                                                        case 2:{
                                                                                            HoraioAuxiliarIda = 21;
                                                                                        }
                                                                                        break;
                                                                                    }

                                                                                    if(ObjAgencia.verifica_data_ida(DiaDeIda, MesDeIda, AnoDeIda, HoraioAuxiliarIda) == true){
                                                                                        controle = true;
                                                                                    }
                                                                                    else{
                                                                                        cout<<"A Data deve ser no presente ou futuro (48 horas de anteced�ncia)"<<endl;
                                                                                        system("pause");
                                                                                        system("cls");
                                                                                        controle = false;
                                                                                    }

                                                                                }while(controle == false);
                                                                                /*Encerra o sistema de verifica��o de datas poss�veis para compra de passagens*/

                                                                                cout << endl;
                                                                                system("pause");

                                                                            }/*Fecha o case 1 de datas*/
                                                                            break;

                                                                            /*Case para a data de volta*/
                                                                            case 1:{
                                                                                /*Variavel booleana e do While respons�veis por verificar se a data
                                                                                de embarque est� dentro dos parametros exigidos*/
                                                                                bool controle = true;
                                                                                bool auxiliar = true;

                                                                                do{

                                                                                     do{
                                                                                       try {
                                                                                            cout << "\n\ndigite a data de volta de sua viagem:" << endl;
                                                                                            cin >> DiaDeVolta;
                                                                                            cin >> MesDeVolta;
                                                                                            cin >> AnoDeVolta;
                                                                                            auxiliar = true;

                                                                                            if(!(DiaDeVolta == 0 && MesDeVolta == 0 && AnoDeVolta == 0)){

                                                                                                if(ObjAgencia.VerificadorDeDataPossivel(DiaDeVolta, MesDeVolta, AnoDeVolta) == true){
                                                                                                    if(!((MesDeVolta < 1)||(MesDeVolta > 12)))
                                                                                                        continue;
                                                                                                    else{
                                                                                                        cout << endl << "A data inserida n�o � v�lida (ou n�o existe) no nosso sistema" << endl;
                                                                                                        auxiliar = false;
                                                                                                    }
                                                                                                }
                                                                                                else{
                                                                                                    cout << endl << "A data inserida n�o � v�lida (ou n�o existe) no nosso sistema" << endl;
                                                                                                    auxiliar = false;
                                                                                                }

                                                                                                if(verifica_data_volta(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta) == true){
                                                                                                    auxiliar = true;
                                                                                                }
                                                                                                else{
                                                                                                    cout << endl << "A data inserida n�o � v�lida (ou n�o existe) no nosso sistema" << endl;
                                                                                                    system("pause");
                                                                                                    system("cls");
                                                                                                    auxiliar = false;
                                                                                                }
                                                                                            }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inv�lido, por favor, digite sua data como n�meros inteiros." << endl;
                                                                                            cin.clear();
                                                                                            string digitada;
                                                                                            getline(cin, digitada);
                                                                                        }
                                                                                    }while(auxiliar == false);

                                                                                    if(verifica_data_volta(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta) == true){
                                                                                        controle = true;
                                                                                    }
                                                                                    else{
                                                                                        cout<<"A Data deve ser no presente ou futuro (48 horas de anteced�ncia)"<<endl;
                                                                                        system("pause");
                                                                                        system("cls");
                                                                                        controle = false;
                                                                                    }

                                                                                }while(controle == false);

                                                                                cout << endl;
                                                                                system("pause");

                                                                            }/*Fecha o case 1 de datas*/
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

                                                                    cout << endl;

                                                                    ObjAgencia.PassaParaOGeradorDePassagens(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDePassagem,
                                                                    Regiao, Cidade, TipoDeViagem, Origem, Horario);

                                                                    cout << endl;
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
                                                                    Escolhas = Agencia.ClienteEscolhaDeTaxaDeOnibus();
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

                                                                                /*Variavel booleana e do While respons�veis por verificar se a data
                                                                                de embarque est� dentro dos parametros exigidos*/
                                                                                bool controle = true;
                                                                                bool auxiliar = true;

                                                                                do{
                                                                                   cin.exceptions(istream::failbit);

                                                                                   do{
                                                                                       try {
                                                                                            cout << "\n\ndigite a data de ida de sua viagem:" << endl;
                                                                                            cin >> DiaDeIda;
                                                                                            cin >> MesDeIda;
                                                                                            cin >> AnoDeIda;
                                                                                            auxiliar = true;

                                                                                            if(ObjAgencia.VerificadorDeDataPossivel(DiaDeIda, MesDeIda,AnoDeIda) == true){
                                                                                                if(!((MesDeIda < 1)||(MesDeIda > 12)))
                                                                                                    continue;
                                                                                                else{
                                                                                                    cout << endl << "A data inserida n�o � v�lida (ou n�o existe) no nosso sistema" << endl;
                                                                                                    auxiliar = false;
                                                                                                }
                                                                                            }
                                                                                            else{
                                                                                                cout << endl << "A data inserida n�o � v�lida (ou n�o existe) no nosso sistema" << endl;
                                                                                                auxiliar = false;
                                                                                            }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inv�lido, por favor, digite sua data como n�meros inteiros." << endl;
                                                                                            cin.clear();
                                                                                            string digitada;
                                                                                            getline(cin, digitada);
                                                                                        }
                                                                                    }while(auxiliar == false);

                                                                                    do{
                                                                                       try {
                                                                                            cout << endl << "Digite o hor�rio da sua viagem" << endl;
                                                                                            cin >> Horario;
                                                                                            auxiliar = true;

                                                                                            if(Horario<0||Horario>2){
                                                                                                cout << "ERRO 0xC0000005 - Caractere inv�lido" << endl;
                                                                                                auxiliar = false;
                                                                                                }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inv�lido, por favor, digite sua data como n�meros inteiros." << endl;
                                                                                            cin.clear();
                                                                                            string digitada;
                                                                                            getline(cin, digitada);
                                                                                        }
                                                                                    }while(auxiliar == false);

                                                                                    switch(Horario){
                                                                                        case 0:{
                                                                                            HoraioAuxiliarIda = 10;
                                                                                        }
                                                                                        break;
                                                                                        case 1:{
                                                                                            HoraioAuxiliarIda = 15;
                                                                                        }
                                                                                        break;
                                                                                        case 2:{
                                                                                            HoraioAuxiliarIda = 21;
                                                                                        }
                                                                                        break;
                                                                                    }

                                                                                    if(ObjAgencia.verifica_data_ida(DiaDeIda, MesDeIda, AnoDeIda, HoraioAuxiliarIda) == true){
                                                                                        controle = true;
                                                                                    }
                                                                                    else{
                                                                                        cout<<"A Data deve ser no presente ou futuro (48 horas de anteced�ncia)"<<endl;
                                                                                        system("pause");
                                                                                        system("cls");
                                                                                        controle = false;
                                                                                    }

                                                                                }while(controle == false);
                                                                                /*Encerra o sistema de verifica��o de datas poss�veis para compra de passagens*/

                                                                                cout << endl;
                                                                                system("pause");
                                                                            }/*Fecha o case 0 de datas*/
                                                                            break;

                                                                            /*Case para a data de volta*/
                                                                            case 1:{
                                                                                /*Variavel booleana e do While respons�veis por verificar se a data
                                                                                de embarque est� dentro dos parametros exigidos*/
                                                                                bool controle = true;
                                                                                bool auxiliar = true;

                                                                                do{

                                                                                     do{
                                                                                       try {
                                                                                            cout << "\n\ndigite a data de volta de sua viagem:" << endl;
                                                                                            cin >> DiaDeVolta;
                                                                                            cin >> MesDeVolta;
                                                                                            cin >> AnoDeVolta;
                                                                                            auxiliar = true;

                                                                                            if(!(DiaDeVolta == 0 && MesDeVolta == 0 && AnoDeVolta == 0)){

                                                                                                if(ObjAgencia.VerificadorDeDataPossivel(DiaDeVolta, MesDeVolta, AnoDeVolta) == true){
                                                                                                    if(!((MesDeVolta < 1)||(MesDeVolta > 12)))
                                                                                                        continue;
                                                                                                    else{
                                                                                                        cout << endl << "A data inserida n�o � v�lida (ou n�o existe) no nosso sistema" << endl;
                                                                                                        auxiliar = false;
                                                                                                    }
                                                                                                }
                                                                                                else{
                                                                                                    cout << endl << "A data inserida n�o � v�lida (ou n�o existe) no nosso sistema" << endl;
                                                                                                    auxiliar = false;
                                                                                                }

                                                                                                if(verifica_data_volta(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta) == true){
                                                                                                    auxiliar = true;
                                                                                                }
                                                                                                else{
                                                                                                    cout << endl << "A data inserida n�o � v�lida (ou n�o existe) no nosso sistema" << endl;
                                                                                                    system("pause");
                                                                                                    system("cls");
                                                                                                    auxiliar = false;
                                                                                                }
                                                                                            }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inv�lido, por favor, digite sua data como n�meros inteiros." << endl;
                                                                                            cin.clear();
                                                                                            string digitada;
                                                                                            getline(cin, digitada);
                                                                                        }
                                                                                    }while(auxiliar == false);

                                                                                    if(verifica_data_volta(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta) == true){
                                                                                        controle = true;
                                                                                    }
                                                                                    else{
                                                                                        cout<<"A Data deve ser no presente ou futuro (48 horas de anteced�ncia)"<<endl;
                                                                                        system("pause");
                                                                                        system("cls");
                                                                                        controle = false;
                                                                                    }

                                                                                }while(controle == false);

                                                                                cout << endl;
                                                                                system("pause");
                                                                            }/*Fecha o case 1 de datas*/
                                                                            break;

                                                                        }/*Fecha o switch respons�vel pela exibi��o das datas*/

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

                                                                    cout << endl;

                                                                    ObjAgencia.PassaParaOGeradorDePassagens(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDePassagem,
                                                                    Regiao, Cidade, TipoDeViagem, Origem, Horario);

                                                                    cout << endl;
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

                                                        /*Foi escolhido o n�mero 999 para definir vari�veis n�o preenchidas pelo usu�rio, como
                                                        as vari�veis s�o definidas atrav�s de inteiros gerados no menu, o n�mero 999 n�o pode
                                                        ser gerado por engano nunda*/

                                                        DiaDeIda = MesDeIda = AnoDeIda = DiaDeVolta = MesDeVolta = AnoDeVolta = TipoDePassagem = 999;

                                                        /*Tipo de viagem, para viagens de �nibus � denidio como 0*/
                                                        TipoDeViagem = 2;

                                                        /*O cruzeiro n�o possu� as seguinte vari�veis, o valor delas � iniciado como 0, para que se possa
                                                        utilizar o mesmo m�todo para constru��o das passagens*/

                                                        Regiao = Origem = Cidade = Horario = 0;

                                                        /*Bloco de repeti��o para cria��o de passagens de cruzeiro*/
                                                        while(1){
                                                            Escolhas = Agencia.ClientePassagensCruzeiro();
                                                            switch(Escolhas){

                                                                /*Respons�vel para as passagens de cruzeiro (salvador - EUROPA)*/
                                                                case 0:{

                                                                    /*Variavel booleana e do While respons�veis por verificar se a data
                                                                    de embarque est� dentro dos parametros exigidos*/
                                                                    bool controle = true;
                                                                    bool auxiliar = true;

                                                                    do{
                                                                        cin.exceptions(istream::failbit);
                                                                        do{
                                                                            try {
                                                                                cout << endl << "Digite a data de ida da sua viagem" << endl;
                                                                                cin >> DiaDeIda;
                                                                                cin >> MesDeIda;
                                                                                cin >> AnoDeIda;
                                                                                auxiliar = true;

                                                                                if(DiaDeIda!=7&&DiaDeIda!=21||MesDeIda<1&&MesDeIda>12||AnoDeIda<1){
                                                                                    cout << "Datas inv�lidas" << endl;
                                                                                    auxiliar = false;
                                                                                }
                                                                            }catch (ios_base::failure &fail) {
                                                                                auxiliar = false;
                                                                                cout << "\nERRO 0xC0000005 - Caractere inv�lido, por favor, digite sua data como n�meros inteiros." << endl;
                                                                                cin.clear();
                                                                                string digitada;
                                                                                getline(cin, digitada);
                                                                            }
                                                                        }while(auxiliar == false);

                                                                        time_t tempo_final, t;

                                                                        time(&t);

                                                                        tm* tempo_final_info=localtime(&tempo_final);

                                                                        tempo_final_info->tm_year=AnoDeIda-1900;
                                                                        tempo_final_info->tm_mon=MesDeIda-1;
                                                                        tempo_final_info->tm_mday=DiaDeIda;
                                                                        tempo_final_info->tm_hour=21;

                                                                        tempo_final=mktime(tempo_final_info);

                                                                        float dif=difftime(tempo_final, t)/3600;

                                                                        if(int(dif)<48||AnoDeIda>DefAnoAtual()+52){
                                                                            controle = false;
                                                                            cout << endl <<"\nA Data de embarque n�o atende aos requisitos informados!"<<endl;
                                                                            system("pause");
                                                                            system("cls");

                                                                        }else{
                                                                            controle = true;
                                                                        }

                                                                    }while(controle == false);



                                                                    /*Encerra o sistema de verifica��o de datas poss�veis para compra de passagens*/

                                                                    /*Bloco para o pacote lua de mel*/                                                                    while(1){
                                                                        system("cls");
                                                                        do{
                                                                            try {
                                                                                cout << "Temos a op��o de pacote de lua de mel, para dexiar sua viagem ainda mais especial (digite 1 para sim e 0 para n�o):" << endl;
                                                                                cin >> TipoDePassagem;
                                                                                cout << endl;

                                                                                if(TipoDePassagem == 0||TipoDePassagem == 1){
                                                                                    auxiliar = true;
                                                                                }

                                                                                else if(TipoDePassagem != 0 && TipoDePassagem != 1){
                                                                                    cout << endl << "Op��o inv�lida, por favor digite novamente!\n" << endl;
                                                                                    auxiliar = false;
                                                                                }


                                                                            }catch (ios_base::failure &fail) {
                                                                                auxiliar = false;
                                                                                cout << "\nERRO 0xC0000005 - Caractere inv�lido, por favor, digite sua data como n�meros inteiros.\n" << endl;
                                                                                cin.clear();
                                                                                string digitada;
                                                                                getline(cin, digitada);
                                                                            }
                                                                        }while(auxiliar == false);

                                                                        struct tm date = { 0, 0, 12 } ;
                                                                        int year = AnoDeIda ;
                                                                        int month = MesDeIda;
                                                                        int day = DiaDeIda;


                                                                        date.tm_year = year - 1900 ;
                                                                        date.tm_mon = month - 1 ;
                                                                        date.tm_mday = day ;


                                                                        DatePlusDays( &date, +15 ) ;

                                                                        DiaDeVolta = date.tm_mday;
                                                                        MesDeVolta = date.tm_mon+1;
                                                                        AnoDeVolta = date.tm_year+1900;

                                                                        system("pause");

                                                                        if(TipoDePassagem != 0 && TipoDePassagem != 1){
                                                                            cout << endl << "Op��o inv�lida, por favor digite novamente!" << endl;
                                                                            system("pause");
                                                                        }
                                                                        else{
                                                                            break;
                                                                        }
                                                                    }

                                                                }
                                                                break;

                                                                /*Respons�vel pelas passagens de cruzeiro (salvador - Cabibe)*/
                                                                case 1:{

                                                                    /*Variavel booleana e do While respons�veis por verificar se a data
                                                                    de embarque est� dentro dos parametros exigidos*/
                                                                    bool auxiliar = true;
                                                                    bool controle = true;
                                                                    do{
                                                                        cin.exceptions(istream::failbit);
                                                                        do{
                                                                            try {
                                                                                cout << endl << "Digite a data de ida da sua viagem" << endl;
                                                                                cin >> DiaDeIda;
                                                                                cin >> MesDeIda;
                                                                                cin >> AnoDeIda;
                                                                                auxiliar = true;

                                                                                if(DiaDeIda!=7&&DiaDeIda!=21||MesDeIda<1&&MesDeIda>12||AnoDeIda<1){
                                                                                cout << "Datas inv�lidas" << endl;
                                                                                auxiliar = false;
                                                                                }
                                                                            }catch (ios_base::failure &fail) {
                                                                                auxiliar = false;
                                                                                cout << "\nERRO 0xC0000005 - Caractere inv�lido, por favor, digite sua data como n�meros inteiros." << endl;
                                                                                cin.clear();
                                                                                string digitada;
                                                                                getline(cin, digitada);
                                                                            }
                                                                        }while(auxiliar == false);

                                                                        time_t tempo_final, t;

                                                                        time(&t);//HORARIO DO PC

                                                                        //Seta o tempo final para 26/05/2011 15:30:50
                                                                        tm* tempo_final_info=localtime(&tempo_final);

                                                                        tempo_final_info->tm_year=AnoDeIda-1900; //ANO 2021
                                                                        tempo_final_info->tm_mon=MesDeIda-1; //M�S 09
                                                                        tempo_final_info->tm_mday=DiaDeIda; //DIA 26
                                                                        tempo_final_info->tm_hour=HoraioAuxiliarIda; //12 HRS

                                                                        tempo_final=mktime(tempo_final_info);

                                                                        float dif=difftime(tempo_final, t)/3600;

                                                                        time_t ano_atual, t2;
                                                                        time(&t2);

                                                                        tm* ano = localtime(&ano_atual);

                                                                        if(int(dif)<48||AnoDeIda>DefAnoAtual()+52){
                                                                            controle = false;
                                                                            cout << endl <<"\nA Data de embarque n�o atende aos requisitos informados!"<<endl;
                                                                            system("pause");
                                                                            system("cls");

                                                                        }else{
                                                                            controle = true;
                                                                        }
                                                                    }while(controle == false);
                                                                    /*Encerra o sistema de verifica��o de datas poss�veis para compra de passagens*/

                                                                    /*Bloco para o pacote lua de mel*/
                                                                    while(1){
                                                                        system("cls");

                                                                        cin.exceptions(istream::failbit);
                                                                        do{
                                                                            try {
                                                                                cout << "Temos a op��o de pacote de lua de mel, para dexiar sua viagem ainda mais especial (digite 1 para sim e 0 para n�o):" << endl;
                                                                                cin >> TipoDePassagem;
                                                                                cout << endl;

                                                                                if(TipoDePassagem == 0||TipoDePassagem == 1){
                                                                                    auxiliar = true;
                                                                                }

                                                                                else if(TipoDePassagem != 0 && TipoDePassagem != 1){
                                                                                    cout << endl << "Op��o inv�lida, por favor digite novamente!\n" << endl;
                                                                                    auxiliar = false;
                                                                                }


                                                                            }catch (ios_base::failure &fail) {
                                                                                auxiliar = false;
                                                                                cout << "\nERRO 0xC0000005 - Caractere inv�lido, por favor, digite sua data como n�meros inteiros.\n" << endl;
                                                                                cin.clear();
                                                                                string digitada;
                                                                                getline(cin, digitada);
                                                                            }
                                                                        }while(auxiliar == false);

                                                                      break;
                                                                    }

                                                                }
                                                                break;

                                                                /*Quando a passagem de cruzeiro estiver finalizada*/
                                                                case 2:{

                                                                    cout << endl;

                                                                    ObjAgencia.PassaParaOGeradorDePassagens(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDePassagem,
                                                                    Regiao, Cidade, TipoDeViagem, Origem, Horario);

                                                                    cout << endl;
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
                                            cout << "Temos para voc� a recomenda��o de poss�veis h�teis, para que supra sua necessidade:\n" << endl;
                                            cout << "H�tel: Caio Brito" << endl;
                                            cout << "H�tel: Jo�o Victor" << endl;
                                            cout << "H�tel: Jos� Savyo" << endl;
                                            cout << "H�tel: Mateus Figueiredo\n" << endl;
                                            system("pause");
                                        }
                                        break;

                                        /*Case para o m�todo de cancelamento de passagens*/
                                        case 2:{
                                            //cout << endl << "EXECUTE O M�TODO DE CANCELAMENTO DE PASSAGENS" << endl;
                                            ObjAgencia.CancelarPassagens();
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
                                            ObjAgencia.RetornaPosicaoParaCliente();
                                            ObjAgencia.ExibirCliente();
                                            system("pause");
                                            system("cls");
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
                            system("cls");
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
