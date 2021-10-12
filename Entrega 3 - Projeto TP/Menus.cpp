#include "Menus.h"

/*###############################################################################################################*/
/*###############################################################################################################*/

/*Funções usadas para exibir o menu e a forma de troca de cores, elas servem de padrão e são chamadas dentro
dos métodos [NÃO ALTERAR OS MÉTODOS DESSE BLOCO, POIS PODE COMPROMETER AS SAÍDAS E FUNCIONAMENTO DO MENU]*/

/*Variáveis inicializadas para as funções do textcolor*/
static int __BACKGROUND = 0;    /*Preto*/
static int __FOREGROUND = 15;   /*Branco*/

void textcolor (int letras, int fundo){

    __FOREGROUND = letras;
    __BACKGROUND = fundo;

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), letras + (__BACKGROUND << 4));
}

int const Menus::ExibidorDeMenus(){

    /*NÃO ALTERAR A EXIBIÇÃO PADRÃO DE MENUS, OS
    MÉTODOS ADICIONADOS PARA NOVOS MENUS, CHAMAM ESSE
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

/*Métodos para todos os menus*/

int const Menus::MenuGeral(){

    string Menu[2] = {"FUNCIONÁRIO", "CLIENTE"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("EMPRESA DE VIAGENS AIRPLANE");

    Exibidor.clear();
    for(int I=0; I<2; /*O .size não fucniona*/ I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();

/*###############################################################################################################*/
/*###############################################################################################################*/

}/*Menus responsáveis pela intereção com os funcionários*/
int const Menus::Funcionario(){

    string Menu[3] = {"ENTRAR COMO PRESIDENTE", "ENTRAR COMO GERENTE", "ENTRAR COMO FUNCIONÁRIO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("BEM VINDO A EMRPRESA DE VIAGENS AIRPLANE ");
    MensagemAmigavel.push_back("POR FAVOR ESCOLHA A BAIXO O CARGO COM O QUAL QUER ENTRAR NO SISTEMA");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu responsável pela interação do funcionário presidente*/
int const Menus::FuncionarioPresidente(){
    string Menu[2] = {"RELATÓRIO GERAL DA EMPRESA", "DEMITIR FUNCIONÁRIOS"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("AGÊNCIA DE VIAGENS AIRPLANE");
    MensagemAmigavel.push_back("BEM VINDO, PRESIDENTE");

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();

}

/*Menu responsável pela interação do funcionário gerente*/
int const Menus::FuncionarioGerente(){
    string Menu[3] = {"DESPEDIR FUNCIONÁRIO","CADASTRAR NOVO FUNCIONÁRIO","EXIBIR FUNCIONÁRIOS"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("BEM VINDO, GERENTE");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu do Funcionário*/
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
    string Menu[3] = {"PASSAGENS DE AVIÃO","PASSAGENS DE ONIBUS","PASSAGENS DE CRUZEIRO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("ESCOLHA A PASSAGEM QUE DESEJA VENDER");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu responsável pela alteração de dados de funionários (Gerentes e vendedores)*/
int const Menus::FuncionarioAlteracaoDados(){
    string Menu[6] = {"SENHA","NOME COMPLETO", "ENDEREÇO","TELEFONE","TELEFONE FAMILIAR","DOCUMENTO"};
;
    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("BEM VINDO, AQUI VOCÊ PODE ALTERAR SEUS DADOS!");

    Exibidor.clear();
    for(int I=0; I<6; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*###############################################################################################################*/
/*###############################################################################################################*/

/*Menus responsáveis pela intereção com o cliente*/
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

/*Menu para entrar no menu geral do usuário*/
int const Menus::ClienteEntrar(){
    string Menu[7] = {"COMPRAR PASSAGENS", "VER HÓTEIS", "CANCELAR PASSAGENS", "EDITAR PERFIL", "MEUS DADOS","VER MINHAS PASSAGENS CONFIRMADAS","VER MINHAS PASSAGENS PENDENTES"};

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
    string Menu[3] = {"PASSAGENS DE AVIÃO","PASSAGENS DE ÔNIBUS","PASSAGENS DE CRUZEIRO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("QUAL O TIPO DE PASSAGEM O SENHOR DESEJA COMPRAR?");

    Exibidor.clear();
    for(int I=0;I<3;I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu com as Regiões para compra de passagem para Avião e Onibus*/
int const Menus::ClientePassagensRegioes(){
    string Menu[5] = {"CENTRO-OESTE","NORDESTE","NORTE","SUDESTE","SUL"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("REGIÕES DISPONÍVEIS");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menus com as cidades disponíveis para compra de passagens*/
int const Menus::ClientePassagensNordeste(){
    string Menu[9] = {"ARACAJU","FORTALEZA","JOÃO PESSOA","MACEIÓ","NATAL","RECIFE","SALVADOR","SÃO LUÍS","TERESINA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("CIDADES DISPONÍVEIS");

    Exibidor.clear();
    for(int I=0; I<9; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensNorte(){
    string Menu[7] = {"BELÉM","BOA VISTA","MACAPÁ","MANAUS","PALMAS","PORTO VELHO","RIO BRANCO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("CIDADES DISPONÍVEIS");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensSudeste(){
    string Menu[4] = {"BELO HORIZONTE","RIO DE JANEIRO","SÃO PAULO","VITÓRIA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("CIDADES DISPONÍVEIS");

    Exibidor.clear();
    for(int I=0; I<4; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensSul(){
    string Menu[3] = {"CURITIBA","FLORIANÓPOLIS","PORTO ALEGRE"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("CIDADES DISPONÍVEIS");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensCentroOeste(){
    string Menu[4] = {"BRASÍLIA","CUIABÁ","CAMPO GRANDE","GOIÂNIA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("CIDADES DISPONÍVEIS");

    Exibidor.clear();
    for(int I=0; I<4; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu com as opções de passagem de Cruzeiro*/
int const Menus::ClientePassagensCruzeiro(){
    string Menu[3] = {"SALVADOR -> EUROPA","SALVADOR -> CARIBE","TERMINOU DE MONTAR SUA PASSAGEM? CLIQUE AQUI PARA CONFIRMAR A SUA COMPRA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("SENHOR CLIENTE, POR FAVOR PRESTE BRASTANTE ATEÇÃO NAS SEGUINTES INSTRUÇÕES PARA QUANDO FOR INSERIR A SUA DATA:");
    MensagemAmigavel.push_back("");
    MensagemAmigavel.push_back("01 - INSIRA A DATA NO FORMATO (DIA MÊS ANO) SEPARADO POR ESPAÇOS");
    MensagemAmigavel.push_back("02 - O DIA DEVE SER ESCRITO COM DOIS ALGARISMOS (POR EXEMPLO: 01, 08, 23)");
    MensagemAmigavel.push_back("03 - O MÊS DEVE SER ESCRITO COM DOIS ALGARISMOS (POR EXEMPLO: 05, 06, 12)");
    MensagemAmigavel.push_back("04 - O ANO DEVE SER ESCRITO COM QUATRO ALGARISMOS (POR EXEMPLO: 2021, 2022)");
    MensagemAmigavel.push_back("05 - LEMBRE-SE DA NÃO INSERIR DATAS QUE JÁ PASSARAM, SE O FIZER, SERÁ ORIENTADO A INSERIR A DATA NOVAMENTE");
    MensagemAmigavel.push_back("06 - NOSSA EMPRESA TRABALHA APENAS COM ANTECIPAÇÃO APENAS PARA O TÉRMINO DO ANO ATUAL");
    MensagemAmigavel.push_back("07 - AS PASSAGENS SÓ PODEM SER COMPRADAS COM NO MÍNIMO 48 HORAS DE ANTECDÊNCIA");
    MensagemAmigavel.push_back("");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para edição de cadastro*/
int const Menus::ClienteEditarCadastro(){
    string Menu[7] = {"EMAIL","SENHA","NOME COMPLETO","ENDEREÇO","TELEFONE","TELEFONE FAMILIAR","DOCUMENTO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("BEM VINDO, AQUI VOCÊ PODE ALTERAR SEUS DADOS!");

    Exibidor.clear();
    for(int I=0; I<7; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu para criação de passageem de avião e de ônibus*/
int const Menus::ClienteCriacaoDePassagem(){
    string Menu[5] = {"ORIGEM","DESTINO","TIPO DA PASSAGEM", "DATAS DA PASSAGEM","TERMINOU DE MONTAR SUA PASSAGEM? CLIQUE AQUI PARA CONFIRMAR A SUA COMPRA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("MONTE A SUA PASSAGEM");
    MensagemAmigavel.push_back("CUIDADO, AO SAIR DESSA PÁGINA, AS INFORMAÇÕES ADICIONADAS SERÃO APAGADAS");
    MensagemAmigavel.push_back("POR FAVOR, CONCLUA A MONTAGEM DA PASSAGEM ANTES DE SAIR");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu para criação de taxa de passageem de avião*/
int const Menus::ClienteEscolhaDeTaxaDeAviao(){
    string Menu[3] = {"PASSAGEM ECONÔMICA", "PASSAGEM EXECUTIVA","PASSAGEM DE PRIMEIRA CLASSE",};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("ESCOLHA O NÍVEL DO SEU CONFORTO");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
int const Menus::ClienteEscolhaDeTaxaDeOnibus(){
    string Menu[2] = {"PASSAGEM ECONÔMICA", "PASSAGEM EXECUTIVA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("ESCOLHA O NÍVEL DO SEU CONFORTO");

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Método para exibir as opções de origem*/
int const Menus::ClienteOrigem(){
    string Menu[5] = {"CENTRO-OESTE - BRASÍLIA","NORDESTE - JOÃO PESSOA","NORTE - MANAUS","SUDESTE - SÃO PAULO","SUL - FLORIANÓPOLIS "};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("REGIÕES DISPONÍVEIS");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Método para personalizar a passagem de cruzeiro*/
int const Menus::ClientePersonalizeSeuCruzeiro(){
    string Menu[2] = {"PACOTE LUA DE MEL", "PACOTE FAMÍLIA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("REGIÕES DISPONÍVEIS");

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Método para chamada de datas*/
int const Menus::ClienteInserindoData(){
    string Menu[2] = {"DATA DE IDA", "DATA DE VOLTA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("SENHOR CLIENTE, POR FAVOR PRESTE BRASTANTE ATEÇÃO NAS SEGUINTES INSTRUÇÕES PARA QUANDO FOR INSERIR A SUA DATA:");
    MensagemAmigavel.push_back("");
    MensagemAmigavel.push_back("01 - INSIRA A DATA NO FORMATO (DIA MÊS ANO) SEPARADO POR ESPAÇOS");
    MensagemAmigavel.push_back("02 - O DIA DEVE SER ESCRITO COM DOIS ALGARISMOS (POR EXEMPLO: 01, 08, 23)");
    MensagemAmigavel.push_back("03 - O MÊS DEVE SER ESCRITO COM DOIS ALGARISMOS (POR EXEMPLO: 05, 06, 12)");
    MensagemAmigavel.push_back("04 - O ANO DEVE SER ESCRITO COM QUATRO ALGARISMOS (POR EXEMPLO: 2021, 2022)");
    MensagemAmigavel.push_back("05 - LEMBRE-SE DA NÃO INSERIR DATAS QUE JÁ PASSARAM, SE O FIZER, SERÁ ORIENTADO A INSERIR A DATA NOVAMENTE");
    MensagemAmigavel.push_back("06 - NOSSA EMPRESA TRABALHA APENAS COM ANTECIPAÇÃO APENAS PARA O TÉRMINO DO ANO ATUAL");
    MensagemAmigavel.push_back("07 - INSIRA O HORÁRIO PARA PASSAGENS DE AVIÃO (0 - PARA 10 HORAS, 1 - PARA AS 15 HORAS, 2 - PARA AS 21 HORAS)");
    MensagemAmigavel.push_back("08 - SE NÃO QUISER UMA PASSAGEM DE VOLTA, INSIRA A DATA DA PASSAGEM DE VOLTA SENDO (0 0 0)");
    MensagemAmigavel.push_back("09 - O VALOR DA SUA PASSAGEM IRÁ SUBIR EM 75% CASO DEFINA UMA DATA PARA VOLTA");
    MensagemAmigavel.push_back("10 - AS PASSAGENS SÓ PODEM SER COMPRADAS COM NO MÍNIMO 48 HORAS DE ANTECDÊNCIA");
    MensagemAmigavel.push_back("");
    MensagemAmigavel.push_back("OBRIGADO POR ESCOLHER A AIRPLANE PARA OS SEUS SERVIOS DE VIAGEM");

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
