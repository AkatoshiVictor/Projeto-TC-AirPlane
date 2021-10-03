class Menus{

    /*A QUANTIDADE DE COMENT�RIOS NESSA VERS�O DO PROJETO, SE DA PELO FARO DE QUE O PROGRAMA FOI CRIADO POR 4 PESSOAS
    E TUDO QUE FOI FEITO, DEVERIA SER EXPLICADO COM DETALHES, PARA AUXILIAR QUEM FOSSE UTILIZAR CADA CLASSE
    ABAIXO VOC� ENCONTRA COMO CADA M�TODO FUNCIONA E ONDE ELE � EXECUTADO NA MAIN. FACILITANDO ASSIM TODAS AS POSS�VEIS
    ALTERA��ES*/

    private:
        /*Vector de controle para a exibi��o de menus*/
        vector <string> Exibidor;
        vector <string> MensagemAmigavel;
    public:
        /*M�todo padr�o para exibi��o de menus*/
        int const ExibidorDeMenus();                                /*Sistema para utiliza��o do menu sem cin, para uso de op��es do cliente*/

        /*M�todos para uso de menus*/
        int const MenuGeral();

        int const Funcionario();                                    /*M�todo para executar as op��es de entrada do funcion�rio*/
        /*Cargos de fcunion�rios*/
        int const FuncionarioPresidente();                          /*M�todo para executar o menu com as op��es do presidente*/

        int const FuncionarioPresidenteRegistroDePassagens();       /*M�todo para executar o menu com os m�todos de impress�o
                                                                    do registro de passagens*/

        int const FuncionarioGerente();                             /*M�todo para executar o menu com as op��es de gerente*/
        int const FuncionarioFuncionario();                         /*M�todo para executar o menu com as op��o do funcion�rio (vendedor)*/
        int const FuncionarioFuncionarioVenderPassagens();          /*M�todo para executar o menu com as op��es de vender passagem
                                                                    cada op��o executa um m�todo que mostra a primeira passagem na fila
                                                                    a ser vendidad, para auxilair o funcion�rio*/

        int const FuncionarioAlteracaoDados();                      /*M�todo para executar o menu com as op��es de altera��o de dados
                                                                    de funcion�rios e gerentes (em cada subop��o � executa um m�todo da classe
                                                                    ag�ncia dentro da main)*/


        /*M�todos para uso exclusivo do cliente*/
        int const Cliente();                                        /*M�todos para exibir as op��es de entrar e cadastrar, se for cadastrar
                                                                    � executado m�todos da classe ag�ncia na main, se for entrar, os m�todos
                                                                    abaixo auxiliam o cliente em sas escolhas*/

        int const ClienteEntrar();                                  /*M�todo para executar o menu com as op��es de quando o cliente entrar*/
        int const ClienteComprarPassagens();                        /*M�todo para executar o menu com as op��es para auxiliar o cliente a comprar passagem*/
        int const ClienteCriacaoDePassagem();                       /*M�todo que aux�lia a cria��o da passagem, com as op��es de destino, origem, etc*/

        int const ClienteEscolhaDeTaxaDeAviao();                    /*Ambos os m�todos, exibem a escolha de tipo de passagem, para ser escolhida*/
        int const ClienteEscolhaDeTaxaDeOnibus();

        int const ClienteOrigem();                                  /*M�todo para exibir as op��es de origem para avi�o e �nibus*/

        int const ClientePassagensRegioes();                        /*M�todos para exibir as regio�es dispon�veis para escolha em ordem alfab�tica
                                                                    (usado apenas para �nibus e abvi�es)*/

        int const ClientePassagensNorte();                          /*Ambos os m�todos desse grupo servem para exibir as cidades em ordem alfab�tica
                                                                    das regi�es escolhidas (Apenas para �nibus e avio�es)*/
        int const ClientePassagensNordeste();
        int const ClientePassagensSul();
        int const ClientePassagensSudeste();
        int const ClientePassagensCentroOeste();

        int const ClientePassagensCruzeiro();                       /*M�todo usado para cria��o da passagem de cruzeiro, ele � usado em conjunto
                                                                    com os m�todos da classe ag�ncia para montar uma passagem de cruzeiro*/
        int const ClientePersonalizeSeuCruzeiro();                  /*M�todo para exibir as eecolhas de personaliza��o de passagens para cruzeiro*/

        int const ClienteEditarCadastro();                          /*M�todo que aux�lia a altera��o de dados do cliente, em cada op��o � executada
                                                                    um m�todo da classe main que vai alterar a vari�vel escolhida pelo usu�rio*/

        int const ClienteInserindoData();                           /*M�todo que exibi as op��es de datas para o cliente poder montar a passagem*/                     
};
