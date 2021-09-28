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
        bool Login(int);
        bool AutenticadorDeLogin(string, string, int);
        void CadastraFuncionario();
        void DemiteFuncionario();
        void CadastraCliente();
        bool VerificaDisponibilidadeDeEmail(string, int);
        void ExibirFuncionario();
        void AlterarDadosFuncionario(int);

        int RetornaPosicaoParaFuncionario(string);

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

        ~AgenciaDeViagens();

};

#endif // AGENCIADEVIAGENS_H_INCLUDED
