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
    MensagemAmigavel.push_back("MENU DE FUNCIONÁRIO ");
    MensagemAmigavel.push_back("POR FAVOR ESCOLHA A BAIXO O CARGO COM O QUAL QUER ENTRAR NO SISTEMA");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
/*Menu responsável pela interação do funcionário presidente*/
int const Menus::FuncionarioPresidente(){
    string Menu[4] = {"RELATÓRIO GERAL DA EMPRESA", "ALTERAR TAXAS DA EMPRESA", "DEMITIR FUNCIONÁRIOS", "ACESSAR REGISTRO DE PASSAGENS"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("AGÊNCIA DE VIAGENS AIRPLANE");
    MensagemAmigavel.push_back("BEM VINDO, PRESIDENTE");

    Exibidor.clear();
    for(int I=0; I<4; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();

}
/*Menu responsável pela alteração de taxas*/
int const Menus::FuncionarioPresidenteAlteracaoDeTaxas(){
    string Menu[6] = {"ALTERÇÃO DE TAXA AÉREA - ECONÔMICA", "ALTERÇÃO DE TAXA AÉREA - EXECUTIVA", "ALTERÇÃO DE TAXA AÉREA - PRIMEIRA CLASSE",
    "ALTERÇÃO DE TAXA TERRESTR - ECONÔMICA", "ALTERÇÃO DE TAXA TERRESTR - EXECUTIVA","ALTERÇÃO DE TAXA MARÍTIMA"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("AGÊNCIA DE VIAGENS AIRPLANE");
    MensagemAmigavel.push_back("BEM VINDO, PRESIDENTE");

    Exibidor.clear();
    for(int I=0; I<6; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();

}
/*Menu responsável pela interação de checagem de registro de passagens*/
int const Menus::FuncionarioPresidenteRegistroDePassagens(){
    string Menu[3] = {"VENDAS DE PASSAGENS DE ÔNIBUS", "VENDAS DE PASSAGENS DE AVIÃO", "VENDA DE PASSAGENS DE CRUZEIRO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("AGÊNCIA DE VIAGENS AIRPLANE");
    MensagemAmigavel.push_back("BEM VINDO, PRESIDENTE");

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();

}

/*Menu do Funcionário*/
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
    string Menu[3] = {"PASSAGENS DE AVIÃO","PASSAGENS DE ONIBUS","PASSAGENS DE CRUZEIRO"};

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu do Gerente*/
int const Menus::FuncionarioGerente(){
    string Menu[3] = {"DESPEDIR FUNCIONÁRIO","VER SEUS DADOS","EDITAR SEUS DADOS"};

    Exibidor.clear();
    for(int I=0; I<3; I++){
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
    MensagemAmigavel.push_back("MENU DE CLIENTE");

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para entrar no menu geral do usuário*/
int const Menus::ClienteEntrar(){
    string Menu[5] = {"COMPRAR PASSAGENS", "VER HÓTEIS", "VER PONTOS TURÍSTICOS", "EDITAR COMPRAS", "EDITAR PERFIL"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("MENU DE CLIENTE - PERFIL");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para o Usuário criar um cadastro*/
int const Menus::ClienteCriarCadastro(){
    string Menu[1] = {"MÉTODOS PARA CRIAR CADASTRO"};

    Exibidor.clear();
    for(int I=0; I<1; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para comprar a passagem*/
int const Menus::ClienteComprarPassagens(){
    string Menu[3] = {"PASSAGENS DE AVIÃO","PASSAGENS DE ÔNIBUS","PASSAGENS DE CRUZEIRO"};

    MensagemAmigavel.clear();
    MensagemAmigavel.push_back("MENU DE CLIENTE - PERFIL");

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
    MensagemAmigavel.push_back("MENU DE CLIENTE - PERFIL");

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menus com as cidades disponíveis para compra de passagens*/
int const Menus::ClientePassagensNordeste(){
    string Menu[9] = {"ARACAJU","FORTALEZA","JOÃO PESSOA","MACEIÓ","NATAL","RECIFE","SALVADOR","SÃO LUÍS","TERESINA"};

    Exibidor.clear();
    for(int I=0; I<9; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensNorte(){
    string Menu[7] = {"BELÉM","BOA VISTA","MACAPÁ","MANAUS","PALMAS","PORTO VELHO","RIO BRANCO"};

    Exibidor.clear();
    for(int I=0; I<5; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensSudeste(){
    string Menu[4] = {"BELO HORIZONTE","RIO DE JANEIRO","SÃO PAULO","VITÓRIA"};

    Exibidor.clear();
    for(int I=0; I<4; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensSul(){
    string Menu[3] = {"CURITIBA","FLORIANÓPOLIS","PORTO ALEGRE"};

    Exibidor.clear();
    for(int I=0; I<3; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

int const Menus::ClientePassagensCentroOeste(){
    string Menu[4] = {"BRASÍLIA","CUIABÁ","CAMPO GRANDE","GOIÂNIA"};

    Exibidor.clear();
    for(int I=0; I<4; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu com as opções de passagem de Cruzeiro*/
int const Menus::ClientePassagensCruzeiro(){
    string Menu[2] = {"SALVADOR -> EUROPA","SALVADOR -> CARIBE"};

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para edição de compras*/
int const Menus::ClienteEditarCompras(){
    string Menu[2] = {"VER COMPRAS","CANCELAR COMPRAS"};

    Exibidor.clear();
    for(int I=0; I<2; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}

/*Menu para edição de cadastro*/
int const Menus::ClienteEditarCadastro(){
    string Menu[8] = {"MUDAR EMAIL","MUDAR SENHA","MUDAR NOME","MUDAR DATA","MUDAR ENDEREÇO","MUDAR TELEFONE","MUDAR TELEFONE FAMILIAR",
    "MUDAR DOCUMENTO"};

    Exibidor.clear();
    for(int I=0; I<8; I++){
        Exibidor.push_back(Menu[I]);
    }

    return ExibidorDeMenus();
}
