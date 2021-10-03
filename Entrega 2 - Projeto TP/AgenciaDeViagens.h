#ifndef AGENCIADEVIAGENS_H_INCLUDED
#define AGENCIADEVIAGENS_H_INCLUDED

#include "Usuario.cpp"
#include "Produto.cpp"
#include "Onibus.cpp"
#include "Aviao.cpp"
#include "Cruzeiro.cpp"
#include "Hospedaria.cpp"
#include "GeradorDePassagens.cpp"

class AgenciaDeViagens{
    private:

        vector <Usuario> Funcionario;
        vector <Usuario> Cliente;
        vector <GeradorDePassagens> Passagens;
        vector <Hospedaria> InformacoesHospedaria;

        float Faturamento;
        float Gasto;
        float Lucro;

        string email_atual;
        string senha_atual;
        int posicao_atual;

    public:

        AgenciaDeViagens();

        void set_posicao_atual(int);

        void RelatorioGeral();
        bool LoginFuncionario(int);
        bool LoginCliente();
        bool AutenticadorDeLoginFuncionario(string, string, int);
        bool AutenticadorDeLoginCliente(string, string);
        void CadastraFuncionario();
        void DemiteFuncionario();
        void CadastraCliente();
        bool VerificaDisponibilidadeDeEmailFuncionario(string);
        bool VerificaDisponibilidadeDeEmailCliente(string);
        void ExibirFuncionario();
        void AlterarDadosFuncionario(int);
        void AlterarDadosCliente(int);

        void PassaParaOGeradorDePassagens(int, int, int, int, int, int, int, int, int, int, int, int);

        int RetornaPosicaoParaFuncionario();

        int RetornaPosicaoFuncionario();

        void FuncaoGeradorDePassagem(int);

        void CalculaFaturamento();
        float CalculaSalario(int);
        void CalculaGasto();
        void CalculaLucro();

        float get_Faturamento() const;
        float get_Gasto() const;
        float get_Lucro() const;
        int get_posicao_atual()const;

        int DecodificadorDeDestino(int, int);

        void Define_Destino(int);


        void ProcurarPassagemParaCancelamento();

        void VenderPassagem(int);

        void ImprimaPassagemPendente();

        void ImprimaPassagemVendida();

        void ImprimirPassagensPendentes(int, string);

        void ImprimirPassagensVendidas(int, string);

        ~AgenciaDeViagens();

};


#endif // AGENCIADEVIAGENS_H_INCLUDED
