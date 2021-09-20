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
                cout << "   [1 Voltar || 2 Entrar]" << endl;
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
        else if(Controle == 49)
            return 99;
        else if(Controle == 50)
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
    MensagemAmigavel.push_back("MENU DE FUNCIO�RIO ");
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

/*###############################################################################################################*/
/*###############################################################################################################*/

/*Menus respons�veis pela intere��o com o cliete*/
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
