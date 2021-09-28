#ifndef GERADORDEPASSAGENS_H
#define GERADORDEPASSAGENS_H

class GeradorDePassagens{
    private:
        vector<Onibus> PassagensOnibus;
        vector<Aviao> PassagensAviao;
        vector<Cruzeiro> PassagensCruzeiro;

        vector<Onibus> PassagensVendidasOnibus;
        vector<Aviao> PassagensVendidasAviao;
        vector<Cruzeiro> PassagensVendidasCruzeiro;

    public:
        GeradorDePassagens();

        void AdicionarPassagem(int);
        void VenderPassaegem(int);

        void CancelarPassagem(int);
        void AgendandoPassagemOnibus(Onibus);
        void AgendandoPassagemAviao(Aviao);
        void AgendandoPassagemCruzeiro(Cruzeiro);

        int Retorna_distancia(string, int);

        void ExibirPassagens(string);
        void Retornar_passagens();


};

#endif // GERADORDEPASSAGENS_H
