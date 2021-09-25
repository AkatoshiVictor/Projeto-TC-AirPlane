class Menus{
    private:
        /*Vector de controle para a exibi��o de menus*/
        vector <string> Exibidor;
        vector <string> MensagemAmigavel;
    public:
        /*M�todo padr�o para exibi��o de menus*/
        int const ExibidorDeMenus();

        /*M�todos para uso de menus*/
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
