#ifndef CRUZEIRO_H
#define CRUZEIRO_H

class Cruzeiro:public Produto{
    private:
        int TaxaFixaDeDistancia = 5.00;

        int Cabine;
        int PacoteLuaDeMel;

        int Distancia_Cruzeiro;

        int maritimo_Salvador[2]={9036, 4949};

    public:
        Cruzeiro(int, int, int, int, int, int, int, int, int, int, int, int);

        void set_Cabine(int);
        void set_PacoteLuaDeMel(int);

        int get_Cabine();
        int get_PacoteLuaDeMel();

        void Define_Distancia_Cruzeiro(int, int);
        int Retorna_Distancia_Cruzeiro();

        void Calcula_TempoDeViagemCruzeiro();
        void Calcula_PrecoDaPassagemCruzeio(int);

        void ImprimePassagemCruzeiro();


};

#endif // CRUZEIORO_H
