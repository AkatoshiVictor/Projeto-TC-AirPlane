#ifndef CRUZEIRO_H
#define CRUZEIRO_H

class Cruzeiro:public Produto{
    private:
        int TaxaFixaDeDistancia;

        int Cabine;
        int PacoteLuaDeMel;

        int Distancia_Cruzeiro;

        int maritimo_Salvador[2]{1747, 2738};//Porto de Santos, porto Rio Grande

    public:
        Cruzeiro(string, string, int, int, int, int, int);

        void set_Cabine(int);
        void set_PacoteLuaDeMel(int);

        int get_Cabine();
        int get_PacoteLuaDeMel();

        void Define_Distancia_Cruzeiro(int, int);
        int Retorna_Distancia_Cruzeiro();

        void Calcula_TempoDeViagemCruzeiro();
        void Calcula_PrecoDaPassagemCruzeio(int);


};

#endif // CRUZEIORO_H
