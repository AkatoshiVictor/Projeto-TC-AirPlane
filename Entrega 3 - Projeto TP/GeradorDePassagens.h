#ifndef GERADORDEPASSAGENS_H
#define GERADORDEPASSAGENS_H

class GeradorDePassagens{
    private:
        vector<Aviao> PassagensAviao;
        vector<Onibus> PassagensOnibus;
        vector<Cruzeiro> PassagensCruzeiro;

        vector<Aviao> PassagensVendidasAviao;
        vector<Onibus> PassagensVendidasOnibus;
        vector<Cruzeiro> PassagensVendidasCruzeiro;

        int Regiao;
        int Cidade;

    public:

        void AdicionarPassagem(int);
        void VenderPassaegem(int);

        void CancelarPassagem(int);
        void AgendandoPassagemOnibus(Onibus);
        void AgendandoPassagemAviao(Aviao);
        void AgendandoPassagemCruzeiro(Cruzeiro);

        int Retorna_distancia(string, int);

        void ExibirPassagens(string);
     

        void Define_Regiao(int);
        void Define_Cidade(int);

        int Retorna_Regiao();
        int Retorna_Cidade();

        void CancelarPassagem(string);

        void VenderPassagemAviao();
        void VenderPassagemOnibus();
        void VenderPassagemCruzeiro();

        void ImprimirPassagensPendentesAviao(string);
        void ImprimirPassagensPendentesOnbius(string);
        void ImprimirPassagensPendentesCruzeiro(string);

        void ImprimirPassagensVendidasAviao(string);
        void ImprimirPassagensVendidasOnibus(string);
        void ImprimirPassagensVendidasCruzeiro(string);

        void GravadorDePassagens();
        void RecuperadorDePassagens();

        float PassaOFaturamentoTotal();


};

#endif // GERADORDEPASSAGENS_H
