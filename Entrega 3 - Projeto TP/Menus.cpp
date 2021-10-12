#include "Menus.h"

/*###############################################################################################################*/
/*###############################################################################################################*/

/*Fun��es usadas para exibir o menu e a forma de troca de cores, elas servem de padr�o e s�o chamadas dentro
dos m�todos [N�O ALTERAR OS M�TODOS DESSE BLOCO, POIS PODE COMPROMETER AS SA�DAS E FUNCIONAMENTO DO MENU]*/

/*Vari�veis inicializadas para as fun��es do textcolor*/
static int __BACKGROUND = 0;    /*Preto*/
static int __FOREGROUND = 15;   /*Branco*/

void textcolor (int letras, int fundo){

    __FOREGROUND = letras;
    __BACKGROUND = fundo;

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), letras + (__BACKGROUND << 4));
}

int const Menus::ExibidorDeMenus(){

    /*N�O ALTERAR A EXIBI��O PADR�O DE MENUS, OS
    M�TODOS ADICIONADOS PARA NOVOS MENUS, CHAMAM ESSE
    AO FINAL*/

    int PosicaoMenu = 0;
    int Controle = 0;

    while(1){
        system("cls");

        textcolor(4,0);
        for(int i=0; i<MensagemAmigavel.size(); i++){
            cout << MensagemAmigavel[i] << endl;
        }
        cout << endl;
        textcolor(15,0);

        for(int I=0; I<Exibidor.size(); I++){
            if(I == PosicaoMenu){
                textcolor(2,0); /*2 = Ciano*/
                cout << Exibidor[I] << endl;
                cout << "  [ <- Voltar || -> Escolher ]" << endl;
            }
            else{
                textcolor(15,0); /*Voltando a cor original*/
                cout << Exibidor[I] << endl;
            }

        }

        textcolor(15,0); /*Ao final deve se voltar ao original*/

        /*Funcionamento de comandos*/
        Controle = getch();
        if(Controle == 80){
            PosicaoMenu++;
            if(PosicaoMenu > Exibidor.size()-1)
                PosicaoMenu = 0;
            continue;
        }
        else if(Controle == 72){
            PosicaoMenu--;
            if(PosicaoMenu < 0)
                PosicaoMenu = Exibidor.size()-1;
            continue;
        }
        else if(Controle == 75)
            return 99;
        else if(Controle == 77)
            return PosicaoMenu;
    }

}

/*###############################################################################################################*/
/*###############################################################################################################*/

/*M�todos para todos os menus*/

