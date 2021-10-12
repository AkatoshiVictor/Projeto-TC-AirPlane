/*As bibliotecas incluídas são usadas
também nas outras classes*/

#include <conio.h>
#include <iostream>
#include <locale>
#include <vector>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

/*Inclusão dos arquivos necessários para a execução da main*/

#include "Menus.cpp"
#include "AgenciaDeViagens.cpp" /*As outras classes são icluídas em agência*/


/*Bloco de funções para auxiliar o sistemna de datas usado nas verificações da main
Como a biblioteca time trata de variáveis que são extraídas do sistema, todas as operações
feitas com essas informações, utilizamos na main, visando que, o usuário poderia ter acesso
e visualiar que informações do sistema estão sendo acessadas (Essa escolha de aplicação no
código, tem fundamento apenas teórico, e foi escolhida para caráter de explicação do projeto
em sua apresentação) - Poderia ser utilizado um sistema de métodos*/

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

    /*Bloco de preapação inicial*/

        /*Preparando o terminal de exibição*/
        setlocale(LC_ALL,"Portuguese");
        system("cls");

        /*Criação dos objetos utilizados dentro da main*/
        Menus Agencia;
        AgenciaDeViagens ObjAgencia;

        /*Variável padrão usada no switch*/
        int Escolhas = 0;

    /*Variáveis para montagem da passagem de avião, ônibus e cruzeiro
    Essas variáveis são redefinidas dentro de cada case*/

        int DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDePassagem,
        Regiao, Cidade, TipoDeViagem, Origem, Horario;

    /*Variaveis usadas para definir os horários para serem feitas as validações da datas*/
        int HoraioAuxiliarVolta, HoraioAuxiliarIda;

    /*Bloco de chamada do menu geral*/
    while(1){
        Escolhas = Agencia.MenuGeral();
        switch(Escolhas){

            /*##################################################################################*/
            /*######################### BLOCO PARA OS FUNCIONÁRIOS #############################*/
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

                            /*Bloco de verificação de login do presidente*/
                            system("cls");
                            if(ObjAgencia.LoginFuncionario(Escolhas)){

                                /*Bloco de repetição para as opções do presidente*/
                                while(1){
                                    Escolhas = Agencia.FuncionarioPresidente();
                                    switch(Escolhas){

                                        /*Case de exibição do relatório de gastos e lucros
                                        da empresa*/
                                        case 0:{
                                            ObjAgencia.ImprimiReceita();
                                        }
                                        break;

                                        /*Case usado para opção de demitir funcionários (pelo presidente)*/
                                        case 1:{
                                            ObjAgencia.DemiteFuncionario();
                                            system("pause");
                                        }
                                        break;

                                    } /*Fecha o switch do bloco das opções do presidente*/

                                    /*Trava para o bloco das opções do presidente*/
                                    if(Escolhas == 99){
                                        Escolhas = 0;
                                        break;
                                    }

                                }/*Feche a repetição das opções do presidente*/

                            }/*Fehca o bloco do if de verificação de login do presidente*/

                            /*Bloco de usuário incorreto para o presidente*/
                            else{
                                system("cls");
                                cout << "\nUsuário ou senha incorretos" << endl;
                                system("pause");
                            }

                        }/*Fecha o case 0 - geral do presidente*/
                        break;

                        /*##################################################################################*/
                        /*############################ BLOCO PARA O GERENTE ################################*/
                        /*##################################################################################*/

                        case 1:{

                            /*Bloco para verificação de login do gerente*/
                            system("cls");
                            if (ObjAgencia.LoginFuncionario(Escolhas)){

                                /*Bloco de repetição das opções gerais do gerente*/
                                while(1){
                                    Escolhas = Agencia.FuncionarioGerente();
                                    switch(Escolhas){

                                        /*Case para demitir funcionário (através do gerente)*/
                                        case 0:{
                                            ObjAgencia.DemiteFuncionario();
                                            system("pause");
                                        }
                                        break;

                                        /*Case para cadastras um funcionário*/
                                        case 1:{
                                            ObjAgencia.CadastraFuncionario();
                                            system("pause");
                                        }
                                        break;

                                        /*Case para exibir um funcionário através do email (para o gerente)*/
                                        case 2:{
                                            int posicao = ObjAgencia.RetornaPosicaoFuncionario();
                                            ObjAgencia.set_posicao_atual(posicao);
                                            ObjAgencia.ExibirFuncionario();
                                            system("pause");
                                        }
                                        break;

                                    }/*Fecha o switch do gerente*/

                                    /*Trava para o bloco de repetição das opções do gerente*/
                                    if(Escolhas == 99){
                                        Escolhas = 0;
                                        break;
                                    }

                                }/*Fecha o bloco de repetição do gerente*/

                            }/*Fecha o bloco de verificação do login*/

                            /*Bloco de usuário incorreto para o gerente*/
                            else{
                                system("cls");
                                cout << "\nUsuário ou senha incorretos" << endl;
                                system("pause");
                            }

                        }/*Fecha o case 1 - Do gerente*/
                        break;

                        /*##################################################################################*/
                        /*########################## BLOCO PARA O FUNCIONÁRIO ###############################*/
                        /*##################################################################################*/

                        case 2:{

                            /*Bloco de verificação do login do funcionário (vendedor)*/
                            system("cls");
                            if(ObjAgencia.LoginFuncionario(Escolhas)){

                                /*Bloco de repetição para as opções do funcionário*/
                                while(1){
                                    Escolhas = Agencia.FuncionarioFuncionario();
                                    switch(Escolhas){

                                        /*Case para a venda de passagens*/
                                        case 0:{

                                            /*Bloco de repetição para a venda de passagens*/
                                            while(1){
                                                Escolhas = Agencia.FuncionarioFuncionarioVenderPassagens();
                                                switch(Escolhas){

                                                    /*Case para a venda de passagens de avião*/
                                                    case 0:{
                                                        //cout << endl << "EXECUTE O MÉTODO DE VENDA DE PASSAGENS DE AVIÃO" << endl;
                                                        ObjAgencia.VenderPassagem(0);
                                                        system("pause");
                                                    }
                                                    break;

                                                    /*Case para a venda de passagens de ônibus*/
                                                    case 1:{
                                                        //cout << endl << "EXECUTE O MÉTODO DE VENDA DE PASSAGENS DE ÔNIBUS" << endl;
                                                        ObjAgencia.VenderPassagem(1);
                                                        system("pause");
                                                    }
                                                    break;

                                                    /*Case para a venda de passagens de cruzeiro*/
                                                    case 2:{
                                                        //cout << endl << "EXECUTE O MÉTODO VENDA DE PASSAGENS DE CRUZEIRO" << endl;
                                                        ObjAgencia.VenderPassagem(2);
                                                        system("pause");
                                                    }
                                                    break;

                                                }/*Fecha o switch das opções de vendas de passagens*/

                                                /*Trava para o bloco de repetição de venda de passagens*/
                                                if(Escolhas == 99){
                                                    Escolhas = 0;
                                                    break;
                                                }

                                            }/*Fecha o bloco de repetição de vendas de passagens*/

                                        }/*Fecha o case 0 - das vendas de passagens pelo funcionário*/
                                        break;

                                        /*Case responsávbel por exibir os dados do funcionário (que está logado)*/
                                        case 1:{
                                            ObjAgencia.RetornaPosicaoParaFuncionario();
                                            ObjAgencia.ExibirFuncionario();
                                            system("pause");
                                            system("cls");
                                        }
                                        break;

                                        /*Bloco de alterção do funcionário logado*/
                                        case 2:{

                                            /*Bloco de repetição para as opções do menu de alteração de dados*/
                                            while(1){
                                                Escolhas = Agencia.FuncionarioAlteracaoDados();

                                                ObjAgencia.AlterarDadosFuncionario(Escolhas);
                                                system("pause");

                                                /*Trava do bloco de repetição das opções de alteração de dados*/
                                                if(Escolhas == 99){
                                                    Escolhas = 0;
                                                    break;
                                                }

                                            }/*Fecha o bloco de repetição de alteração de dados*/

                                        }/*Fecha o case 2 - da alteração de dados do funcionário (logado)*/
                                        break;

                                    }/*Fecha o switch de exibição de opções do funcionário vendedor*/

                                    /*Trava do bloco de repetição de funcionários vendedor*/
                                    if(Escolhas == 99){
                                        Escolhas = 0;
                                        break;
                                    }

                                }/*Fecha o bloco de repetição das opções do funcionário*/

                            }/*Fecha o if de verificação de login do funcioário*/

                            /*Bloco de login incorreto para o vendedor*/
                            else{
                                system("cls");
                                cout << "\nUsuário ou senha incorretos" << endl;
                                system("pause");
                            }

                        }/*Fecha o case 2 - das opções do funcionário vendedor*/
                        break;

                    }/*Fecha o switch de exibição das opções do funcionário*/

                    /*Trava do bloco de repetição do funcionário*/
                    if(Escolhas == 99){
                        Escolhas = 0;
                        break;
                    }

                }/*Fecha o bloco de repetição das opções do funcionário*/

            }/*Fecha o case 0 - responsável pelo gerenciamento das opções do funcionário*/
            break;

            /*##################################################################################*/
            /*########################### BLOCO PARA OS CLIENTES ###############################*/
            /*##################################################################################*/

            case 1:{

                /*Bloco de repetição para as opções do cliente*/
                while(1){
                    Escolhas = Agencia.Cliente();
                    switch(Escolhas){

                        /*Case responsável para o cliente entrar nos sistema*/
                        case 0:{

                            /*Bloco de verificação de login do cliente*/
                            system("cls");
                            if(ObjAgencia.LoginCliente()){

                                /*Bloco de repetição para as opções do cliente*/
                                while(1){
                                    Escolhas = Agencia.ClienteEntrar();
                                    switch(Escolhas){

                                        /*Case responsável pelas opções de comprar uma passagem*/
                                        case 0:{

                                            /*Bloco de repetição de compra de passagens*/
                                            while(1){
                                                Escolhas = Agencia.ClienteComprarPassagens();
                                                switch(Escolhas){

                                                    /*Case resonsável para compra de passagens de avião*/
                                                    case 0:{

                                                        /*Foi escolhido o número 999 para definir variáveis não preenchidas pelo usuário, como
                                                        as variáveis são definidas através de inteiros gerados no menu, o número 999 não pode
                                                        ser gerado por engano nunda*/

                                                        DiaDeIda = MesDeIda = AnoDeIda = DiaDeVolta = MesDeVolta = AnoDeVolta = TipoDePassagem = 999;
                                                        Regiao = Origem = Cidade = Horario = 999;

                                                        /*Tipo de viagem, para viagens de avião é denidio como 0*/
                                                        TipoDeViagem = 0;

                                                        /*Bloco de repetição para as passagens de avião*/
                                                        while(1){
                                                            Escolhas = Agencia.ClienteCriacaoDePassagem();
                                                            switch(Escolhas){

                                                                /*Case para escolha de origem do avião*/
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

                                                                    /*Bloco parar exibição das regiões de destino*/
                                                                    Escolhas = Agencia.ClientePassagensRegioes();
                                                                    switch(Escolhas){

                                                                        /*Case para a região centro-oeste*/
                                                                        case 0:{

                                                                            /*Definição de região recebe o número do case do switch*/
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
                                                                        /*A repetição para os próximos casos é padrão ao anterior*/

                                                                        /*Case para região nordeste*/
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

                                                                        /*Case para a região norte*/
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

                                                                        /*Case para a região sudeste*/
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

                                                                        /*Case para a região Sul*/
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

                                                                    }/*Fecha o switch para escolha de destino do avião*/

                                                                    /*Bloco de redefinição de escolha*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        Regiao = 999;
                                                                    }

                                                                }/*Fecha o case 1 - responsávvel pela escolha de desnito*/
                                                                break;

                                                                /*Case responsável pela escolha de tipo de passagem no avião*/
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

                                                                /*Case responsável pela escolha de opção de datas*/
                                                                case 3:{

                                                                    /*Bloco de repetição para a inserção de datas*/
                                                                    while(1){
                                                                        Escolhas = Agencia.ClienteInserindoData();
                                                                        switch(Escolhas){

                                                                            /*Case para a data de ida*/
                                                                            case 0:{

                                                                                /*Variavel booleana e do While responsáveis por verificar se a data
                                                                                de embarque está dentro dos parametros exigidos*/
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
                                                                                                    cout << endl << "A data inserida não é válida (ou não existe) no nosso sistema" << endl;
                                                                                                    auxiliar = false;
                                                                                                }
                                                                                            }
                                                                                            else{
                                                                                                cout << endl << "A data inserida não é válida (ou não existe) no nosso sistema" << endl;
                                                                                                auxiliar = false;
                                                                                            }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inválido, por favor, digite sua data como números inteiros." << endl;
                                                                                            cin.clear();
                                                                                            string digitada;
                                                                                            getline(cin, digitada);
                                                                                        }
                                                                                    }while(auxiliar == false);

                                                                                    do{
                                                                                       try {
                                                                                            cout << endl << "Digite o horário da sua viagem" << endl;
                                                                                            cin >> Horario;
                                                                                            auxiliar = true;

                                                                                            if(Horario<0||Horario>2){
                                                                                                cout << "ERRO 0xC0000005 - Caractere inválido" << endl;
                                                                                                auxiliar = false;
                                                                                                }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inválido, por favor, digite sua data como números inteiros." << endl;
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
                                                                                        cout<<"A Data deve ser no presente ou futuro (48 horas de antecedência)"<<endl;
                                                                                        system("pause");
                                                                                        system("cls");
                                                                                        controle = false;
                                                                                    }

                                                                                }while(controle == false);
                                                                                /*Encerra o sistema de verificação de datas possíveis para compra de passagens*/

                                                                                cout << endl;
                                                                                system("pause");

                                                                            }/*Fecha o case 1 de datas*/
                                                                            break;

                                                                            /*Case para a data de volta*/
                                                                            case 1:{
                                                                                /*Variavel booleana e do While responsáveis por verificar se a data
                                                                                de embarque está dentro dos parametros exigidos*/
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
                                                                                                        cout << endl << "A data inserida não é válida (ou não existe) no nosso sistema" << endl;
                                                                                                        auxiliar = false;
                                                                                                    }
                                                                                                }
                                                                                                else{
                                                                                                    cout << endl << "A data inserida não é válida (ou não existe) no nosso sistema" << endl;
                                                                                                    auxiliar = false;
                                                                                                }

                                                                                                if(verifica_data_volta(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta) == true){
                                                                                                    auxiliar = true;
                                                                                                }
                                                                                                else{
                                                                                                    cout << endl << "A data inserida não é válida (ou não existe) no nosso sistema" << endl;
                                                                                                    system("pause");
                                                                                                    system("cls");
                                                                                                    auxiliar = false;
                                                                                                }
                                                                                            }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inválido, por favor, digite sua data como números inteiros." << endl;
                                                                                            cin.clear();
                                                                                            string digitada;
                                                                                            getline(cin, digitada);
                                                                                        }
                                                                                    }while(auxiliar == false);

                                                                                    if(verifica_data_volta(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta) == true){
                                                                                        controle = true;
                                                                                    }
                                                                                    else{
                                                                                        cout<<"A Data deve ser no presente ou futuro (48 horas de antecedência)"<<endl;
                                                                                        system("pause");
                                                                                        system("cls");
                                                                                        controle = false;
                                                                                    }

                                                                                }while(controle == false);

                                                                                cout << endl;
                                                                                system("pause");

                                                                            }/*Fecha o case 1 de datas*/
                                                                            break;

                                                                        }/*FEcha o switch responsável pela exibição das datas*/

                                                                        /*Trava para o bloco de repetição inserção de datas*/
                                                                        if(Escolhas == 99){
                                                                            Escolhas = 0;
                                                                            break;
                                                                        }

                                                                    }/*Fecha o bloco de repetição de datas*/

                                                                }/*Fecha o case 3 responsável pela escolha de opção de datas*/
                                                                break;

                                                                /*Ao terminar de montar a passagem o case 4 é responsável pela confirmação
                                                                e geração da passagem, para adicionar aos vector da agência*/
                                                                case 4:{

                                                                    cout << endl;

                                                                    ObjAgencia.PassaParaOGeradorDePassagens(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDePassagem,
                                                                    Regiao, Cidade, TipoDeViagem, Origem, Horario);

                                                                    cout << endl;
                                                                    system("pause");
                                                                }
                                                                break;

                                                            }/*Fecha o switch responsável pela criação de passagens de avião*/

                                                            /*Trava para o bloco de repetição de passagens*/
                                                            if(Escolhas == 99){
                                                                Escolhas = 0;
                                                                break;
                                                            }

                                                        }/*Fecha o bloco de repetição das opções de criação de passagem de avião*/

                                                    }/*Fecha o case 0 - Responsãvel pelas opções de venda de passagem de avião*/
                                                    break;

                                                    /*Case resonsável para compra de passagens de ônibus*/
                                                    case 1:{

                                                        /*Foi escolhido o número 999 para definir variáveis não preenchidas pelo usuário, como
                                                        as variáveis são definidas através de inteiros gerados no menu, o número 999 não pode
                                                        ser gerado por engano nunda*/

                                                        DiaDeIda = MesDeIda = AnoDeIda = DiaDeVolta = MesDeVolta = AnoDeVolta = TipoDePassagem = 999;
                                                        Regiao = Origem = Cidade = Horario = 999;

                                                        /*Tipo de viagem, para viagens de ônibus é denidio como 0*/
                                                        TipoDeViagem = 1;
                                                        /*As passagens de ônibus possuem apenas um horário*/
                                                        Horario = 2;

                                                        /*Bloco de repetição para as passagens de ônibus*/
                                                        while(1){
                                                            Escolhas = Agencia.ClienteCriacaoDePassagem();
                                                            switch(Escolhas){

                                                                /*Case para escolha de origem do ônibus*/
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

                                                                    /*Bloco parar exibição das regiões de destino*/
                                                                    Escolhas = Agencia.ClientePassagensRegioes();
                                                                    switch(Escolhas){

                                                                        /*Case para a região centro-oeste*/
                                                                        case 0:{

                                                                            /*Definição de região recebe o número do case do switch*/
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
                                                                        /*A repetição para os próximos casos é padrão ao anterior*/

                                                                        /*Case para região nordeste*/
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

                                                                        /*Case para a região norte*/
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

                                                                        /*Case para a região sudeste*/
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

                                                                        /*Case para a região Sul*/
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

                                                                    }/*Fecha switch para escolha de destino do ônibus*/

                                                                    /*Bloco de redefinição de escolha*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        Regiao = 999;
                                                                    }

                                                                }/*Fecha o case 1 - responsávvel pela escolha de desnito*/
                                                                break;

                                                                /*Case responsável pela escolha de tipo de passagem no ônibus*/
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

                                                                /*Case responsável pela escolha de opção de datas*/
                                                                case 3:{

                                                                    /*Bloco de repetição para a inserção de datas*/
                                                                    while(1){
                                                                        Escolhas = Agencia.ClienteInserindoData();
                                                                        switch(Escolhas){

                                                                            /*Case para a data de ida*/
                                                                            case 0:{

                                                                                /*Variavel booleana e do While responsáveis por verificar se a data
                                                                                de embarque está dentro dos parametros exigidos*/
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
                                                                                                    cout << endl << "A data inserida não é válida (ou não existe) no nosso sistema" << endl;
                                                                                                    auxiliar = false;
                                                                                                }
                                                                                            }
                                                                                            else{
                                                                                                cout << endl << "A data inserida não é válida (ou não existe) no nosso sistema" << endl;
                                                                                                auxiliar = false;
                                                                                            }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inválido, por favor, digite sua data como números inteiros." << endl;
                                                                                            cin.clear();
                                                                                            string digitada;
                                                                                            getline(cin, digitada);
                                                                                        }
                                                                                    }while(auxiliar == false);

                                                                                    do{
                                                                                       try {
                                                                                            cout << endl << "Digite o horário da sua viagem" << endl;
                                                                                            cin >> Horario;
                                                                                            auxiliar = true;

                                                                                            if(Horario<0||Horario>2){
                                                                                                cout << "ERRO 0xC0000005 - Caractere inválido" << endl;
                                                                                                auxiliar = false;
                                                                                                }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inválido, por favor, digite sua data como números inteiros." << endl;
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
                                                                                        cout<<"A Data deve ser no presente ou futuro (48 horas de antecedência)"<<endl;
                                                                                        system("pause");
                                                                                        system("cls");
                                                                                        controle = false;
                                                                                    }

                                                                                }while(controle == false);
                                                                                /*Encerra o sistema de verificação de datas possíveis para compra de passagens*/

                                                                                cout << endl;
                                                                                system("pause");
                                                                            }/*Fecha o case 0 de datas*/
                                                                            break;

                                                                            /*Case para a data de volta*/
                                                                            case 1:{
                                                                                /*Variavel booleana e do While responsáveis por verificar se a data
                                                                                de embarque está dentro dos parametros exigidos*/
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
                                                                                                        cout << endl << "A data inserida não é válida (ou não existe) no nosso sistema" << endl;
                                                                                                        auxiliar = false;
                                                                                                    }
                                                                                                }
                                                                                                else{
                                                                                                    cout << endl << "A data inserida não é válida (ou não existe) no nosso sistema" << endl;
                                                                                                    auxiliar = false;
                                                                                                }

                                                                                                if(verifica_data_volta(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta) == true){
                                                                                                    auxiliar = true;
                                                                                                }
                                                                                                else{
                                                                                                    cout << endl << "A data inserida não é válida (ou não existe) no nosso sistema" << endl;
                                                                                                    system("pause");
                                                                                                    system("cls");
                                                                                                    auxiliar = false;
                                                                                                }
                                                                                            }

                                                                                        }catch (ios_base::failure &fail) {
                                                                                            auxiliar = false;
                                                                                            cout << "\nERRO 0xC0000005 - Caractere inválido, por favor, digite sua data como números inteiros." << endl;
                                                                                            cin.clear();
                                                                                            string digitada;
                                                                                            getline(cin, digitada);
                                                                                        }
                                                                                    }while(auxiliar == false);

                                                                                    if(verifica_data_volta(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta) == true){
                                                                                        controle = true;
                                                                                    }
                                                                                    else{
                                                                                        cout<<"A Data deve ser no presente ou futuro (48 horas de antecedência)"<<endl;
                                                                                        system("pause");
                                                                                        system("cls");
                                                                                        controle = false;
                                                                                    }

                                                                                }while(controle == false);

                                                                                cout << endl;
                                                                                system("pause");
                                                                            }/*Fecha o case 1 de datas*/
                                                                            break;

                                                                        }/*Fecha o switch responsável pela exibição das datas*/

                                                                        /*Trava para o bloco de repetição inserção de datas*/
                                                                        if(Escolhas == 99){
                                                                            Escolhas = 0;
                                                                            break;
                                                                        }

                                                                    }/*Fecha o bloco de repetição de datas*/

                                                                }/*Fecha o case 3 responsável pela escolha de opção de datas*/
                                                                break;

                                                                /*Ao terminar de montar a passagem o case 4 é responsável pela confirmação
                                                                e geração da passagem, para adicionar aos vector da agência*/
                                                                case 4:{

                                                                    cout << endl;

                                                                    ObjAgencia.PassaParaOGeradorDePassagens(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDePassagem,
                                                                    Regiao, Cidade, TipoDeViagem, Origem, Horario);

                                                                    cout << endl;
                                                                    system("pause");
                                                                }
                                                                break;

                                                            }/*Fecha o switch responsável pela criação de passagens*/

                                                            /*Trava para o bloco de repetição de criação de passagens de ônibus*/
                                                            if(Escolhas == 99){
                                                                Escolhas = 0;
                                                                break;
                                                            }

                                                        }/*Fecha o bloco de repetição das opções de criação de passagem de ônibus*/

                                                    }/*Fecha o case 0 - Responsãvel pelas opções de venda de passagem de ônibus*/
                                                    break;

                                                    /*Case responsável para criação de passagens de cruzeiro*/
                                                    case 2:{

                                                        /*Foi escolhido o número 999 para definir variáveis não preenchidas pelo usuário, como
                                                        as variáveis são definidas através de inteiros gerados no menu, o número 999 não pode
                                                        ser gerado por engano nunda*/

                                                        DiaDeIda = MesDeIda = AnoDeIda = DiaDeVolta = MesDeVolta = AnoDeVolta = TipoDePassagem = 999;

                                                        /*Tipo de viagem, para viagens de ônibus é denidio como 0*/
                                                        TipoDeViagem = 2;

                                                        /*O cruzeiro não possuí as seguinte variáveis, o valor delas é iniciado como 0, para que se possa
                                                        utilizar o mesmo método para construção das passagens*/

                                                        Regiao = Origem = Cidade = Horario = 0;

                                                        /*Bloco de repetição para criação de passagens de cruzeiro*/
                                                        while(1){
                                                            Escolhas = Agencia.ClientePassagensCruzeiro();
                                                            switch(Escolhas){

                                                                /*Responsável para as passagens de cruzeiro (salvador - EUROPA)*/
                                                                case 0:{

                                                                    /*Variavel booleana e do While responsáveis por verificar se a data
                                                                    de embarque está dentro dos parametros exigidos*/
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
                                                                                    cout << "Datas inválidas" << endl;
                                                                                    auxiliar = false;
                                                                                }
                                                                            }catch (ios_base::failure &fail) {
                                                                                auxiliar = false;
                                                                                cout << "\nERRO 0xC0000005 - Caractere inválido, por favor, digite sua data como números inteiros." << endl;
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
                                                                            cout << endl <<"\nA Data de embarque não atende aos requisitos informados!"<<endl;
                                                                            system("pause");
                                                                            system("cls");

                                                                        }else{
                                                                            controle = true;
                                                                        }

                                                                    }while(controle == false);



                                                                    /*Encerra o sistema de verificação de datas possíveis para compra de passagens*/

                                                                    /*Bloco para o pacote lua de mel*/                                                                    while(1){
                                                                        system("cls");
                                                                        do{
                                                                            try {
                                                                                cout << "Temos a opção de pacote de lua de mel, para dexiar sua viagem ainda mais especial (digite 1 para sim e 0 para não):" << endl;
                                                                                cin >> TipoDePassagem;
                                                                                cout << endl;

                                                                                if(TipoDePassagem == 0||TipoDePassagem == 1){
                                                                                    auxiliar = true;
                                                                                }

                                                                                else if(TipoDePassagem != 0 && TipoDePassagem != 1){
                                                                                    cout << endl << "Opção inválida, por favor digite novamente!\n" << endl;
                                                                                    auxiliar = false;
                                                                                }


                                                                            }catch (ios_base::failure &fail) {
                                                                                auxiliar = false;
                                                                                cout << "\nERRO 0xC0000005 - Caractere inválido, por favor, digite sua data como números inteiros.\n" << endl;
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
                                                                            cout << endl << "Opção inválida, por favor digite novamente!" << endl;
                                                                            system("pause");
                                                                        }
                                                                        else{
                                                                            break;
                                                                        }
                                                                    }

                                                                }
                                                                break;

                                                                /*Responsável pelas passagens de cruzeiro (salvador - Cabibe)*/
                                                                case 1:{

                                                                    /*Variavel booleana e do While responsáveis por verificar se a data
                                                                    de embarque está dentro dos parametros exigidos*/
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
                                                                                cout << "Datas inválidas" << endl;
                                                                                auxiliar = false;
                                                                                }
                                                                            }catch (ios_base::failure &fail) {
                                                                                auxiliar = false;
                                                                                cout << "\nERRO 0xC0000005 - Caractere inválido, por favor, digite sua data como números inteiros." << endl;
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
                                                                        tempo_final_info->tm_mon=MesDeIda-1; //MêS 09
                                                                        tempo_final_info->tm_mday=DiaDeIda; //DIA 26
                                                                        tempo_final_info->tm_hour=HoraioAuxiliarIda; //12 HRS

                                                                        tempo_final=mktime(tempo_final_info);

                                                                        float dif=difftime(tempo_final, t)/3600;

                                                                        time_t ano_atual, t2;
                                                                        time(&t2);

                                                                        tm* ano = localtime(&ano_atual);

                                                                        if(int(dif)<48||AnoDeIda>DefAnoAtual()+52){
                                                                            controle = false;
                                                                            cout << endl <<"\nA Data de embarque não atende aos requisitos informados!"<<endl;
                                                                            system("pause");
                                                                            system("cls");

                                                                        }else{
                                                                            controle = true;
                                                                        }
                                                                    }while(controle == false);
                                                                    /*Encerra o sistema de verificação de datas possíveis para compra de passagens*/

                                                                    /*Bloco para o pacote lua de mel*/
                                                                    while(1){
                                                                        system("cls");

                                                                        cin.exceptions(istream::failbit);
                                                                        do{
                                                                            try {
                                                                                cout << "Temos a opção de pacote de lua de mel, para dexiar sua viagem ainda mais especial (digite 1 para sim e 0 para não):" << endl;
                                                                                cin >> TipoDePassagem;
                                                                                cout << endl;

                                                                                if(TipoDePassagem == 0||TipoDePassagem == 1){
                                                                                    auxiliar = true;
                                                                                }

                                                                                else if(TipoDePassagem != 0 && TipoDePassagem != 1){
                                                                                    cout << endl << "Opção inválida, por favor digite novamente!\n" << endl;
                                                                                    auxiliar = false;
                                                                                }


                                                                            }catch (ios_base::failure &fail) {
                                                                                auxiliar = false;
                                                                                cout << "\nERRO 0xC0000005 - Caractere inválido, por favor, digite sua data como números inteiros.\n" << endl;
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

                                                            }/*Fecha o switch responsável pelas escolhas de passagens de cruzeiro*/

                                                            /*Trava do bloco de repetição do cruzeiro*/
                                                            if(Escolhas == 99){
                                                                Escolhas = 0;
                                                                break;
                                                            }

                                                        }/*Fecha o bloco de repetição para a geração de passagens de cruzeiro*/

                                                    }/*Fecha o case 2 responsável pelas opções de criação de passagem de cruzeiro*/

                                                }/*Fecha o switch da esolha do tipo de passagem*/

                                                /*Trava para repetição do bloco de escolhas do tipo de passagem*/
                                                if(Escolhas == 99){
                                                    Escolhas = 0;
                                                    break;
                                                }

                                            }/*Fecha o bloco de repetição para a escolha do tipo de passagem*/

                                        }/*Fecha o case 0 - responsável pelas escolhas do tipo de passagem*/
                                        break;

                                        /*Responsável pela exibição e escolha de hóteis*/
                                        case 1:{

                                            /*Case apenas para mostrar os créditos dos responsáveis pela criação do projeto
                                            como forma de brincadeira, pois tinhamos a ideia de implementa um sistema de reserva hóteis
                                            em conjunto com o sistema de venda de passagens*/

                                            system("cls");
                                            cout << "Presado cliente, infelizmente nossa parceria com o ramo de hóteis foi cancelada." << endl;
                                            cout << "Talvez em um futuro proxímo, voltaremos a utilizar o sistema de parceria com hóteis" << endl;
                                            cout << "Temos para você a recomendação de possíveis hóteis, para que supra sua necessidade:\n" << endl;
                                            cout << "Hótel: Caio Brito" << endl;
                                            cout << "Hótel: João Victor" << endl;
                                            cout << "Hótel: José Savyo" << endl;
                                            cout << "Hótel: Mateus Figueiredo\n" << endl;
                                            system("pause");
                                        }
                                        break;

                                        /*Case para o método de cancelamento de passagens*/
                                        case 2:{
                                            //cout << endl << "EXECUTE O MÉTODO DE CANCELAMENTO DE PASSAGENS" << endl;
                                            ObjAgencia.CancelarPassagens();
                                            system("pause");
                                        }
                                        break;

                                        /*Case para a alteração de dados do cliente (logado)*/
                                        case 3:{

                                            /*Bloco de repetição para a alteração de dados do cliente*/
                                            while(1){
                                                Escolhas = Agencia.ClienteEditarCadastro();

                                                /*Trava para o bloco de repetição para a alteração de dados do cliente*/
                                                if(Escolhas == 99){
                                                    Escolhas = 0;
                                                    break;
                                                }
                                                ObjAgencia.AlterarDadosCliente(Escolhas);
                                            }
                                        }
                                        break;

                                        /*Case responsável para exibição dos dados do cliente (logado)*/
                                        case 4:{
                                            ObjAgencia.RetornaPosicaoParaCliente();
                                            ObjAgencia.ExibirCliente();
                                            system("pause");
                                            system("cls");
                                        }
                                        break;

                                        /*Case reponsável para exibição das passagens compradas pelo cliente*/
                                        case 5:{
                                            //cout << "EXECUTE O MÉTODO DE EXIBIÇÃO DAS PASSAGENS DO CLIENTE" << endl;
                                            //cout << "AS PASSAGENS SÓ APARECEM AQUI QUANDO FOREM CONFIRMADAS AS VENDAS PELO FUNCIONÁRIO" << endl;
                                            ObjAgencia.ImprimaPassagemVendida();
                                            system("pause");
                                        }

                                        /*Case responsável por exibir os custos das passagens atuais do cliente*/
                                        case 6:{
                                            //cout << "EXECUTE O MÉTODO QUE EXIBE AS PASSAGENS QUE FALTAM SER CONFIRMADAS PELO FUNCIONÁRIO" << endl;
                                            ObjAgencia.ImprimaPassagemPendente();
                                            system("pause");
                                        }
                                        break;

                                    }/*Fecha o switch do cliente responsável pela função entrar*/

                                    /*Trava para o bloco de repetição das funcões do cliente, entrar*/
                                    if(Escolhas == 99){
                                        Escolhas = 0;
                                        break;
                                    }

                                }/*Fecha o bloco de repetição responsável pela exibição das escolhas do cliente, entrar*/

                            }/*Fecha o bloco if de login do cliente*/

                            /*Bloco de exibição de mensagem de login incorreto para o cliente*/
                            else{
                                system("cls");
                                cout << "\nUsuário ou senha incorretos" << endl;
                                system("pause");
                            }

                        }/*Fecha o case 0 - responsável pela entrada na função entrar (do cliente)*/
                        break;

                        /*Responsável pela função cadastrar um cliente*/
                        case 1:{
                            system("cls");
                            ObjAgencia.CadastraCliente();
                            system("pause");
                        }
                        break;

                    }/*Fecha o switch responsável pelas funcionções do cliente (entrar e cadastra-se)*/

                    /*Trava para o bloco de repetição do sistema de exibição de cliente(entrar e cadastra-se)*/
                    if(Escolhas == 99){
                        Escolhas = 0;
                        break;
                    }

                }/*Fecha o bloco de repetição do sistema de exibição de cliente(entrar e cadastrar-se)*/

            }/*Fecha o case 1 - responsável pela interação com o cliente*/

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
