class Menus{

    /*A QUANTIDADE DE COMENTÁRIOS NESSA VERSÃO DO PROJETO, SE DA PELO FARO DE QUE O PROGRAMA FOI CRIADO POR 4 PESSOAS
    E TUDO QUE FOI FEITO, DEVERIA SER EXPLICADO COM DETALHES, PARA AUXILIAR QUEM FOSSE UTILIZAR CADA CLASSE
    ABAIXO VOCÊ ENCONTRA COMO CADA MÉTODO FUNCIONA E ONDE ELE É EXECUTADO NA MAIN. FACILITANDO ASSIM TODAS AS POSSÍVEIS
    ALTERAÇÕES*/

    private:
        /*Vector de controle para a exibição de menus*/
        vector <string> Exibidor;
        vector <string> MensagemAmigavel;
    public:
        /*Método padrão para exibição de menus*/
        int const ExibidorDeMenus();                                /*Sistema para utilização do menu sem cin, para uso de opções do cliente*/

        /*Métodos para uso de menus*/
        int const MenuGeral();

        int const Funcionario();                                    /*Método para executar as opções de entrada do funcionário*/
        /*Cargos de fcunionários*/
        int const FuncionarioPresidente();                          /*Método para executar o menu com as opções do presidente*/

        int const FuncionarioPresidenteRegistroDePassagens();       /*Método para executar o menu com os métodos de impressão
                                                                    do registro de passagens*/

        int const FuncionarioGerente();                             /*Método para executar o menu com as opções de gerente*/
        int const FuncionarioFuncionario();                         /*Método para executar o menu com as opção do funcionário (vendedor)*/
        int const FuncionarioFuncionarioVenderPassagens();          /*Método para executar o menu com as opções de vender passagem
                                                                    cada opção executa um método que mostra a primeira passagem na fila
                                                                    a ser vendidad, para auxilair o funcionário*/

        int const FuncionarioAlteracaoDados();                      /*Método para executar o menu com as opções de alteração de dados
                                                                    de funcionários e gerentes (em cada subopção é executa um método da classe
                                                                    agência dentro da main)*/


        /*Métodos para uso exclusivo do cliente*/
        int const Cliente();                                        /*Métodos para exibir as opções de entrar e cadastrar, se for cadastrar
                                                                    é executado métodos da classe agência na main, se for entrar, os métodos
                                                                    abaixo auxiliam o cliente em sas escolhas*/

        int const ClienteEntrar();                                  /*Método para executar o menu com as opções de quando o cliente entrar*/
        int const ClienteComprarPassagens();                        /*Método para executar o menu com as opções para auxiliar o cliente a comprar passagem*/
        int const ClienteCriacaoDePassagem();                       /*Método que auxília a criação da passagem, com as opções de destino, origem, etc*/

        int const ClienteEscolhaDeTaxaDeAviao();                    /*Ambos os métodos, exibem a escolha de tipo de passagem, para ser escolhida*/
        int const ClienteEscolhaDeTaxaDeOnibus();

        int const ClienteOrigem();                                  /*Método para exibir as opções de origem para avião e ônibus*/

        int const ClientePassagensRegioes();                        /*Métodos para exibir as regioões disponíveis para escolha em ordem alfabética
                                                                    (usado apenas para ônibus e abviões)*/

        int const ClientePassagensNorte();                          /*Ambos os métodos desse grupo servem para exibir as cidades em ordem alfabética
                                                                    das regiões escolhidas (Apenas para ônibus e avioões)*/
        int const ClientePassagensNordeste();
        int const ClientePassagensSul();
        int const ClientePassagensSudeste();
        int const ClientePassagensCentroOeste();

        int const ClientePassagensCruzeiro();                       /*Método usado para criação da passagem de cruzeiro, ele é usado em conjunto
                                                                    com os métodos da classe agência para montar uma passagem de cruzeiro*/
        int const ClientePersonalizeSeuCruzeiro();                  /*Método para exibir as eecolhas de personalização de passagens para cruzeiro*/

        int const ClienteEditarCadastro();                          /*Método que auxília a alteração de dados do cliente, em cada opção é executada
                                                                    um método da classe main que vai alterar a variável escolhida pelo usuário*/

        int const ClienteInserindoData();                           /*Método que exibi as opções de datas para o cliente poder montar a passagem*/                     
};