int const Menus::MenuGeral(){

    string Menu[2] = {"FUNCION�RIO", "CLIENTE"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("EMPRESA DE VIAGENS AIRPLANE");

    Exibidor.clear();
    for(int I=0; I<2; /*O .size n�o fucniona*/ I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();

/*###############################################################################################################*/
/*###############################################################################################################*/

}/*Menus respons�veis pela intere��o com os funcion�rios*/
int const Menus::Funcionario(){

    string Menu[3] = {"ENTRAR COMO PRESIDENTE", "ENTRAR COMO GERENTE", "ENTRAR COMO FUNCION�RIO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("BEM VINDO A EMRPRESA DE VIAGENS AIRPLANE ");
    MensagemAmigavel.push_back("POR FAVOR ESCOLHA A BAIXO O CARGO COM O QUAL QUER ENTRAR NO SISTEMA");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu respons�vel pela intera��o do funcion�rio presidente*/
int const Menus::FuncionarioPresidente(){
    string Menu[2] = {"RELAT�RIO GERAL DA EMPRESA", "DEMITIR FUNCION�RIOS"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("AG�NCIA DE VIAGENS AIRPLANE");
    MensagemAmigavel.push_back("BEM VINDO, PRESIDENTE");

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();

}

/*Menu respons�vel pela intera��o do funcion�rio gerente*/
int const Menus::FuncionarioGerente(){
    string Menu[3] = {"DESPEDIR FUNCION�RIO","CADASTRAR NOVO FUNCION�RIO","EXIBIR FUNCION�RIOS"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("BEM VINDO, GERENTE");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu do Funcion�rio*/
int const Menus::FuncionarioFuncionario(){
    string Menu[3] = {"VENDER PASSAGENS","MEUS DADOS","EDITAR MEUS DADOS"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("BEM VINDO, VENDEDOR");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu de venda de passagens*/
int const Menus::FuncionarioFuncionarioVenderPassagens(){
    string Menu[3] = {"PASSAGENS DE AVI�O","PASSAGENS DE ONIBUS","PASSAGENS DE CRUZEIRO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("ESCOLHA A PASSAGEM QUE DESEJA VENDER");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu respons�vel pela altera��o de dados de funion�rios (Gerentes e vendedores)*/
int const Menus::FuncionarioAlteracaoDados(){
    string Menu[6] = {"SENHA","NOME COMPLETO", "ENDERE�O","TELEFONE","TELEFONE FAMILIAR","DOCUMENTO"};
;
    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("BEM VINDO, AQUI VOC� PODE ALTERAR SEUS DADOS!");

    Exibidor.clear();
    for(int I=0; I<6; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*###############################################################################################################*/
/*###############################################################################################################*/

/*Menus respons�veis pela intere��o com o cliente*/
int const Menus::Cliente(){

    string Menu[2] = {"ENTRAR", "CADASTRE-SE"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("CLIENTE AIRPLANE");

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para entrar no menu geral do usu�rio*/
int const Menus::ClienteEntrar(){
    string Menu[7] = {"COMPRAR PASSAGENS", "VER H�TEIS", "CANCELAR PASSAGENS", "EDITAR PERFIL", "MEUS DADOS","VER MINHAS PASSAGENS CONFIRMADAS","VER MINHAS PASSAGENS PENDENTES"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("BEM VINDO, SENHOR CLIENTE! O QUE DESEJA FAZER HOJE?");

    Exibidor.clear();
    for(int I=0; I<7; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para comprar a passagem*/
int const Menus::ClienteComprarPassagens(){
    string Menu[3] = {"PASSAGENS DE AVI�O","PASSAGENS DE �NIBUS","PASSAGENS DE CRUZEIRO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("QUAL O TIPO DE PASSAGEM O SENHOR DESEJA COMPRAR?");

    Exibidor.clear();
    for(int I=0;I<3;I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu com as Regi�es para compra de passagem para Avi�o e Onibus*/
int const Menus::ClientePassagensRegioes(){
    string Menu[5] = {"CENTRO-OESTE","NORDESTE","NORTE","SUDESTE","SUL"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("REGI�ES DISPON�VEIS");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menus com as cidades dispon�veis para compra de passagens*/
int const Menus::ClientePassagensNordeste(){
    string Menu[9] = {"ARACAJU","FORTALEZA","JO�O PESSOA","MACEI�","NATAL","RECIFE","SALVADOR","S�O LU�S","TERESINA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("CIDADES DISPON�VEIS");

    Exibidor.clear();
    for(int I=0; I<9; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensNorte(){
    string Menu[7] = {"BEL�M","BOA VISTA","MACAP�","MANAUS","PALMAS","PORTO VELHO","RIO BRANCO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("CIDADES DISPON�VEIS");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensSudeste(){
    string Menu[4] = {"BELO HORIZONTE","RIO DE JANEIRO","S�O PAULO","VIT�RIA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("CIDADES DISPON�VEIS");

    Exibidor.clear();
    for(int I=0; I<4; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensSul(){
    string Menu[3] = {"CURITIBA","FLORIAN�POLIS","PORTO ALEGRE"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("CIDADES DISPON�VEIS");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensCentroOeste(){
    string Menu[4] = {"BRAS�LIA","CUIAB�","CAMPO GRANDE","GOI�NIA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("CIDADES DISPON�VEIS");

    Exibidor.clear();
    for(int I=0; I<4; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu com as op��es de passagem de Cruzeiro*/
int const Menus::ClientePassagensCruzeiro(){
    string Menu[3] = {"SALVADOR -> EUROPA","SALVADOR -> CARIBE","TERMINOU DE MONTAR SUA PASSAGEM? CLIQUE AQUI PARA CONFIRMAR A SUA COMPRA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("SENHOR CLIENTE, POR FAVOR PRESTE BRASTANTE ATE��O NAS SEGUINTES INSTRU��ES PARA QUANDO FOR INSERIR A SUA DATA:");
    MensagemAmigavel.push_back("");
    MensagemAmigavel.push_back("01 - INSIRA A DATA NO FORMATO (DIA M�S ANO) SEPARADO POR ESPA�OS");
    MensagemAmigavel.push_back("02 - O DIA DEVE SER ESCRITO COM DOIS ALGARISMOS (POR EXEMPLO: 01, 08, 23)");
    MensagemAmigavel.push_back("03 - O M�S DEVE SER ESCRITO COM DOIS ALGARISMOS (POR EXEMPLO: 05, 06, 12)");
    MensagemAmigavel.push_back("04 - O ANO DEVE SER ESCRITO COM QUATRO ALGARISMOS (POR EXEMPLO: 2021, 2022)");
    MensagemAmigavel.push_back("05 - LEMBRE-SE DA N�O INSERIR DATAS QUE J� PASSARAM, SE O FIZER, SER� ORIENTADO A INSERIR A DATA NOVAMENTE");
    MensagemAmigavel.push_back("06 - NOSSA EMPRESA TRABALHA APENAS COM ANTECIPA��O APENAS PARA O T�RMINO DO ANO ATUAL");
    MensagemAmigavel.push_back("07 - AS PASSAGENS S� PODEM SER COMPRADAS COM NO M�NIMO 48 HORAS DE ANTECD�NCIA");
    MensagemAmigavel.push_back("");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para edi��o de cadastro*/
int const Menus::ClienteEditarCadastro(){
    string Menu[7] = {"EMAIL","SENHA","NOME COMPLETO","ENDERE�O","TELEFONE","TELEFONE FAMILIAR","DOCUMENTO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("BEM VINDO, AQUI VOC� PODE ALTERAR SEUS DADOS!");

    Exibidor.clear();
    for(int I=0; I<7; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu para cria��o de passageem de avi�o e de �nibus*/
int const Menus::ClienteCriacaoDePassagem(){
    string Menu[5] = {"ORIGEM","DESTINO","TIPO DA PASSAGEM", "DATAS DA PASSAGEM","TERMINOU DE MONTAR SUA PASSAGEM? CLIQUE AQUI PARA CONFIRMAR A SUA COMPRA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("MONTE A SUA PASSAGEM");
    MensagemAmigavel.push_back("CUIDADO, AO SAIR DESSA P�GINA, AS INFORMA��ES ADICIONADAS SER�O APAGADAS");
    MensagemAmigavel.push_back("POR FAVOR, CONCLUA A MONTAGEM DA PASSAGEM ANTES DE SAIR");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu para cria��o de taxa de passageem de avi�o*/
int const Menus::ClienteEscolhaDeTaxaDeAviao(){
    string Menu[3] = {"PASSAGEM ECON�MICA", "PASSAGEM EXECUTIVA","PASSAGEM DE PRIMEIRA CLASSE",};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("ESCOLHA O N�VEL DO SEU CONFORTO");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
int const Menus::ClienteEscolhaDeTaxaDeOnibus(){
    string Menu[2] = {"PASSAGEM ECON�MICA", "PASSAGEM EXECUTIVA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("ESCOLHA O N�VEL DO SEU CONFORTO");

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*M�todo para exibir as op��es de origem*/
int const Menus::ClienteOrigem(){
    string Menu[5] = {"CENTRO-OESTE - BRAS�LIA","NORDESTE - JO�O PESSOA","NORTE - MANAUS","SUDESTE - S�O PAULO","SUL - FLORIAN�POLIS "};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("REGI�ES DISPON�VEIS");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*M�todo para personalizar a passagem de cruzeiro*/
int const Menus::ClientePersonalizeSeuCruzeiro(){
    string Menu[2] = {"PACOTE LUA DE MEL", "PACOTE FAM�LIA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("REGI�ES DISPON�VEIS");

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*M�todo para chamada de datas*/
int const Menus::ClienteInserindoData(){
    string Menu[2] = {"DATA DE IDA", "DATA DE VOLTA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("SENHOR CLIENTE, POR FAVOR PRESTE BRASTANTE ATE��O NAS SEGUINTES INSTRU��ES PARA QUANDO FOR INSERIR A SUA DATA:");
    MensagemAmigavel.push_back("");
    MensagemAmigavel.push_back("01 - INSIRA A DATA NO FORMATO (DIA M�S ANO) SEPARADO POR ESPA�OS");
    MensagemAmigavel.push_back("02 - O DIA DEVE SER ESCRITO COM DOIS ALGARISMOS (POR EXEMPLO: 01, 08, 23)");
    MensagemAmigavel.push_back("03 - O M�S DEVE SER ESCRITO COM DOIS ALGARISMOS (POR EXEMPLO: 05, 06, 12)");
    MensagemAmigavel.push_back("04 - O ANO DEVE SER ESCRITO COM QUATRO ALGARISMOS (POR EXEMPLO: 2021, 2022)");
    MensagemAmigavel.push_back("05 - LEMBRE-SE DA N�O INSERIR DATAS QUE J� PASSARAM, SE O FIZER, SER� ORIENTADO A INSERIR A DATA NOVAMENTE");
    MensagemAmigavel.push_back("06 - NOSSA EMPRESA TRABALHA APENAS COM ANTECIPA��O APENAS PARA O T�RMINO DO ANO ATUAL");
    MensagemAmigavel.push_back("07 - INSIRA O HOR�RIO PARA PASSAGENS DE AVI�O (0 - PARA 10 HORAS, 1 - PARA AS 15 HORAS, 2 - PARA AS 21 HORAS)");
    MensagemAmigavel.push_back("08 - SE N�O QUISER UMA PASSAGEM DE VOLTA, INSIRA A DATA DA PASSAGEM DE VOLTA SENDO (0 0 0)");
    MensagemAmigavel.push_back("09 - O VALOR DA SUA PASSAGEM IR� SUBIR EM 75% CASO DEFINA UMA DATA PARA VOLTA");
    MensagemAmigavel.push_back("10 - AS PASSAGENS S� PODEM SER COMPRADAS COM NO M�NIMO 48 HORAS DE ANTECD�NCIA");
    MensagemAmigavel.push_back("");
    MensagemAmigavel.push_back("OBRIGADO POR ESCOLHER A AIRPLANE PARA OS SEUS SERVIOS DE VIAGEM");

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
