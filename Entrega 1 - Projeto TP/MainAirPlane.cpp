#include <conio.h>
#include <iostream>
#include <locale>
#include <vector>
#include <windows.h>
#include <fstream>

using namespace std;

/*COMO ESSA É A MAIN PRINCIPAL DO PROJETO
ELA NÃO FOI FINALIZADA, E SERÁ FINALIZADA APENAS
NA VERSÃO 2 DO PROJETO*/

/*Inclusão de arquivos utilizados*/
#include "Menus.cpp"
#include "AgenciaDeViagens.cpp"

/*PARA O FUNCIONAMENTO CORRETO DO PROGRAMA DESLIGUE O "CAPS LOCK"*/
int main(){
    setlocale(LC_ALL,"Portuguese");
    system("cls");
    Menus Agencia;
    AgenciaDeViagens ObjAgencia;

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
                            system("cls");

                            if(ObjAgencia.Login(Escolhas)){

                                while(1){

                                    Escolhas = Agencia.FuncionarioPresidente();

                                    switch(Escolhas){

                                        case 0:{
                                            cout << endl << "EXIBA O RELÁTORIO DA EMPRESA" << endl;
                                            system("pause");
                                        }
                                        break;

                                        /*Case para os métodos de alteração de taxas*/
                                        break;

                                        case 1:{
                                            ObjAgencia.DemiteFuncionario();
                                            system("pause");
                                        }
                                        break;

                                        /*Case para os métodos de exibição de passagens vendidas*/
                                        case 2:{
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

                            else{
                                system("cls");
                                cout << "\nUsuário ou senha incorretos" << endl;
                                system("pause");
                            }

                        }
                        break;
                        /*Funcionário gerente*/
                        case 1:{
                            /*if Método de verificalçao de login*/
                            system("cls");
                            if (ObjAgencia.Login(Escolhas)){

                                while(1){
                                    Escolhas = Agencia.FuncionarioGerente();

                                    switch(Escolhas){

                                        case 0:{
                                            ObjAgencia.DemiteFuncionario();
                                            system("pause");
                                        }
                                        break;

                                        case 1:{
                                            ObjAgencia.CadastraFuncionario();
                                            system("pause");
                                        }
                                        break;

                                        case 2:{

                                            int posicao = ObjAgencia.RetornaPosicaoFuncionario();
                                            ObjAgencia.set_posicao_atual(posicao);
                                            ObjAgencia.ExibirFuncionario();
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

                            else{
                                system("cls");
                                cout << "\nUsuário ou senha incorretos" << endl;
                                system("pause");
                            }
                        }
                        break;
                        /*Funcionário vendedor*/
                        case 2:{
                            /*if Método de verificalçao de login*/
                            system("cls");
                            if(ObjAgencia.Login(Escolhas)){

                                while(1){
                                    Escolhas = Agencia.FuncionarioFuncionario();
                                    switch(Escolhas){
                                        case 0:{
                                            while(1){
                                                Escolhas = Agencia.FuncionarioFuncionarioVenderPassagens();
                                                switch(Escolhas){
                                                    case 0:{
                                                        cout << endl << "EXECUTE O MÉTODO DE VENDA DE PASSAGENS DE AVIÃO" << endl;
                                                        system("pause");
                                                    }
                                                    break;
                                                    case 1:{
                                                        cout << endl << "EXECUTE O MÉTODO DE VENDA DE PASSAGENS DE ÔNIBUS" << endl;
                                                        system("pause");
                                                    }
                                                    break;
                                                    case 2:{
                                                        cout << endl << "EXECUTE O MÉTODO VENDA DE PASSAGENS DE CRUZEIRO" << endl;
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
                                            ObjAgencia.ExibirFuncionario();
                                            system("pause");
                                            system("cls");
                                        }
                                        break;
                                        case 2:{
                                            while(1){
                                                Escolhas = Agencia.FuncionarioAlteracaoDados();
                                                switch(Escolhas){

                                                    case 0:{
                                                        ObjAgencia.AlterarDadosFuncionario(Escolhas);
                                                        system("pause");
                                                    }
                                                    break;

                                                    case 1:{
                                                        ObjAgencia.AlterarDadosFuncionario(Escolhas);
                                                        system("pause");
                                                    }
                                                    break;
                                            ;
                                                    case 2:{
                                                        ObjAgencia.AlterarDadosFuncionario(Escolhas);
                                                        system("pause");
                                                    }
                                                    break;

                                                    case 3:{
                                                        ObjAgencia.AlterarDadosFuncionario(Escolhas);
                                                        system("pause");
                                                    }
                                                    break;

                                                    case 4:{
                                                        ObjAgencia.AlterarDadosFuncionario(Escolhas);
                                                        system("pause");
                                                    }
                                                    break;

                                                    case 5:{
                                                        ObjAgencia.AlterarDadosFuncionario(Escolhas);
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

                            else{
                                system("cls");
                                cout << "\nUsuário ou senha incorretos" << endl;
                                system("pause");
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
                            /*if Método de verificalçao de login*/
                            while(1){
                                Escolhas = Agencia.ClienteEntrar();

                                switch(Escolhas){
                                    /*Comprar passagem*/
                                    case 0:{
                                        while(1){
                                            Escolhas = Agencia.ClienteComprarPassagens();

                                            switch(Escolhas){
                                                /*Coisas do avião*/
                                                case 0:{
                                                    while(1){
                                                        Escolhas = Agencia.ClienteCriacaoDePassagem();

                                                        switch(Escolhas){
                                                            /*Escolha de origem*/
                                                            case 0:{
                                                                while(1){
                                                                    Escolhas = Agencia.ClienteOrigem();
                                                                    /*Execute o método que pega a origem e passe escolhas como parâmetro*/
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
                                                                            /*Passe a escolha de região para o método de geração de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensCentroOeste();
                                                                                /*Passe a escolha de cidade para a geração de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }

                                                                            }
                                                                        }
                                                                        break;

                                                                        case 1:{
                                                                            /*Passe a escolha de região para o método de geração de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensNordeste();
                                                                                /*Passe a escolha de cidade para a geração de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }
                                                                            }

                                                                        }
                                                                        break;

                                                                        case 2:{
                                                                            /*Passe a escolha de região para o método de geração de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensNorte();
                                                                                /*Passe a escolha de cidade para a geração de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }
                                                                            }

                                                                        }
                                                                        break;

                                                                        case 3:{
                                                                            /*Passe a escolha de região para o método de geração de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensSudeste();
                                                                                /*Passe a escolha de cidade para a geração de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }
                                                                            }

                                                                        }
                                                                        break;

                                                                        case 4:{
                                                                            /*Passe a escolha de região para o método de geração de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensSul();
                                                                                /*Passe a escolha de cidade para a geração de passagem*/
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
                                                                    /*Execute o método de taxas e pegue como parâmetro escolhas*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        break;
                                                                    }
                                                                }

                                                            }
                                                            break;

                                                            case 3:{
                                                                while(1){
                                                                    Escolhas = Agencia.ClienteInserindoData();

                                                                    switch(Escolhas){
                                                                        case 0:{
                                                                            cout << endl << "EXECUTE O MÉTODO QUE PEGA A DATA DE IDA (DIA MÊS ANO) SEPARADO POR ESPAÇO";
                                                                            cout << endl << "APÓS ISSO EXECUTE O MÉTODO QUE VERIFICA SE A DATA É DISPONÍVEL" << endl << endl;
                                                                            system("pause");
                                                                        }
                                                                        break;

                                                                        case 1:{
                                                                            cout << endl << "EXECUTE O MÉTODO QUE PEGA A DATA DE VOLTA (DIA MÊS ANO) SEPARADO POR ESPAÇO";
                                                                            cout << endl << "APÓS ISSO EXECUTE O MÉTODO QUE VERIFICA SE A DATA É DISPONÍVEL" << endl << endl;
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

                                                            case 4:{
                                                                cout << "EXECUTE O MÉTODO QUE EXIBE A PASSAGEM DE AVIÃO QUE FOI FEITA" << endl;
                                                                cout << "EXECUTE O MÉTODO QUE CONFIRMA A PASSAGEM DO CLIENTE SE ELE APERTAR PARA DIREITA"
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

                                                /*Coisas do ônibus*/
                                                case 1:{
                                                    while(1){
                                                        Escolhas = Agencia.ClienteCriacaoDePassagem();
                                                        switch(Escolhas){
                                                            /*Escolha de origem*/
                                                            case 0:{
                                                                while(1){
                                                                    Escolhas = Agencia.ClienteOrigem();
                                                                    /*Execute o método que pega a origem e passe escolhas como parâmetro*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                            break;

                                                            case 1:{
                                                                /*Para todas as escolhas do destino, deve-se utilizar o método que recebe a posição da respectiva região
                                                                para que possa ser escolhido e atribuído a distância correspondente*/
                                                                while(1){
                                                                    Escolhas = Agencia.ClientePassagensRegioes();

                                                                    switch(Escolhas){
                                                                        case 0:{
                                                                            /*Passe a escolha de região para o método de geração de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensCentroOeste();
                                                                                /*Passe a escolha de cidade para a geração de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }
                                                                            }
                                                                        }
                                                                        break;

                                                                        case 1:{
                                                                            /*Passe a escolha de região para o método de geração de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensNordeste();
                                                                                /*Passe a escolha de cidade para a geração de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }
                                                                            }

                                                                        }
                                                                        break;

                                                                        case 2:{
                                                                            /*Passe a escolha de região para o método de geração de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensNorte();
                                                                                /*Passe a escolha de cidade para a geração de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }
                                                                            }

                                                                        }
                                                                        break;

                                                                        case 3:{
                                                                            /*Passe a escolha de região para o método de geração de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensSudeste();
                                                                                /*Passe a escolha de cidade para a geração de passagem*/
                                                                                if(Escolhas == 99){
                                                                                    Escolhas = 0;
                                                                                    break;
                                                                                }
                                                                            }

                                                                        }
                                                                        break;

                                                                        case 4:{
                                                                            /*Passe a escolha de região para o método de geração de passagem*/
                                                                            while(1){
                                                                                Escolhas = Agencia.ClientePassagensSul();
                                                                                /*Passe a escolha de cidade para a geração de passagem*/
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
                                                                    /*Execute o método de taxas e pegue como parâmetro escolhas*/
                                                                    if(Escolhas == 99){
                                                                        Escolhas = 0;
                                                                        break;
                                                                    }
                                                                }

                                                            }
                                                            break;

                                                            case 3:{
                                                                while(1){
                                                                    Escolhas = Agencia.ClienteInserindoData();

                                                                    switch(Escolhas){
                                                                        case 0:{
                                                                            cout << endl << "EXECUTE O MÉTODO QUE PEGA A DATA DE IDA (DIA MÊS ANO) SEPARADO POR ESPAÇO";
                                                                            cout << endl << "APÓS ISSO EXECUTE O MÉTODO QUE VERIFICA SE A DATA É DISPONÍVEL" << endl << endl;
                                                                            system("pause");
                                                                        }
                                                                        break;

                                                                        case 1:{
                                                                            cout << endl << "EXECUTE O MÉTODO QUE PEGA A DATA DE VOLTA (DIA MÊS ANO) SEPARADO POR ESPAÇO";
                                                                            cout << endl << "APÓS ISSO EXECUTE O MÉTODO QUE VERIFICA SE A DATA É DISPONÍVEL" << endl << endl;
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

                                                            case 4:{
                                                                cout << "EXECUTE O MÉTODO QUE EXIBE A PASSAGEM DE ÔNIBUS QUE FOI FEITA" << endl;
                                                                cout << "EXECUTE O MÉTODO QUE CONFIRMA A PASSAGEM DO CLIENTE SE ELE APERTAR PARA DIREITA"
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
                                                        /*Passe escolhas como parâmetro da criação do cliente passagens
                                                        crueiro*/
                                                        /*Execute o método de pergunta (pacote lua de mel)*/
                                                        /*Execute o método de pergunta de acompanhante*/
                                                        if(Escolhas == 99){
                                                            Escolhas = 0;
                                                            break;
                                                        }

                                                        else{
                                                            /*O método do cruzeiro é executado depois do método anteior, sendo feito no else if da escolha*/
                                                            Escolhas = Agencia.ClientePersonalizeSeuCruzeiro();
                                                            /*Esse método realmente não tem break*/
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
                                                    cout << "COLOQUE OS COUTS DO HÓTEL DE 5 ESTRELAS, E PASSA O PARÂMETRO PARA O MÉTODO DE ESCOLHA DE HOÉTEIS" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 1:{
                                                    cout << "COLOQUE OS COUTS DO HÓTEL DE 4 ESTRELAS, E PASSA O PARÂMETRO PARA O MÉTODO DE ESCOLHA DE HOÉTEIS" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 2:{
                                                    cout << "COLOQUE OS COUTS DO HÓTEL DE 3 ESTRELAS, E PASSA O PARÂMETRO PARA O MÉTODO DE ESCOLHA DE HOÉTEIS" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 3:{
                                                    cout << "COLOQUE OS COUTS DO HÓTEL DE 2 ESTRELAS, E PASSA O PARÂMETRO PARA O MÉTODO DE ESCOLHA DE HOÉTEIS" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 4:{
                                                    cout << "COLOQUE OS COUTS DO HÓTEL DE 1 ESTRELAS, E PASSA O PARÂMETRO PARA O MÉTODO DE ESCOLHA DE HOÉTEIS" << endl;
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
                                        cout << endl << "EXECUTE O MÉTODO DE CANCELAMENTO DE PASSAGENS" << endl;
                                        system("pause");
                                    }
                                    break;

                                    case 3:{
                                        while(1){
                                            Escolhas = Agencia.ClienteEditarCadastro();

                                            switch(Escolhas){
                                                case 0:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE EMAIL" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 1:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE SENHA" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 2:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTEREAÇÃO DE NOME" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 3:{
                                                    cout << endl << "EXECUTE O MÉTODO DE NASCIMENTO" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 4:{
                                                    cout << endl << "EXECUTE O MÉTODO ALTERAÇÃO DE ENDEREÇO" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 5:{
                                                    cout << endl << "EXECUTE O MÉTODO DE TELEFONE" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 6:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE TELEFONE FAMILAIR" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 7:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE DOCUMENTO" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 8:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE ORÇAMENTO" << endl;
                                                    system("pause");
                                                }
                                                break;

                                                case 9:{
                                                    cout << endl << "EXECUTE O MÉTODO DE ALTERAÇÃO DE ACAOMPANHANTE" << endl;
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
                            cout << "EXECUTE O MÉTODO PARA CADASTRAR O CLIENTE" << endl;
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
            Escolhas = 0; /*Redefinindo o valor da variável*/
            cout << endl << "O programa foi encerrado" << endl;
            system("pause");
            break;
        }
    }

    return 0;
}
