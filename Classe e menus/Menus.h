class Menus{
    private:
        /*Vector de controle para a exibição de menus*/
        vector <string> Exibidor;
        vector <string> MensagemAmigavel;
    public:
        /*Método padrão para exibição de menus*/
        int const ExibidorDeMenus();

        /*Métodos para uso de menus*/
        int const MenuGeral();

        int const Funcionario();

        int const FuncionarioPresidente();
        int const FuncionarioPresidenteAlteracaoDeTaxas();
        int const FuncionarioPresidenteRegistroDePassagens();

        int const FuncionarioGerente();

        int const FuncionarioFuncionario();
        int const FuncionarioFuncionarioVenderPassagens();

        int const Cliente();
        int const ClienteEntrar();
        int const ClienteCriarCadastro();
        int const ClienteComprarPassagens();
        int const ClientePassagensRegioes();
        int const ClientePassagensNorte();
        int const ClientePassagensNordeste();
        int const ClientePassagensSul();
        int const ClientePassagensSudeste();
        int const ClientePassagensCentroOeste();
        int const ClientePassagensCruzeiro();
        int const ClienteEditarCompras();
        int const ClienteEditarCadastro();
};
