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
            cout << "   " << MensagemAmigavel[i] << endl;
        }
        cout << endl;
        textcolor(15,0);

        for(int I=0; I<Exibidor.size(); I++){
            if(I == PosicaoMenu){
                textcolor(2,0); /*2 = Ciano*/
                cout << "   " << Exibidor[I] << endl;
                cout << "       [ <- Voltar || -> Entrar ]" << endl;
            }
            else{
                textcolor(15,0); /*Voltando a cor original*/
                cout << "   " << Exibidor[I] << endl;
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
    MensagemAmigavel.push_back("MENU DE FUNCION�RIO ");
    MensagemAmigavel.push_back("POR FAVOR ESCOLHA A BAIXO O CARGO COM O QUAL QUER ENTRAR NO SISTEMA");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu respons�vel pela intera��o do funcion�rio presidente*/
int const Menus::FuncionarioPresidente(){
    string Menu[4] = {"RELAT�RIO GERAL DA EMPRESA", "ALTERAR TAXAS DA EMPRESA", "DEMITIR FUNCION�RIOS", "ACESSAR REGISTRO DE PASSAGENS"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("AG�NCIA DE VIAGENS AIRPLANE");
    MensagemAmigavel.push_back("BEM VINDO, PRESIDENTE");

    Exibidor.clear();
    for(int I=0; I<4; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();

}
/*Menu respons�vel pela altera��o de taxas*/
int const Menus::FuncionarioPresidenteAlteracaoDeTaxas(){
    string Menu[6] = {"ALTER��O DE TAXA A�REA - ECON�MICA", "ALTER��O DE TAXA A�REA - EXECUTIVA", "ALTER��O DE TAXA A�REA - PRIMEIRA CLASSE",
    "ALTER��O DE TAXA TERRESTR - ECON�MICA", "ALTER��O DE TAXA TERRESTR - EXECUTIVA","ALTER��O DE TAXA MAR�TIMA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("AG�NCIA DE VIAGENS AIRPLANE");
    MensagemAmigavel.push_back("BEM VINDO, PRESIDENTE");

    Exibidor.clear();
    for(int I=0; I<6; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();

}
/*Menu respons�vel pela intera��o de checagem de registro de passagens*/
int const Menus::FuncionarioPresidenteRegistroDePassagens(){
    string Menu[3] = {"VENDAS DE PASSAGENS DE �NIBUS", "VENDAS DE PASSAGENS DE AVI�O", "VENDA DE PASSAGENS DE CRUZEIRO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("AG�NCIA DE VIAGENS AIRPLANE");
    MensagemAmigavel.push_back("BEM VINDO, PRESIDENTE");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();

}

/*Menu do Funcion�rio*/
int const Menus::FuncionarioFuncionario(){
    string Menu[3] = {"VENDER PASSAGENS","VER SEUS DADOS","EDITAR SEUS DADOS"};

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu de venda de passagens*/
inst const Menus::FuncionarioFuncionarioVenderPassagens(){
    string Menu[3] = {"PASSAGENS DE AVI�O","PASSAGENS DE ONIBUS","PASSAGENS DE CRUZEIRO"};

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu do Gerente*/
int const Menus::FuncionarioGerente(){
    string Menu[3] = {"DESPEDIR FUNCION�RIO","VER SEUS DADOS","EDITAR SEUS DADOS"};

    Exibidor.clear();
    for(int I=0; I<3; I++){
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
    MensagemAmigavel.push_back("MENU DE CLIENTE");

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para entrar no menu geral do usu�rio*/
int const Menus::ClienteEntrar(){
    string Menu[5] = {"COMPRAR PASSAGENS", "VER H�TEIS", "VER PONTOS TUR�STICOS", "EDITAR COMPRAS", "EDITAR PERFIL"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("MENU DE CLIENTE - PERFIL");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para o Usu�rio criar um cadastro*/
int const Menus::ClienteCriarCadastro(){
    string Menu[1] = {"M�TODOS PARA CRIAR CADASTRO"};

    Exibidor.clear();
    for(int I=0; I<1; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para comprar a passagem*/
int const Menus::ClienteComprarPassagens(){
    string Menu[3] = {"PASSAGENS DE AVI�O","PASSAGENS DE �NIBUS","PASSAGENS DE CRUZEIRO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("MENU DE CLIENTE - PERFIL");

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
    MensagemAmigavel.push_back("MENU DE CLIENTE - PERFIL");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menus com as cidades dispon�veis para compra de passagens*/
int const Menus::ClientePassagensNordeste(){
    string Menu[9] = {"ARACAJU","FORTALEZA","JO�O PESSOA","MACEI�","NATAL","RECIFE","SALVADOR","S�O LU�S","TERESINA"};

    Exibidor.clear();
    for(int I=0; I<9; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensNorte(){
    string Menu[7] = {"BEL�M","BOA VISTA","MACAP�","MANAUS","PALMAS","PORTO VELHO","RIO BRANCO"};

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensSudeste(){
    string Menu[4] = {"BELO HORIZONTE","RIO DE JANEIRO","S�O PAULO","VIT�RIA"};

    Exibidor.clear();
    for(int I=0; I<4; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensSul(){
    string Menu[3] = {"CURITIBA","FLORIAN�POLIS","PORTO ALEGRE"};

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensCentroOeste(){
    string Menu[4] = {"BRAS�LIA","CUIAB�","CAMPO GRANDE","GOI�NIA"};

    Exibidor.clear();
    for(int I=0; I<4; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu com as op��es de passagem de Cruzeiro*/
int const Menus::ClientePassagensCruzeiro(){
    string Menu[2] = {"SALVADOR -> EUROPA","SALVADOR -> CARIBE"};

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para edi��o de compras*/
int const Menus::ClienteEditarCompras(){
    string Menu[2] = {"VER COMPRAS","CANCELAR COMPRAS"};

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para edi��o de cadastro*/
int const Menus::ClienteEditarCadastro(){
    string Menu[8] = {"MUDAR EMAIL","MUDAR SENHA","MUDAR NOME","MUDAR DATA","MUDAR ENDERE�O","MUDAR TELEFONE","MUDAR TELEFONE FAMILIAR",
    "MUDAR DOCUMENTO"};

    Exibidor.clear();
    for(int I=0; I<8; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
